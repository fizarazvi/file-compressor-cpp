#include "../include/huffman/HuffmanCoding.h"
#include "../include/utils/FileUtils.h"
#include <iostream>
#include <unordered_map>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> <decoded_output_file>" << std::endl;
        return 1;
    }
    std::string inputFilePath = argv[1];
    std::string encodedOutputFilePath = argv[2];
    std::string decodedOutputFilePath = argv[3];

    HuffmanCoding huffman;

    std::string text = FileUtils::readFile(inputFilePath);

    std::unordered_map<char, int> freqMap;
    for (char ch : text)
    {
        freqMap[ch]++;
    }

    HuffmanNode *root = huffman.buildHuffmanTree(freqMap);

    std::unordered_map<char, std::string> huffmanCode;
    huffman.generateHuffmanCodes(root, "", huffmanCode);
    std::string encodedText = huffman.encode(text, huffmanCode);

    FileUtils::writeFile(encodedOutputFilePath, encodedText);
    std::cout << "File compressed and saved to: " << encodedOutputFilePath << std::endl;

    std::string decodedText = huffman.decode(root, encodedText);
    FileUtils::writeFile(decodedOutputFilePath, decodedText);
    std::cout << "File decompressed and saved to: " << decodedOutputFilePath << std::endl;

    return 0;
}