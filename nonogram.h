#ifndef __NONOGRAM_H__
#define __NONOGRAM_H__

#include <sys/types.h>
#include <vector>

class Nonogram
{
protected:
    unsigned short m_Width;
    unsigned short m_Height;
    std::vector<std::vector<unsigned short>> m_Strips;
public:
    Nonogram();
    Nonogram(const unsigned short &width, const unsigned short &height, const std::vector<std::vector<unsigned short>> &strips);
    std::vector<unsigned short> getRowStrips(unsigned short row) const;
    std::vector<unsigned short> getColStrips(unsigned short col) const;
    unsigned short getWidth() const;
    unsigned short getHeight() const;
    void zero();
};

#endif // __NONOGRAM_H__
