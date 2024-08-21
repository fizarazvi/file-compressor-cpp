#include "../../include/utils/FileUtils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace FileUtils
{

    std::string readFile(const std::string &filePath)
    {
        std::ifstream file(filePath);
        if (!file)
        {
            throw std::runtime_error("Unable to open file for reading: " + filePath);
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    void writeFile(const std::string &filePath, const std::string &content)
    {
        std::ofstream file(filePath);
        if (!file)
        {
            throw std::runtime_error("Unable to open file for writing: " + filePath);
        }
        file << content;
    }

}
