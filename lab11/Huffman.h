#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include "Tree.h"

/*
Glowna funkcja obliczajaca dla wartosci z pliku inFile konwertujaca na kod binarny dane litery algorytmem Huffmana
@param letters przyslane litery do zakodowania
@param numbers przyslane czestotliwosci/prawdopodobienstwo z jakim nalezy zakodowac litery
*/
void huffmanAlgorithm(std::vector <char> &letters, std::vector <double> &numbers);

/*
Funkcja pomocnicza pokazujaca kolejke na ekran
@priority_queue kolejka priorytetowa z drzewami
*/
void show_pq(std::priority_queue <Tree, std::vector<Tree>, CompareTwoTrees> gq);

/*
Funkcja tworzaca rodzica przyslanych dzieci
@param leftChild lewe dziecko
@param rightChild prawe dziecko
@return rodzic przeslanych dzieci
*/
Tree createParentOfChildren(Tree &leftChild, Tree &rightChild);

#endif // !HUFFMAN_H

