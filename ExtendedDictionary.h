//Created a new class called ExtendedDictionary it will se the functions from its parent class to load and manage the Vector of Words, and perform Assignment 1 functionality
#ifndef EXTENDEDDICTIONSRY_H
#define EXTENDEDDICTIONSRY_H 
#include "Dictionary.h"
#include <unordered_set>
//using inheritance from the Dictionary 
class ExtendedDictionary : public Dictionary
{
private:
	int hightScore = 0;
	int mysterywordLength = 0;
	string yellowLetters;
	string greyLetters;
	vector <int> positionNumber;
	string greenLetters;
	int remainingPostion;
	bool parameter;
public:

	// Task 05 - Palindromes - List all words in the dictionary that are palindromes. e.g .”civic”
	//this function goes through each word and reverses the name. if the reverse name and normal name equls the same it will print the word.
	//it would single letter words too so i changed it so that the minimum word length is more than 2.
	void palindromeFinder() {
		cout << endl << "Finding all the palindrome in the dictionary...." << endl;
		string wordName;
		string reverseWordName;
		for (Word word : Dictionary) {
			wordName = word.getWordName();
			reverseWordName = wordName;
			reverse(reverseWordName.begin(), reverseWordName.end());
			if (wordName.compare(reverseWordName) == 0 && wordName.length() > 1) {

				cout << wordName << endl;

			}

		}


	}
	//Task 06 - Rhyming words – prompt the user to enter a word and print all words from the
	//dictionary that end in the same sequence of three letters as the entered word.
	// the user inputs a word (string). the length of the word need to be atleast 4 long
	// it gets the last three letter of the word and looks through the dictionary to find words with matching last three letters
	// it outputs all the words with the same last three letters 
	void rhymingwordsFinder() {
		string searchedWord;
		string wordName;
		string endofsearchWord;
		string endofWord;
		bool looping = true;
		cout << endl << endl << "Enter a word to find all other words that rhymes with it:" << endl;

		bool  foundWord = true;
		while (looping == true) {
			searchedWord = getLettersOnly();
			searchedWord = capitalRemover(searchedWord);
			if (searchedWord.length() > 3) {
				endofsearchWord = searchedWord.substr(searchedWord.length() - 3);
				for (Word word : Dictionary) {
					wordName = word.getWordName();

					if (wordName.length() > 3) {
						endofWord = wordName.substr(wordName.length() - 3);
						if (endofsearchWord.compare(endofWord) == 0 && searchedWord.compare(wordName) != 0) {
							cout << wordName << endl;
						}


					}

				}
				looping = false;
			}
			else {
				cout << "Please enter a word with at least 4 letters!!!" << endl;
			}

		}


	}
	//Task 07 - Guess the fourth word 
	// randomly picks a word from the dictionary
	// the definition of the word will have its fourth word hidden for the user to guess
	// if the user guesses correctly then they are awarded 10 points. if they guess wrong it is gameover.
	// it outputs score of the user and the hightscore.
	void guessfourthWord() {
		cout << "Welcome to the guess the fourth word" << endl;
		cout << "High Score = " << gethighScore() << endl;
		bool looping = true;
		int inputOption;

		while (looping) {
			cout << endl << "Enter '1' to Play game" << endl;
			cout << "Enter '2' to Exit" << endl;

			int optionLimit = 3;
			inputOption = inputCheck(optionLimit);
			switch (inputOption) {
			case 1:
				guessGame();
				break;
			case 2:

				looping = false;
				break;
			}
		}
	}
	//ask 08 - Cheat at Searchdle
	//the user can set the grey, yellow and green letters. Along with the length of the mystery word
	//the user can choose to show all the potential words the mystery word can be. 
	// it outputs words that are with in the set parameter of the coloured letters. 
	void cheatatSearchdle() {
		setmysteryLength(0);
		greyLetters = "";
		yellowLetters = "";
		greenLetters = "";
		positionNumber.clear();
		remainingPostion = getmysteryLength();
		parameter = false;
		cout << endl << "Welcome to the Searchdle cheat" << endl;
		bool looping = true;
		int inputOption;
		int inputExit;
		bool exiting = true;

		while (looping) {
			cout << endl << endl << "Note the list of potential words will update as you fill out the parameters below" << endl;
			cout << endl << "Enter '1' to set the number of letters in the 'mystery' word" << " (*Length of the Word)" << endl;
			cout << "Enter '2' to enter letters that the 'mystery' word DOES NOT contain" << " (*Note: The GREY letters in the game. It means that the word does not contain the letter in it.)" << endl;
			cout << "Enter '3' to enter letters that the 'mystery' word contain SOMEWHERE" << " (*Note: The YELLOW letters in the game. It means that the word contains the letter in it but it is NOT in the correct position.)" << endl;
			cout << "Enter '4' to enter letters that the 'mystery' word contain in the correct position" << " (*Note: The GREEN letters in the game. It means that the word contains the letter and it IS in the correct position.)" << endl;
			cout << "Enter '5' to list all the words that meet the parameters you entered" << endl;
			cout << "Enter '6' to Clear all parameters" << endl;
			cout << "Enter '7' to Exit" << endl;

			int optionLimit = 8;
			inputOption = inputCheck(optionLimit);
			switch (inputOption) {
			case 1:
				setmysteryLength();
				break;
			case 2:
				getgreyLetters();
				break;
			case 3:
				getyellowLetters();
				break;
			case 4:
				getgreenLetters();
				break;
			case 5:
				findmysteryWords();
				break;
			case 6:
				while (exiting == true) {
					cout << endl << endl << "All the parameters you set will be Cleared. Are you sure you want to continue?" << endl;
					cout << "Enter '1' to say YES" << endl;
					cout << "Enter '2' to say NO" << endl;
					inputExit = inputCheck(3);
					if (inputExit == 1) {
						cheatatSearchdle();
						break;
					}
					if (inputExit == 2) {
						break;
					}
				}
				break;

			case 7:

				while (exiting == true) {
					cout << endl << endl << "All the parameters you set will be lost. Are you sure you want to Exit?" << endl;
					cout << "Enter '1' to say YES" << endl;
					cout << "Enter '2' to say NO" << endl;
					inputExit = inputCheck(3);
					if (inputExit == 1) {
						looping = false;
						break;
					}
					if (inputExit == 2) {
						break;
					}
				}
				break;
			}

		}

	}
	//a get method for high score
	//was no need for it as the variable have no use anywhere else
	//i still wanted to try using method 
	int gethighScore() {
		return hightScore;
	}
	void sethighScore(int score) {
		hightScore = score;
	}

	//the function that is used in the guess the fourth word.
	//this fuction will output a random word and show its definition. the defintion will have its fourth word hidden for the user to guess.
	//some words have more than 1 defintion so it was a little tricky but i made it so that the definition with atleast 4 words will have its word blanked.

	void guessGame() {
		bool guessing = true;
		int score = 0;
		while (guessing == true) {

			int randomNumber = 0;
			randomNumber = randomNumberGenerator();

			Word randomWord = Dictionary[randomNumber];

			string definition = randomWord.getWordDefinition();

			istringstream stream(definition);
			vector <string> definitionVector;
			string word;
			int wordCount = 0;
			int fourthWord = 3;
			bool nofourthWord = true;
			string correctWord;
			while (stream >> word) {
				definitionVector.push_back(word);

			}
			for (auto word : definitionVector) {
				if (!word.empty()) {
					char lastChar = word.back();
					if (lastChar == ';') {

						if (fourthWord > wordCount) {
							fourthWord = wordCount + 4;
						}
						else if (fourthWord <= wordCount) {
							correctWord = definitionVector[fourthWord];
							nofourthWord = false;
							break;
						}
					}
				}
				wordCount++;
			}

			if (wordCount > 3) {
				correctWord = definitionVector[fourthWord];
				nofourthWord = false;
			}

			if (nofourthWord == true) {
				continue;
			}
			//used to get rid of any special characters i.e *, ; ,() stuck to the word
			string cleanWord;
			for (char c : correctWord) {
				if (!ispunct(static_cast<unsigned char>(c))) {
					cleanWord += c;
				}
			}
			correctWord = cleanWord;

			cout << endl << "Guess the blank (_____) word in the definition of the word given." << endl;
			cout << "Correct guess = 10 points!!! GAMEOVER if you guess incorrectly" << endl;
			cout << endl << "Word: " << randomWord.getWordName() << endl;
			cout << "Type: " << typeConverter(randomWord.getWordType()) << endl;
			cout << "Definition: " << endl;

			string wordinDefinition;
			definitionVector[fourthWord] = "______";
			for (auto wordinDefinition : definitionVector) {

				if (!wordinDefinition.empty()) {
					char lastChar = wordinDefinition.back();
					if (lastChar == ';') {
						cout << wordinDefinition << endl << "-";
						continue;
					}
				}
				cout << wordinDefinition << " ";
			}

			string guessWord;
			cout << endl << endl << "Guess Word: ";
			guessWord = getLettersOnly();
			guessWord = capitalRemover(guessWord);
			if (guessWord.compare(correctWord) == 0) {
				cout << endl << "Congratulations!!! You guessed correctly" << endl;
				score += 10;
				cout << "Current Score: " << score << endl;
			}
			else {
				cout << endl << "INCORRECT" << endl;
				cout << endl << "Correct word = " << correctWord << endl;
				break;

			}

		}
		if (gethighScore() < score) {
			cout << endl << "Congratulations!!! You have set a new High Score" << endl;
			sethighScore(score);
			cout << "New High Score: " << gethighScore() << endl;
		}
		else {
			cout << endl << "GAME OVER!!!" << endl;
			cout << "Your Score: " << score << endl;
			cout << "High Score: " << gethighScore() << endl;
		}
	}
	//generates a random word from 0 to the wordcount-1. it is subtracted by one so that when used in vectors it will not go out of bounds.
	int randomNumberGenerator() {
		srand(time(NULL));
		int randomNumber = (rand() / double(RAND_MAX)) * wordCount;

		if (randomNumber == wordCount) {
			randomNumber -= 1;
		}

		return randomNumber;
	}
	//functionn is used to set the length of the mystery word
	void setmysteryLength() {

		bool change = true;
		bool looping = true;
		cout << endl << "Mystery Word Length = " << getmysteryLength() << endl;
		while (looping == true) {
			cout << "Enter '1' to Add/Change mystery word Length" << endl;
			cout << "Enter '2' to Exit" << endl;

			int optionLimit = 3;
			int inputOption = inputCheck(optionLimit);
			switch (inputOption) {
			case 1:
				looping = false;
				break;
			case 2:
				looping = false;
				change = false;
				break;
			}

		}

		if (change == true) {
			cout << "What is the length of the 'mystery' word (*Note: The number of letters that is in the mystery word)" << endl;
			bool correctInput = false;
			int input;
			while (correctInput == false) {
				if (cin >> input) {
					if (input > 0) {
						break;
					}
					cout << endl << "Length of the mystery word need to be more than 0" << endl;
				}
				else {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please input the valid number!!!" << endl << endl;


				}
			}
			setmysteryLength(input);
			remainingPostion = getmysteryLength();
			parameter = true;
		}

	}
	//used to list grey letters as parameter
	void getgreyLetters() {
		bool add = true;
		bool looping = true;
		bool deleteLetters = false;
		string newgrayLetter;
		cout << endl << "Gray letters = (";
		for (char c : greyLetters) {
			cout << c << ", ";
		}
		cout << ")" << endl;
		cout << endl << "Yellow letters = (";
		for (char c : yellowLetters) {
			cout << c << ", ";
		}
		cout << ")" << endl;
		while (looping == true) {
			cout << endl << "Enter '1' to Add grey letters" << endl;
			cout << "Enter '2' to clear all Grey letters" << endl;
			cout << "Enter '3' to Exit" << endl;

			int optionLimit = 4;
			int inputOption = inputCheck(optionLimit);
			switch (inputOption) {
			case 1:
				looping = false;
				break;
			case 2:
				add = false;
				deleteLetters = true;
				looping = false;
				break;
			case 3:
				looping = false;
				add = false;
				break;
			}

		}
		if (add == true) {
			bool nooverLaps = true;
			while (true) {
				cout << endl << "What are the grey letter words? (*Note: The letters that are NOT in the mystery word)" << endl;
				cout << "Enter them without spaces. Example: ABCED" << endl;
				newgrayLetter = getLettersOnly();
				newgrayLetter = capitalRemover(newgrayLetter);
				string cleanWord;
				unordered_set<char> allLetters;
				bool repeatingLetter = false;
				for (char c : newgrayLetter) {
					if (!ispunct(static_cast<unsigned char>(c))) {
						cleanWord += c;
					}
					if (allLetters.count(c) > 0) {
						repeatingLetter = true;
						break;
					}
					allLetters.insert(c);

				}
				if (repeatingLetter == true) {
					cout << endl << "Try again with out repeating letters" << endl;
					continue;
				}
				newgrayLetter = cleanWord;
				nooverLaps = checkLetters(newgrayLetter, yellowLetters);
				nooverLaps = checkLetters(newgrayLetter, greyLetters);
				if (nooverLaps == false) {
					greyLetters.append(newgrayLetter);
					parameter = true;
					break;
				}
				if (nooverLaps == true) {
					cout << endl << "The words you inputed already exists in yellow Letters or grey Letters" << endl;
					break;
				}

			}

		}
		if (deleteLetters == true) {
			cout << endl << "All Grey letters cleared" << endl;
			greyLetters = "";
		}


	}
	//used to list yellow letters as parameter
	void getyellowLetters() {
		bool add = true;
		bool looping = true;
		bool deleteLetters = false;
		string newyellowLetter;
		cout << endl << "Yellow letters = (";
		for (char c : yellowLetters) {
			cout << c << ", ";
		}
		cout << ")" << endl;
		cout << endl << "Gray letters = (";
		for (char c : greyLetters) {
			cout << c << ", ";
		}
		cout << ")" << endl;
		while (looping == true) {
			cout << endl << "Enter '1' to Add yellow letters" << endl;
			cout << "Enter '2' to clear all Yellow letters" << endl;
			cout << "Enter '3' to Exit" << endl;

			int optionLimit = 4;
			int inputOption = inputCheck(optionLimit);
			switch (inputOption) {
			case 1:
				looping = false;
				break;
			case 2:
				looping = false;
				add = false;
				deleteLetters = true;
				break;
			case 3:
				looping = false;
				add = false;
				break;
			}

		}
		if (add == true) {
			bool nooverLaps = false;
			while (true) {
				cout << endl << "What are the yellow letter words? (*Note: The letters that are in the mystery word)" << endl;
				cout << "Enter them without spaces. Example: ABCED" << endl;
				newyellowLetter = getLettersOnly();
				newyellowLetter = capitalRemover(newyellowLetter);
				string cleanWord;
				unordered_set<char> allLetters;
				bool repeatingLetter = false;
				for (char c : newyellowLetter) {
					if (!ispunct(static_cast<unsigned char>(c))) {
						cleanWord += c;
					}
					if (allLetters.count(c) > 0) {
						repeatingLetter = true;
						break;
					}
					allLetters.insert(c);

				}
				if (repeatingLetter == true) {
					cout << endl << "Try again with out repeating letters" << endl;
					continue;
				}

				newyellowLetter = cleanWord;

				nooverLaps = checkLetters(newyellowLetter, yellowLetters);
				nooverLaps = checkLetters(newyellowLetter, greyLetters);
				if (nooverLaps == false) {
					yellowLetters.append(newyellowLetter);
					parameter = true;
					break;
				}
				if (nooverLaps == true) {
					cout << endl << "The words you inputed already exists in yellow Letters or grey Letters" << endl;
					break;
				}

			}

		}
		if (deleteLetters == true) {
			cout << endl << "All Yellow letters cleared" << endl;
			yellowLetters = "";
		}
	}
	//used to list green letters as parameter
	void getgreenLetters() {

		bool add = true;
		bool looping = true;
		bool deleteLetters = false;
		bool samePosition = false;
		bool nooverLaps = false;
		char newgreenLetter;
		int position;
		cout << endl << "Mystery Word Length = " << getmysteryLength() << endl;
		cout << endl << "Yellow letters = (";
		for (char c : yellowLetters) {
			cout << c << ", ";
		}
		cout << ")" << endl;
		cout << endl << "Gray letters = (";
		for (char c : greyLetters) {
			cout << c << ", ";
		}
		cout << ")" << endl;
		cout << endl << "Green letters:" << endl << "Letter" << "    " << "Position" << endl;
		for (int i = 0; i < positionNumber.size(); i++) {
			int positionLetter = positionNumber[i];
			char letter = greenLetters[i];

			cout << "-" << letter << "           -" << positionLetter << endl;
		}
		while (looping == true) {
			cout << endl << "Enter '1' to Add green letters" << endl;
			cout << "Enter '2' to clear all green letters" << endl;
			cout << "Enter '3' to Exit" << endl;

			int optionLimit = 4;
			int inputOption = inputCheck(optionLimit);
			switch (inputOption) {
			case 1:
				if (getmysteryLength() <= 0) {
					cout << endl << "Exit and set the mystery word length correct before you proceed" << endl;
					break;
				}
				if (remainingPostion == 0) {
					cout << endl << "All positions are occupied." << endl;
					break;
				}

				while (true) {
					cout << endl << "What position is the green letter in?(*Note: the length of the mystery word is: " << getmysteryLength() << ")" << endl;
					cout << "Enter only intergers. Example: '2'" << endl;
					position = getpositionNumber();

					bool exist = false;
					for (auto pos : positionNumber) {
						if (position == pos) {
							samePosition = true;
							break;
						}
						samePosition = false;
					}
					if (samePosition == false) {

						break;
					}
					if (samePosition == true) {
						cout << endl << "That position already has a letter assigned" << endl;
						break;
					}

				}
				if (samePosition == true) {
					break;
				}
				nooverLaps = false;
				while (true) {
					cout << endl << "What is the green letter words? (*Note: The letters that are in the mystery word and are in the correct position)" << endl;
					cout << "Enter only one letter. Example: 'A'" << endl;
					newgreenLetter = getLetter();

					for (char c : greyLetters) {
						if (c == newgreenLetter) {
							nooverLaps = false;
							break;
						}
						nooverLaps = true;
					}
					if (nooverLaps == true) {
						positionNumber.push_back(position);


						greenLetters.push_back(newgreenLetter);
						remainingPostion -= 1;
						parameter = true;
						looping = false;
						break;
					}
					if (nooverLaps == false) {
						cout << endl << "The letter you inputed already exists in grey Letters" << endl;
						break;
					}

				}


				break;
			case 2:
				looping = false;
				deleteLetters = true;
				break;
			case 3:
				looping = false;
				break;
			}

		}

		if (deleteLetters == true) {
			cout << endl << "All Green letters cleared" << endl;
			greenLetters = "";
			positionNumber.clear();
		}


	}
	//use to get and set the length of the myster word's length 
	int getmysteryLength() {
		return mysterywordLength;
	}
	void setmysteryLength(int length) {
		mysterywordLength = length;
	}


	//checks whether or not the strings have similar letters
	//it returns true if does have similar letter in the two words
	//it reurns false of no letter are same in the two words
	bool checkLetters(string inputString, string existingString) {

		bool exist = false;
		for (char c : inputString) {

			for (char e : existingString) {
				if (e == c) {
					exist = true;
					break;
				}
			}
			if (exist == true) {
				break;
			}
		}
		return exist;
	}

	// askes input for one char letter 
	char getLetter() {
		char letter;
		while (true) {
			cin >> letter;
			letter = tolower(letter);
			if (letter >= 'a' && letter <= 'z') {
				break;
			}
			else {
				cout << endl << "Invalid input!!! Enter a vaild single letter" << endl;
			}
		}
		return letter;

	}
	// askes to input the position of the green word
	int getpositionNumber() {

		bool correctInput = false;
		int input;
		while (correctInput == false) {
			if (cin >> input) {
				if (input <= getmysteryLength() && input > 0) {
					correctInput = true;
					break;
				}
				cout << endl << "Position of the letter need to be more than 0 and less then or equal to the length of the mystery word which is: (" << getmysteryLength() << ")" << endl;
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please input the valid number corrosponding to the option you want to choose!!!" << endl << endl;


			}
		}
		return input;
	}
	//this function is used to search for the word within the parameter set.
	// it will output all the potential myster word that match the parameter.
	void findmysteryWords() {
		string wordName;
		bool greyLetterExist = false;
		bool yellowLetterExist = true;
		bool greenLetterExist = true;
		bool wordFound = false;
		int position;
		char letter;
		if (parameter == true) {
			cout << endl << "Potential mystery words: " << endl;
			for (Word word : Dictionary) {
				wordName = word.getWordName();
				if (getmysteryLength() != wordName.length()) {
					continue;
				}
				if (!greyLetters.empty()) {
					greyLetterExist = checkLetters(wordName, greyLetters);

				}
				if (greyLetterExist == true) {
					continue;
				}
				if (!yellowLetters.empty()) {
					for (char c : yellowLetters) {
						yellowLetterExist = false;
						for (char e : wordName) {
							if (e == c) {
								yellowLetterExist = true;

							}
						}
						if (yellowLetterExist == false) {
							break;
						}
					}

				}
				if (yellowLetterExist == false) {
					continue;
				}
				if (!greenLetters.empty() && !positionNumber.empty()) {

					for (int i = 0; i < positionNumber.size(); i++) {
						greenLetterExist = true;
						position = positionNumber[i] - 1;
						letter = greenLetters[i];
						if (wordName[position] != letter) {
							greenLetterExist = false;
							break;
						}
					}

				}
				if (greenLetterExist == false) {
					continue;
				}

				cout << wordName << endl;
				wordFound = true;
			}
		}
		else {
			cout << "Please input the parameters before searching for words!!!" << endl << endl;
		}
		if (wordFound == false) {
			cout << endl << "No word found that matches the parameters" << endl;
		}

	}

};



#endif

