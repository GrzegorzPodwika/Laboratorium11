#include "libExceptions.h"
#include <iostream>
using namespace std;


void openIFileStream(std::string filename, std::fstream &in) {
	in.open(filename.c_str());
	if (!in.good()) {
		throw MyRuntimeExceptions::FileOpenException("Nie mozna otworzyc pliku wejsciowego");
	}
}