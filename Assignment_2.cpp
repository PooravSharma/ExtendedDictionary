// Assignment_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "ExtendedDictionary.h"

using namespace std;


int main()
{
	ExtendedDictionary dictionary;
	bool loopingMenu = true;
	int inputOption;

	cout << "Hi!! Input the name for the dictionary you want to load." << endl;
	dictionary.fileChoice();

	while (loopingMenu) {
		cout << endl << "Enter '1' to search for a word in the dictionary" << endl;
		cout << "Enter '2' to print all the words from the dictonary that contains more than three 'z' letters" << endl;
		cout << "Enter '3' to add a word to the dictionary and save updated dictionary" << endl;
		cout << "Enter '4' to list all words in the dictionary that are palindromes. e.g .'civic'" << endl;
		cout << "Enter '5' to find all the Rhyming words of the word you enter" << endl;
		cout << "Enter '6' to play Guess the Fourth word of a word's definition" << endl;
		cout << "Enter '7' to Cheat at Searchdle" << endl;
		cout << "Enter '8' to Open different dictionary" << endl;
		cout << "Enter '9' to Exit program" << endl;


		int optionLimit = 10;
		inputOption = dictionary.inputCheck(optionLimit);

		switch (inputOption) {
		case 1:
			//Task 02 method
			dictionary.searchWord();
			break;
		case 2:
			//Task 03 methon 
			dictionary.moreZZZFinder();
			break;
		case 3:
			//Task 04 method
			dictionary.addWord();
			break;
		case 4:
			dictionary.palindromeFinder();
			break;
		case 5:
			dictionary.rhymingwordsFinder();
			break;
		case 6:
			dictionary.guessfourthWord();
			break;
		case 7:
			dictionary.addWord();
			break;
		case 8:
			dictionary.fileChoice();
			break;
		case 9:
			//to exit the menu loop and end he program
			loopingMenu = false;
			break;
		}

	}
}

