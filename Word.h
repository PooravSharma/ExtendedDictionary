#ifndef WORD_H
#define WORD_H 

using namespace std;
#include <string>

class Word
{
private: 
	string name;	
	string type;
	string definition;

public:
	Word(string cName, string cType, string cDefinition) {

		name = cName;
		type = cType;
		definition = cDefinition;

	}
	string getWordName() {
		return name;
	}
	string getWordType() {
		return type;
	}
	string getWordDefinition() {
		return definition;
	}



};

#endif// !WORD_H

