#ifndef __NONOGRAM_H__
#define __NONOGRAM_H__

#include <sys/types.h>
#include <vector>

class Nonogram
{
protected:
    int m_Width;
    int m_Height;
    std::vector<std::vector<unsigned char>> m_Strips;
public:
    Nonogram();
    Nonogram(const int &width, const int &height, const std::vector<std::vector<unsigned char>> &strips);
    std::vector<unsigned char> getRowStrips(unsigned int row) const;
    std::vector<unsigned char> getColStrips(unsigned int col) const;
    int getWidth() const;
    int getHeight() const;
    void zero();
};

#endif // __NONOGRAM_H__