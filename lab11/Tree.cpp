#include "Tree.h"

using namespace std;

Tree::Tree(char lett, double numb)
{
	TreeElement *nElem = new TreeElement;
	nElem->letter = lett;
	nElem->number = numb;
	nElem->zeroOneNumber = -1;

	nElem->leftChild = nullptr;
	nElem->rightChild = nullptr;

	nElem->parent = nullptr;
	root = nElem;
}

Tree::~Tree()
{}

void Tree::pushLeft(Tree & leftChild)
{
	leftChild.setBinaryDigit(0);

	root->leftChild = leftChild.root;
	leftChild.root->parent = root;
}

void Tree::pushRight(Tree & rightChild)
{
	rightChild.setBinaryDigit(1);

	root->rightChild = rightChild.root;
	rightChild.root->parent = root;
}

void Tree::showWholeTree()
{
	TreeInorder(root);
}

void Tree::TreeInorder(TreeElement * rt, int spaceBeetweenNodes, int lvlOfRoot)
{
	if (rt)
	{

		for (int j = 0; j <= spaceBeetweenNodes; j++)
		{
			cout << "\t";
		}

		cout << lvlOfRoot << " litera = " << rt->letter << endl;

		for (int j = 0; j <= spaceBeetweenNodes; j++)
		{
			cout << "\t";
		}

		cout << lvlOfRoot << " liczba = " << rt->number << endl;

		for (int j = 0; j <= spaceBeetweenNodes; j++)
		{
			cout << "\t";
		}

		cout << lvlOfRoot << " binarna cyfra = " << rt->zeroOneNumber << endl<<endl;
		spaceBeetweenNodes--;

		TreeInorder(rt->leftChild, spaceBeetweenNodes, lvlOfRoot + 1);
		TreeInorder(rt->rightChild, spaceBeetweenNodes, lvlOfRoot + 1);
	}
}



void Tree::saveDataToFile(std::fstream &outFile)
{
	TreeInOrderToFile(outFile, root);
}

void Tree::TreeInOrderToFile(std::fstream & outFile, TreeElement * rt, int lvlOfRoot)
{
	if (rt)
	{
		outFile << lvlOfRoot << " litera = " << rt->letter << endl;
		outFile << lvlOfRoot << " liczba = " << rt->number << endl;
		outFile << lvlOfRoot << " binarna cyfra = " << rt->zeroOneNumber << endl << endl;

		TreeInOrderToFile(outFile, rt->leftChild, lvlOfRoot + 1);
		TreeInOrderToFile(outFile, rt->rightChild, lvlOfRoot + 1);
	}
}


void Tree::showHuffmanTree()
{
	huffmanTree(root, "");
}

void Tree::huffmanTree(TreeElement * root, std::string str)
{
	if (!root->leftChild) cout << root->letter << " " << str << endl;
	else
	{
		huffmanTree(root->leftChild, str + "0");
		huffmanTree(root->rightChild, str + "1");
	}
}

void Tree::setBinaryDigit(int binDigit)
{
	root->zeroOneNumber = binDigit;
}

int Tree::getBinaryDigit()
{
	return root->zeroOneNumber;
}

void Tree::setNumber(double numb)
{
	root->number = numb;
}

double Tree::getNumber()
{
	return root->number;
}

