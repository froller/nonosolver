#include "nonofile.h"
#include <stdio.h>
#include <stdlib.h>

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
    FILE *file = fopen(path.c_str(), "r");
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
