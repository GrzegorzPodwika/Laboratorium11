#pragma once
#include <fstream>
#include<exception>
#include <string>


namespace MyRuntimeExceptions {

	class FileOpenException : public std::runtime_error {
	public:

		FileOpenException() : runtime_error("Nie mozna otworzyc pliku") {
		}

		FileOpenException(std::string msg) : runtime_error(msg.c_str()) {
		}
	};

	class FileReadException : public std::runtime_error 
	{
	public:
		FileReadException() : runtime_error("Blad w odczycie danych z pliku")
		{}
	
		FileReadException(std::string msg) : runtime_error(msg.c_str())
		{}
	};
}


/*
* Otwiera plik do odczytu
*
* @param filename nazwa pliku do otwarcia
* @param out referencja na strumieñ wejœcia
*/
void openIFileStream(std::string filename, std::fstream &in);