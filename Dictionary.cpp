#include "Dictionary.h"


void  Dictionary::fileChoice() {
	bool looping = true;
	int inputOption;
	string dictionarynameInput;
	bool loadedDictionary = false;
	while (looping) {
		cout << "Enter '1' to open default dictionary" << endl;
		cout << "Enter '2' to open New dictionary" << endl;
		cout << "Enter '3' Exit" << endl;

		cin >> inputOption;
		inputOption = inputCheck(inputOption);
		switch (inputOption) {
		case 1:
			cout << "Loading dictionary....." << endl << endl;
			TextFileReader("dictionary_2023S1.txt");
			break;
		case 2:
			while (loadedDictionary == false) {
				cin >> dictionarynameInput;
				if (dictionarynameInput.length() >= 4 && dictionarynameInput.substr(dictionarynameInput.length() - 4) == ".txt") {
					cout << "Loading dictionary....." << endl << endl;
					TextFileReader(dictionarynameInput);
					loadedDictionary = true;
				}
				// If no dictionary is loaded the task should just print ‘No dictionary loaded’ and return to the menu
				else {
					cout << "No Dictionary loaded" << endl << "Please try again!!!" << endl;

				}
			}

			break;
		case 3:

			looping = false;
			break;
		}
	}
};
int inputCheck(int input) {
	bool correctInput = false;

	while (correctInput == false) {
		if (cin >> input) {
			if (input < 5 && input >0) {
				correctInput = true;
				break;
			}
			else {
				cout << "Please input the correct number corrosponding to the option you want to choose!!!" << endl << endl;
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input the valid number corrosponding to the option you want to choose!!!" << endl << endl;


		}
	}
	return input;
};

void Dictionary::TextFileReader(string fileName) {
	cout << "Wait few seconds" << endl;
	//used try and catch to prevent system error from stopping the program
	try {
		string wordLine;
		ifstream readFile;
		int count = 1;
		string name;
		string type;
		string definition;

		readFile.open(fileName);
		if (readFile.is_open()) {
			while (!readFile.eof()) {

				getline(readFile, wordLine);
				size_t startWord = wordLine.find("<word>");

				if (startWord != string::npos) {

					getline(readFile, wordLine);
					name = wordLine;
					//had to switch the order of the definiton and type element because the definition is printed above the type. 
					getline(readFile, wordLine);
					definition = wordLine;

					getline(readFile, wordLine);
					type = wordLine;

					Word newWord(name, type, definition);

					Dictionary.push_back(newWord);

				}
			}
			//closed the file after use and changes the booles loaded dictionary to true so that the program can continue to the menu 
			readFile.close();
			cout << "Dictionary has been loaded" << endl << endl;
		}

		else {
			cout << "unable to open file" << endl << "Try Again!" << endl;
		}

	}
	catch (exception ex) {
		cout << "Something went wrong!!!" << ex.what() << endl;
	}
};