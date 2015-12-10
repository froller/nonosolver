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
    char getPixel(const unsigned int x, const unsigned int y);
    void setPixel(const unsigned int x, const unsigned int y, char p);
    std::vector<char> getCol(unsigned int x);
    std::vector<char> getRow(unsigned int y);
private:
    unsigned int pixelIndex(const unsigned int x, const unsigned int y);
};

#endif // __RASTER_H__