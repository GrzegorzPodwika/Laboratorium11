#include <iostream>
#include "libFiles.h"
#include "Huffman.h"
#include "libExceptions.h"

using namespace std;

int main()
{
	fstream inFile;
	string filenameIn;
	int returnCode = 0;
	char let{};
	double numb{};
	vector <char> letters;
	vector <double> numbers;

	try {
		cout << "Podaj nazwe pliku wejsciowego: " << endl;
		cin >> filenameIn;
		openIFileStream(filenameIn, inFile);

		while (!inFile.eof())
		{
			inFile >> let >> numb;

			if (let < 'A' || let > 'z' || numb < 0)
				throw MyRuntimeExceptions::FileReadException("Blad w odczycie danych z pliku");

			letters.push_back(let);
			numbers.push_back(numb);
		}

		huffmanAlgorithm(letters, numbers);
	}
	catch (const std::exception &e) {
		returnCode = 1;
		cerr << e.what();
	}


	getchar();
	getchar();
	return returnCode;
}