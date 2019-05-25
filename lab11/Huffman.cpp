#include "Huffman.h"
using namespace std;

void huffmanAlgorithm(std::fstream & inFile)
{
	char let{};
	double numb{};

	priority_queue <Tree, vector<Tree>, CompareTwoTrees> queue;

	while (!inFile.eof())
	{
		inFile >> let >> numb;

		queue.push(Tree(let, numb));
	}

	show_pq(queue);

	while (queue.size() != 1)
	{

	}
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

