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
#include "Word.h"

class Dictionary
{
protected:
	vector <Word> Dictionary;

public:
	string dictionarynameInput;
	int wordCount;
	bool loadedDictionary = false;

	void fileChoice();

	void TextFileReader(string fileName);

	void searchWord();

	void moreZZZFinder();

	void addWord();

	int inputCheck(int input);

	string capitalRemover(string word);

	string typeConverter(string type);

	string definitionSeperator(string definition);

	void TextFileWriter(string newFileName);

};

#endif

