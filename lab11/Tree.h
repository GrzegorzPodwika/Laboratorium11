#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <fstream>

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
	TreeElement *lastLeaf;		//wskaznik na ostatni lisc
	unsigned levelOfRoot;		//poziom drzewa liczony od góry


public:

	//konstruktor
	Tree() : root{ nullptr }, lastLeaf{nullptr}, levelOfRoot{}
	{}
	
	Tree(char lett, double numb);

	//destruktor
	~Tree();

	//metody publiczne
	//metody dolaczajace do danego drzewa nastepny lisc
	void push(char lett, double numb, int binCode_0_1);
	void pushLeft(char lett, double numb, int binCode_0_1 = 0);
	void pushRight(char lett, double numb, int binCode_0_1 = 1);

	void pop();																			//metoda wracajaca sie do rodzica ostatniego liscia
	void showWholeTree();																//metoda pomocnicza pokazujaca stanm drzewa w danej chwilii
	int size();																			//metoda zwracajaca rozmiar drzewa liczony od gory

	void setBinaryDigit(int binDigit);
	int getBinaryDigit();

	void setNumber(double numb);
	double getNumber();

	void TreeInorder(TreeElement *rt, int spaceBeetweenNodes, int lvlOfRoot = 0);		//metoda rekurencyjna pomocnicza do pokazywania drzewa na ekran
	TreeElement* getLastLeaf();															//metoda zwracajaca ostatni lisc

	void saveDataToFile(std::fstream &outFile);											//metoda zapisujaca drzewo do pliku
	void TreeInOrderToFile(std::fstream &outFile, TreeElement *rt, int lvlOfRoot = 0);	//metoda rekurencyjna pomocnicza do zapisywania stanu drzewa do pliku
};











#endif // !TREE_H
