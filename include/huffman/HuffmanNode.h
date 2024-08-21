#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

class HuffmanNode
{
public:
    char character;
    int frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char ch, int freq);
};

struct Compare
{
    bool operator()(HuffmanNode *left, HuffmanNode *right)
    {
        return left->frequency > right->frequency;
    }
};

#endif