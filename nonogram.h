#ifndef __NONOGRAM_H__
#define __NONOGRAM_H__

#include <sys/types.h>
#include <vector>

class Nonogram
{
protected:
    unsigned char m_Width;
    unsigned char m_Height;
    std::vector<std::vector<unsigned char>> m_Strips;
public:
    Nonogram();
    Nonogram(const unsigned char &width, const unsigned char &height, const std::vector<std::vector<unsigned char>> &strips);
    std::vector<unsigned char> getRowStrips(unsigned char row);
    std::vector<unsigned char> getColStrips(unsigned char col);
    unsigned char getWidth();
    unsigned char getHeight();
    void zero();
};

#endif // __NONOGRAM_H__