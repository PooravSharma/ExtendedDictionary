//Created a class called Dictionary.It encapsulates data and functionality related to the dictionary
#ifndef DICTIONSRY_H
#define DICTIONSRY_H 
using namespace std;
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <string>
#include <limits>
#include <algorithm>
//included to use the word objects
#include "Word.h"
//The functions from Assignment 1 are all encapsulated as member functions(aka methods) into the Dictionary class.
class Dictionary
{
	//its under protected so that the child class can access these variables or vector easily
protected:
	//The Dictionary class holds and maintains the STL Vector of Word objects.
	vector <Word> Dictionary;
	int wordCount = 0;
	bool loadedDictionary = false;

public:
	/*The Dictionary class is defined in a file called Dictionary.h and implemented
		in a file called Dictionary.cpp*/
	void fileChoice();
	/*The Dictionary class is responsible for loading the dictionary file using an
		this method below*/
	void TextFileReader(string fileName);

	void searchWord();

	void moreZZZFinder();

	void addWord();

	int inputCheck(int upperLimit);

	string capitalRemover(string word);

	string typeConverter(string type);

	string definitionSeperator(string definition);

	void TextFileWriter(string newFileName);
	// this is a new method i made to make the code run even smoother. 
	// it askes users for input and only accpets letters. it removes any spaces the string might have. it return the input string in the end
	string getLettersOnly();
};

#endif

