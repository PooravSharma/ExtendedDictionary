#include "Dictionary.h"


void  Dictionary::fileChoice() {
	bool looping = true;
	int inputOption;
	string dictionarynameInput;
	loadedDictionary = false;
	while (looping) {
		cout << "Enter '1' to open default dictionary" << endl;
		cout << "Enter '2' to open New dictionary" << endl;
		cout << "Enter '3' Exit" << endl;

		int optionLimit = 4;
		inputOption = inputCheck(optionLimit);
		switch (inputOption) {
		case 1:
			cout << "Loading dictionary....." << endl << endl;
			TextFileReader("dictionary_2023S1.txt");
			looping = false;
			break;
		case 2:
			while (loadedDictionary == false) {
				cin >> dictionarynameInput;
				if (dictionarynameInput.length() >= 4 && dictionarynameInput.substr(dictionarynameInput.length() - 4) == ".txt") {
					cout << "Loading dictionary....." << endl << endl;
					TextFileReader(dictionarynameInput);
					looping = false;
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
int Dictionary::inputCheck(int upperLimit) {
	bool correctInput = false;
	int input;
	while (correctInput == false) {
		if (cin >> input) {
			if (input < upperLimit && input >0) {
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
		int count = 0;
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
					count++;
				}

			}
			//closed the file after use and changes the booles loaded dictionary to true so that the program can continue to the menu 
			readFile.close();
			cout << "Dictionary has been loaded" << endl << endl;
			wordCount = count;
			loadedDictionary = true;
		}

		else {
			cout << "unable to open file" << endl << "Try Again!" << endl;
		}

	}
	catch (exception ex) {
		cout << "Something went wrong!!!" << ex.what() << endl;
	}
};
void Dictionary::searchWord() {
	string searchedWord;

	cout << endl << endl << "What word are your searching for?" << endl;
	cin >> searchedWord;
	// I made a function that lowers all the string letters so that there is no problem due to capital letter when comparing words
	searchedWord = capitalRemover(searchedWord);
	bool  foundWord = false;
	// uded for loop to go through the vector and try and find the word the user wants.
	for (Word word : Dictionary) {
		string wordName = word.getWordName();

		if (wordName.compare(searchedWord) == 0) {
			string wordDefinition = word.getWordDefinition();
			string wordType = word.getWordType();
			// i used two function I created to make sure the displayed type is shown as per the requirement of the second task, 
			string type = typeConverter(wordType);
			// i aslo desided to seperate the definitions becasue if there were multiple for one word. 
			string definition = definitionSeperator(wordDefinition);
			cout << endl << "Search Result: " << endl << "Word: " << wordName << endl << "Type: " << type << endl << "Definitions: " << endl << definition << endl << endl;
			foundWord = true;
			break;
		}

	}
	//If the word is not in the dictionary print ‘word not found.’
	if (foundWord == false) {

		cout << endl << "Word '" << searchedWord << "' cound not be found in the dictionary" << endl << endl;

	}
};
string Dictionary::definitionSeperator(string definition) {
	istringstream iss(definition);
	string meanings;
	string newDefinition;
	while (getline(iss, meanings, ';')) {
		newDefinition += "- " + meanings + "\n";
	}
	return newDefinition;

};
string Dictionary::typeConverter(string type) {
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
	return type;
}
string Dictionary::capitalRemover(string word) {
	string lowerWord;
	for (char w : word) {
		lowerWord += tolower(w);
	}
	return lowerWord;
};
void Dictionary::moreZZZFinder() {
	cout << endl << "Finding words that has more than three 'z'..." << endl;
	// again used the for loop to got throught all the word name and count the number of z it has. I then used a if statement which states that any word with more than three counts of z letter need to be printed 
	// I wamted to used the same function but the function is a return type and it only allows parameter loaded
	for (Word word : Dictionary) {
		int zCounter = 0;
		string wordName = word.getWordName();
		zCounter = count(wordName.begin(), wordName.end(), 'z');
		if (zCounter > 3) {
			cout << endl << wordName << endl;
		}
	}

};

// Task 04 Add a word to the dictionary. Allow the user to enter the name, type and definition of a word. If the word is already in the dictionary, the program should print ‘error: word exists, elevated privileges required to edit existing words’. If the word is not in the dictionary, and providing a valid ‘type’ is entered – create a corresponding Word struct instance and add it to the Dictionary STL vector.
void Dictionary::addWord() {
	// I create new Variable where i can store the users new word. Before continueing on I used a for loop and the comapre method to check if there is already a same word in the dictionary. if there is one then then I inform them and take them back to the menu.
	string newWordName;
	string newWordType;
	string newWordDefinition;
	int typeOptionInput;
	string wordName;

	cout << endl << "What is the name of the word you want to add to the dictionary?" << endl;
	newWordName = getLettersOnly();
	//used the capital remover fucntion to lower the letter so that even if the user used capital letter i doesn't affect the comparing process
	newWordName = capitalRemover(newWordName);
	for (Word word : Dictionary) {
		wordName = word.getWordName();
		if (wordName.compare(newWordName) == 0) {
			cout << "That word already exists in the dictionary!!!" << endl;
			return;
		}
	}
	// I make a multiple choice option using a switch case to insure that i can store the type of the word similar to how the orginal dictionary format
	cout << endl << "What type of word is it?" << endl;
	cout << "Enter '1' for Noun" << endl << "Enter '2' for Verb" << endl << "Enter '3' for Adverb" << endl << "Enter '4' for Adjective" << endl;
	cout << "Enter '5' for Preposition" << endl << "Enter '6' for Miscellaneous" << endl << "Enter '7' for Proper Noun" << endl << "Enter '8' for Noun and Verb" << endl;
	int optionLimit = 9;
	typeOptionInput = inputCheck(optionLimit);


	switch (typeOptionInput) {
	case 1:
		newWordType = "n";
		break;
	case 2:
		newWordType = "v";
		break;
	case 3:
		newWordType = "adv";
		break;
	case 4:
		newWordType = "adj";
		break;
	case 5:
		newWordType = "prep";
		break;
	case 6:
		newWordType = "misc";
		break;
	case 7:
		newWordType = "pn";
		break;
		// I when throughth the dictionary and could not find what noun and verb type are written i decided to just make one up. this will not affect the output later on because is used the else statemnt to show case any noun and verb type letters  
	case 8:
		newWordType = "n_and_v";
		break;

	}
	// askes for definiton of the word. the used can add multiple one as long as they seperate them using a semicolon(';')
	bool definitionRecieved = false;
	cout << "What is the definition of the word?" << endl;
	cout << "(*Note: If there is multiple definition use ';' at the end of each definition to seperate them)" << endl;

	while (definitionRecieved == false) {
		getline(cin, newWordDefinition);
		if (cin.fail() || newWordDefinition.empty()) {
			cin.clear();
			cin.ignore();
			cout << "Input definition again" << endl;
			continue;
		}
		break;
	}
	Word newWord(newWordName, newWordType, newWordDefinition);
	// new word added to the vector
	Dictionary.push_back(newWord);

	string newDictionaryFileName;
	bool correctnewName = false;

	//Following the successful addition of the word, save the Dictionary to a new file(file name specified by the user), in the same format as the original dictionary file(so that it can be read using Task 01).
	cout << endl << "Which file do you want to save the updated Dictionary to?" << endl;
	// used this method to ensure the user names the new file correctily using the correct format at the end
	while (correctnewName == false) {


		cin >> newDictionaryFileName;
		if (newDictionaryFileName.length() >= 4 && newDictionaryFileName.substr(newDictionaryFileName.length() - 4) == ".txt") {
			correctnewName = true;
			TextFileWriter(newDictionaryFileName);
		}
		else {
			cout << endl << "Please provide a valid file name to save the updated Dictionary into." << endl << endl;
		}
	}
};

string Dictionary::getLettersOnly() {
	string nameInput;

	while (true) {
		bool onlyLetter = true;
		getline(cin >> ws, nameInput);
		nameInput.erase(remove_if(nameInput.begin(), nameInput.end(), ::isspace), nameInput.end());
		for (char n : nameInput) {
			if (!isalpha(n) && n != '-') {
				onlyLetter = false;
				break;
			}

		}
		if (onlyLetter == true) {
			break;
		}

		std::cout << "Invalid name!!! Enter Word name with only letters" << std::endl;
	}

	return nameInput;

};
void Dictionary::TextFileWriter(string newFileName) {
	cout << "Wait few seconds..." << endl << "Saving dictionary..." << endl;
	try {
		string wordLine;
		ofstream writeFile;
		int count = wordCount + 1;
		writeFile.open(newFileName);
		if (writeFile.is_open()) {
			// The orginal dictionary text file had this sentence at the beginning along with the number of words it contains. i augusted the word count accordingly and write the sentance into the txt file
			// Attention to detail is key 
			writeFile << "2023 - S1 dictionary contains " << count << " words" << endl << endl;
			for (Word word : Dictionary) {
				writeFile << "<word>" << endl;

				writeFile << word.getWordName() << endl;
				writeFile << word.getWordDefinition() << endl;
				writeFile << word.getWordType() << endl;

				writeFile << "</word>" << endl;
			}
			writeFile.close();
			cout << "Dictionary has been saved" << endl << endl;
		}
		else {
			cout << "unable to open file" << endl << "Try Again!" << endl;
		}

	}
	catch (exception ex) {
		cout << "Something went wrong!!!" << ex.what() << endl;
	}
};
