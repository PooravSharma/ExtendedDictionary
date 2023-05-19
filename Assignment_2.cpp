// Assignment_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
using namespace std;
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ExtendedDictionary.h"
int main()
{
	ExtendedDictionary dictionary;
	bool loopingMenu = true;
	int inputOption;

	cout << "Hi!! Input the name for the dictionary you want to load." << endl;


	while (loopingMenu) {
		cout << endl << "Enter '1' to search for a word in the dictionary" << endl;
		cout << "Enter '2' to print all the words from the dictonary that contains more than three 'z' letters" << endl;
		cout << "Enter '3' to add a word to the dictionary and save updated dictionary" << endl;
		cout << "Enter '4' to Exit program" << endl;


		cin >> inputOption;
		inputOption = dictionary.inputCheck(inputOption);

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
			//to exit the menu loop and end he program
			loopingMenu = false;
			break;
		}

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
