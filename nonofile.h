#ifndef __NONOFILE_H__
#define __NONOFILE_H__

#include "nonogram.h"
#include <filesystem>

class NonoFile: public Nonogram
{
public:
    NonoFile(const unsigned short width, const unsigned short height, const std::vector<std::vector<unsigned short>> &strips);
    NonoFile(const std::filesystem::path &path);
    virtual int load(const std::filesystem::path &path);
    virtual int save(const std::filesystem::path &path);
};

#endif // __NONOFILE_H__
