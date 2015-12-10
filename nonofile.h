#ifndef __NONOFILE_H__
#define __NONOFILE_H__

#include "nonogram.h"

class NonoFile: public Nonogram
{
public:
    NonoFile(const size_t &width, const size_t &height, const std::vector<std::vector<unsigned char>> &strips);
    NonoFile(const char *filename);
    virtual int load(const char *filename);
//    virtual int save(const char *filename) = 0;
};

#endif // __NONOFILE_H__