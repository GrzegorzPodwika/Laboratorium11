#include <iostream>
#include "libFiles.h"
#include "Huffman.h"
using namespace std;

int main()
{
	fstream inFile("in.txt");

	huffmanAlgorithm(inFile);



	getchar();
	getchar();
	return 0;
}