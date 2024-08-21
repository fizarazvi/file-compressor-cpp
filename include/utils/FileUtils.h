#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

namespace FileUtils
{
    std::string readFile(const std::string &filePath);
    void writeFile(const std::string &filePath, const std::string &content);
}

#endif
