#include "nonofile.h"
#include <stdio.h>
#include <stdlib.h>

NonoFile::NonoFile(const unsigned char &width, const unsigned char &height, const std::vector<std::vector<unsigned char>> &strips)
//    : m_Width(width), m_Height(height), m_Strips(strips)
{
    this->m_Width = width;
    this->m_Height = height;
    this->m_Strips = std::move(strips);
}

NonoFile::NonoFile(const char *filename)
{
    load(filename);
}

int NonoFile::load(const char* filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return 1;
    zero();
    char *buffer = static_cast<char *>(malloc(BUFSIZ));
    if (fread(&m_Width, sizeof(m_Width), 1, file) != 1) {
        zero();
        fclose(file);
        return 1;
    }
    if (fread(&m_Height, sizeof(m_Height), 1, file) != 1) {
        zero();
        fclose(file);
        return 1;
    }
    while (!feof(file))
    {
        size_t read = fread(buffer, sizeof(unsigned char), BUFSIZ, file);
        for (size_t i = 0; i < read; ++i) {
            std::vector<unsigned char> strip;
            if (buffer[i])
                strip.push_back(buffer[i]);
            else
                m_Strips.push_back(std::move(strip));
        }
    }
    free(buffer);
    fclose(file);
    return 0;
}
