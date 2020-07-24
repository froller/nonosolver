#ifndef __RASTER_H__
#define __RASTER_H__

#include <sys/types.h>
#include <vector>

class Raster
{
protected:
    size_t m_Width;
    size_t m_Height;
    char *m_Raster;
public:
    Raster();
    Raster(const size_t width, const size_t height);
    ~Raster();
    char getPixel(const unsigned int x, const unsigned int y) const;
    void setPixel(const unsigned short x, const unsigned short y, char p);
    std::vector<char> getCol(unsigned int x) const;
    std::vector<char> getRow(unsigned int y) const;
    void clear();
private:
    unsigned int pixelIndex(const unsigned short x, const unsigned short y) const;
};

#endif // __RASTER_H__