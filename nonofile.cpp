#include "nonofile.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

NonoFile::NonoFile(const unsigned short width, const unsigned short height, const std::vector<std::vector<unsigned short>> &strips)
//    : m_Width(width), m_Height(height), m_Strips(strips)
{
    this->m_Width = width;
    this->m_Height = height;
    this->m_Strips = std::move(strips);
}

NonoFile::NonoFile(const std::filesystem::path &path)
{
    load(path);
}

int NonoFile::load(const std::filesystem::path &path)
{
    FILE *file = fopen(path.string().c_str(), "rb");
    if (!file)
        return 1;
    zero();
    unsigned short *buffer = static_cast<unsigned short *>(malloc(BUFSIZ));
    if (fread(&m_Width, sizeof(m_Width), 1, file) != 1)
    {
        zero();
        fclose(file);
        return 1;
    }
    if (fread(&m_Height, sizeof(m_Height), 1, file) != 1)
    {
        zero();
        fclose(file);
        return 1;
    }
    std::vector<unsigned short> strip;
    while (!feof(file))
    {
        size_t read = fread(buffer, sizeof(unsigned short), BUFSIZ / sizeof(unsigned short), file);
        if (!read)
        {
            zero();
            fclose(file);
            free(buffer);
            return 1;
        }
        for (size_t i = 0; i < read; ++i) {
            if (buffer[i])
                strip.push_back(buffer[i]);
            else
            {
                m_Strips.push_back(strip);
                strip.clear();
            }
        }
    }
    free(buffer);
    fclose(file);
    return 0;
}

int NonoFile::save (const std::filesystem::path& path)
{
    size_t bufferSize = 2;
    std::for_each(m_Strips.begin(), m_Strips.end(), [&bufferSize](std::vector<unsigned short> strip) {
        bufferSize += strip.size() + 1;
    });
    unsigned short *buffer = static_cast<unsigned short *>(malloc(sizeof(unsigned short) * bufferSize));
    buffer[0] = m_Width;
    buffer[1] = m_Height;
    unsigned short *bufferTop = buffer + 2;
    std::for_each(m_Strips.begin(), m_Strips.end(), [&bufferTop](std::vector<unsigned short> strip) {
        std::for_each(strip.begin(), strip.end(), [&bufferTop](unsigned short v) {
            *(bufferTop++) = v;
        });
        *(bufferTop++) = 0;
    });
    FILE *file = fopen(path.string().c_str(), "wb+");
    if (!file)
        return 1;
    if (fwrite(buffer, sizeof(unsigned short), bufferSize, file) != sizeof(unsigned short) * bufferSize)
    {
        fclose(file);
        free(buffer);
        return 1;
    }
    fclose(file);
    free(buffer);
    return 0;
}
