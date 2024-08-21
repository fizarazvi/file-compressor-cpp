#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H

#include "HuffmanNode.h"
#include <unordered_map>
#include <string>

class HuffmanCoding
{
public:
    HuffmanNode *buildHuffmanTree(const std::unordered_map<char, int> &freqMap);
    void generateHuffmanCodes(HuffmanNode *root, const std::string &str, std::unordered_map<char, std::string> &huffmanCode);
    std::string encode(const std::string &text, const std::unordered_map<char, std::string> &huffmanCode);
    std::string decode(HuffmanNode *root, const std::string &encodeStr);

    std::string readFile(const std::string &filePath);
    void writeFile(const std::string &filePath, const std::string &data);
};

#endif