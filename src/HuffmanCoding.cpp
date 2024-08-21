#include "HuffmanCoding.h"
#include <queue>
#include <vector>
#include <fstream>
#include <iostream>

HuffmanNode::HuffmanNode(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}

HuffmanNode *HuffmanCoding::buildHuffmanTree(const std::unordered_map<char, int> &freqMap)
{
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, Compare> minHeap;

    for (const auto &pair : freqMap)
    {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (minHeap.size() != 1)
    {
        HuffmanNode *left = minHeap.top();
        minHeap.pop();
        HuffmanNode *right = minHeap.top();
        minHeap.pop();

        int sum = left->frequency + right->frequency;
        HuffmanNode *newNode = new HuffmanNode('\0', sum);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}

void HuffmanCoding::generateHuffmanCodes(HuffmanNode *root, const std::string &str, std::unordered_map<char, std::string> &huffmanCode)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        huffmanCode[root->character] = str;
    }

    generateHuffmanCodes(root->left, str + "0", huffmanCode);
    generateHuffmanCodes(root->right, str + "1", huffmanCode);
}

std::string HuffmanCoding::encode(const std::string &text, const std::unordered_map<char, std::string> &huffmanCode)
{
    std::string encodedStr = "";
    for (char ch : text)
    {
        encodedStr += huffmanCode.at(ch);
    }
    return encodedStr;
}

std::string HuffmanCoding::decode(HuffmanNode *root, const std::string &encodedStr)
{
    std::string decodedStr = "";
    HuffmanNode *curr = root;
    for (char bit : encodedStr)
    {
        if (bit == '0')
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }

        if (!curr->left && !curr->right)
        {
            decodedStr += curr->character;
            curr = root;
        }
    }
    return decodedStr;
}

std::string HuffmanCoding::readFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file" << filePath << std::endl;
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    file.close();
    return content;
}

void HuffmanCoding::writeFile(const std::string &filePath, const std::string &data)
{
    std::ofstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not write to the file" << filePath << std::endl;
        return;
    }

    file << data;
    file.close();
}