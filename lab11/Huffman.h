#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <fstream>
#include <queue>
#include "Tree.h"

void huffmanAlgorithm(std::fstream &inFile);

void show_pq(std::priority_queue <Tree, std::vector<Tree>, CompareTwoTrees> gq);

#endif // !HUFFMAN_H

