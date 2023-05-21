//The Word class is defined and implemented in its own file(eg.Word.h) – for
//this assignment there is no requirement for a separate Word.cpp file so I included all implementation of Word in the header(.h) file.

#ifndef WORD_H
#define WORD_H 
//Converted Word struct from Assignment 1 into a Word class.Encapsulated the appropriate
//functionality of a Word into the Word class, including getters, setters, constructor and the
//printDefinition function that prints that words name, type and definition according to the
//output requirements that were given in Assignment 1.
using namespace std;
#include <string>
class Word
{
private:
	string name;
	string type;
	string definition;

public:
	//functionality of a Word into the Word class, including getters, setters, constructor
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
	//printDefinition function that prints that words name, type and definition according to the
//output requirements that were given in Assignment 1.
	void printdefiniton() {
		if (type == "n") {
			type = "[noun]";
		}
		else if (type == "v") {
			type = "[verb]";
		}
		else if (type == "adv") {
			type = "[adverb]";
		}
		else if (type == "adj") {
			type = "[adjective]";
		}
		else if (type == "prep") {
			type = "[preposition]";
		}
		else if (type == "misc") {
			type = "[miscellaneous]";
		}
		else if (type == "pn") {
			type = "[proper noun]";
		}
		else {
			type = "[noun and verb]";
		}

		istringstream iss(definition);
		string meanings;
		string newDefinition;
		while (getline(iss, meanings, ';')) {
			newDefinition += "- " + meanings + "\n";
		}
		cout << "Word Name: " << name << endl;
		cout << "Type: " << type << endl;
		cout << "Definition: " << newDefinition << endl;
	}


};

#endif// !WORD_H

