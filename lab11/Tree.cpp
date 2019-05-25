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
	lastLeaf = root;
}

Tree::~Tree()
{}

void Tree::push(char lett, double numb, int binCode_0_1)
{
	if (root == nullptr)
	{
		TreeElement *nElem = new TreeElement;
		nElem->letter = lett;
		nElem->number = numb;
		nElem->zeroOneNumber = binCode_0_1;

		nElem->leftChild = nullptr;
		nElem->rightChild = nullptr;

		nElem->parent = nullptr;
		root = nElem;
		lastLeaf = root;
	}
	else
	{
		if (root != lastLeaf)
		{
			if (lastLeaf->leftChild == nullptr)
				pushLeft(lett, numb, binCode_0_1);
			else
				pushRight(lett, numb, binCode_0_1);
		}
		else
		{
			if (lastLeaf->leftChild == nullptr)
				pushLeft(lett, numb, binCode_0_1);
			else
				pushRight(lett, numb, binCode_0_1);
		}

	}
}

void Tree::pushLeft(char lett, double numb, int binCode_0_1)
{
	TreeElement *nElem = new TreeElement;
	nElem->letter = lett;
	nElem->number = numb;
	nElem->zeroOneNumber = binCode_0_1;

	nElem->leftChild = nullptr;
	nElem->rightChild = nullptr;

	nElem->parent = lastLeaf;
	lastLeaf->leftChild = nElem;

	lastLeaf = nElem;
	levelOfRoot++;
}

void Tree::pushRight(char lett, double numb, int binCode_0_1)
{
	TreeElement *nElem = new TreeElement;
	nElem->letter = lett;
	nElem->number = numb;
	nElem->zeroOneNumber = binCode_0_1;

	nElem->leftChild = nullptr;
	nElem->rightChild = nullptr;

	nElem->parent = lastLeaf;
	lastLeaf->rightChild = nElem;

	lastLeaf = nElem;
	levelOfRoot++;
}

void Tree::pop()
{
	if (root != nullptr)
	{
		TreeElement *tmp = lastLeaf;
		lastLeaf = tmp->parent;
		//delete tmp;
		levelOfRoot--;
	}
	else
	{
		cout << "Drzewo jest pusta!" << endl;
	}
}

void Tree::showWholeTree()
{
	TreeInorder(root, levelOfRoot);
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

TreeElement * Tree::getLastLeaf()
{
	return lastLeaf;
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


int Tree::size()
{
	return levelOfRoot;
}

void Tree::setBinaryDigit(int binDigit)
{
	lastLeaf->zeroOneNumber = binDigit;
}

int Tree::getBinaryDigit()
{
	return lastLeaf->zeroOneNumber;
}

void Tree::setNumber(double numb)
{
	lastLeaf->number = numb;
}

double Tree::getNumber()
{
	return lastLeaf->number;
}
