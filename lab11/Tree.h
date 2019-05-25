#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <fstream>
#include <string>

//Struktura imituj¹ca pojedynczy element drzewa
struct TreeElement
{
	TreeElement *parent;
	TreeElement *leftChild;
	TreeElement *rightChild;

	int zeroOneNumber;
	double number;
	char letter;
};

//klasa imitujaca drzewo skladajaca sie z pojedynczych obiektow struktury TreeElement
class Tree
{
	TreeElement *root;			//wskaznik na korzen

public:

	//konstruktor
	Tree() : root{ nullptr }
	{}

	Tree(char lett, double numb);

	//destruktor
	~Tree();

	//metody publiczne
	//metody dolaczajace do danego drzewa nastepny lisc
	void pushLeft(Tree &leftChild);
	void pushRight(Tree &rightChild);

	void showWholeTree();																//metoda pomocnicza pokazujaca stan drzewa w danej chwilii

	void setBinaryDigit(int binDigit);													//metoda ustanawiajaca liczbe w wezle na 0 lub 1
	int getBinaryDigit();																//metoda zwracajaca liczbe 0 albo 1 z wezla

	void setNumber(double numb);														//metoda ustawiajaca czestostliwosc/prawdopodobienstweo w wezle
	double getNumber();																	//metoda zwracajaca czestostliwosc/prawdopodobienstweo z wezla

	void TreeInorder(TreeElement *rt, int spaceBeetweenNodes = 0, int lvlOfRoot = 0);	//metoda rekurencyjna pomocnicza do pokazywania drzewa na ekran

	void saveDataToFile(std::fstream &outFile);											//metoda zapisujaca drzewo do pliku
	void TreeInOrderToFile(std::fstream &outFile, TreeElement *rt, int lvlOfRoot = 0);	//metoda rekurencyjna pomocnicza do zapisywania stanu drzewa do pliku

	void showHuffmanTree();																//metoda pokazujaca zakodowane litery algorytmem Huffmana
	void huffmanTree(TreeElement *root, std::string str);								//metoda rekursywna pomocnicza do pokazywania liter algorytmu Huffmana
};

//definicja funktora porownujacego dwa drzewa za pomoca wartosci w wezla, np. prawdopodobienstwa
class CompareTwoTrees
{
public:
	bool operator()(Tree &tree_1, Tree &tree_2)
	{
		if (tree_1.getNumber() < tree_2.getNumber())
			return false;

		if (tree_1.getNumber() > tree_2.getNumber())
			return true;
		
		//else tree_1.getNumber() == tree_2.getNumber()
		return false;
	}
};


#endif // !TREE_H
