#include "Huffman.h"
using namespace std;

void huffmanAlgorithm(vector <char> &letters, vector <double> &numbers)
{
	priority_queue <Tree, vector<Tree>, CompareTwoTrees> queue;

	for (int i = 0; i < letters.size(); i++)
	{
		queue.push(Tree(letters[i], numbers[i]));
	}

	Tree tmp1{}, tmp2{};

	while (queue.size() != 1)
	{
		tmp1 = queue.top();
		queue.pop();

		tmp2 = queue.top();
		queue.pop();

		queue.push(createParentOfChildren(tmp1, tmp2));
	}

	Tree mainTree = queue.top();

	mainTree.showWholeTree();
	mainTree.showHuffmanTree();
}

void show_pq(priority_queue <Tree, vector<Tree>, CompareTwoTrees> gq)
{
	priority_queue <Tree, vector<Tree>, CompareTwoTrees> g = gq;
	while (!g.empty())
	{
		Tree tmp = g.top();
		tmp.showWholeTree();
		g.pop();
	}
}

Tree createParentOfChildren(Tree &leftChild, Tree &rightChild)
{
	Tree parent('-', leftChild.getNumber()+rightChild.getNumber());

	parent.pushLeft(leftChild);
	parent.pushRight(rightChild);

	return parent;
}



