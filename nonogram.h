#ifndef __NONOGRAM_H__
#define __NONOGRAM_H__

#include <sys/types.h>
#include <vector>

class Nonogram
{
protected:
    size_t m_Width;
    size_t m_Height;
    std::vector<std::vector<unsigned char>> m_Strips;
public:
    Nonogram();
    Nonogram(const size_t &width, const size_t &height, const std::vector<std::vector<unsigned char>> &strips);
    std::vector<unsigned char> getRowStrips(unsigned int row);
    std::vector<unsigned char> getColStrips(unsigned int col);
    size_t getWidth();
    size_t getHeight();
    void zero();
};

#endif // __NONOGRAM_H__