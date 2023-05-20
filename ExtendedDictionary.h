#ifndef EXTENDEDDICTIONSRY_H
#define EXTENDEDDICTIONSRY_H 
#include "Dictionary.h"
class ExtendedDictionary : public Dictionary
{
private:
	int hightScore = 0;
	int mysterywordLength=0;
	string yellowLetters;
	string greyLetters;
	vector <int> positionNumber;
	string greenLetters;
	int remainingPostion;
	bool parameter;
public:


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

	void cheatatSearchdle() {
		setmysteryLength(0);
		greyLetters = "";
		yellowLetters = "";
		greenLetters ="";
		positionNumber.clear();
		remainingPostion = getmysteryLength();
		parameter = false;
		cout << "Welcome to the Searchdle cheat" << endl;
		bool looping = true;
		int inputOption;
		int inputExit;
		bool exiting = true;

		while (looping) {
			cout << endl << "Note the list of potential words will update as you fill out the parameters below" << endl;
			cout << endl << "Enter '1' to set the number of letters in the ‘mystery’ word" << " (*Length of the Word)" << endl;
			cout << "Enter '2' to enter letters that the 'mystery' word DOES NOT contain" << " (*Note: The GREY letters in the game. It means that the word does not contain the letter in it.)" << endl;
			cout << "Enter '3' to enter letters that the 'mystery' word contain SOMEWHERE" << " (*Note: The YELLOW letters in the game. It means that the word contains the letter in it but it is NOT in the correct position.)" << endl;
			cout << "Enter '4' to enter letters that the 'mystery' word contain in the correct position" << " (*Note: The GREEN letters in the game. It means that the word contains the letter and it IS in the correct position.)" << endl;
			cout << "Enter '5' to list all the words that meet the parameters you entered" << endl;
			cout << "Enter '6' to Exit" << endl;

			int optionLimit = 7;
			inputOption = inputCheck(optionLimit);
			switch (inputOption) {
			case 1:
				setmysteryLength();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:

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

	int gethighScore() {
		return hightScore;
	}
	void sethighScore(int score) {
		hightScore = score;
	}
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

	int randomNumberGenerator() {
		srand(time(NULL));
		int randomNumber = (rand() / double(RAND_MAX)) * wordCount;

		if (randomNumber == wordCount) {
			randomNumber -= 1;
		}

		return randomNumber;
	}

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
				break;
			case 2:
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
			parameter = true;
		}
		
	}
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
			cout << "Enter '1' to Add grey letters" << endl;
			cout << "Enter '2' to clear all Grey letters" << endl;
			cout << "Enter '2' to Exit" << endl;

			int optionLimit = 3;
			int inputOption = inputCheck(optionLimit);
			switch (inputOption) {
			case 1:
				break;
			case 2:
				add = false;
				deleteLetters = true;
				break;
			case 3:
				add = false;
				break;
			}

		}
		if (add == true) {
			bool nooverLaps = true;
			while (true) {
				cout << "What are the grey letter words? (*Note: The letters that are NOT in the mystery word)" << endl;
				cout << "Enter them without spaces. Example: ABCED" << endl;
				newgrayLetter = getLettersOnly();
				newgrayLetter = capitalRemover(newgrayLetter);
				string cleanWord;
				for (char c : newgrayLetter) {
					if (!ispunct(static_cast<unsigned char>(c))) {
						cleanWord += c;
					}
				}
				newgrayLetter = cleanWord;
				nooverLaps = checkLetters(newgrayLetter, yellowLetters);
				nooverLaps = checkLetters(newgrayLetter, greyLetters);
				if (nooverLaps == true) {
					break;
				}
				cout << endl << "The words you inputed already exists in yellowLetters or grey Letters;" << endl;
			}
			greyLetters.append(newgrayLetter);
			parameter = true;
		}
		if (deleteLetters == true) {
			greyLetters = "";
		}


	}
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
			cout << "Enter '1' to Add yellow letters" << endl;
			cout << "Enter '2' to clear all Yellow letters" << endl;
			cout << "Enter '3' to Exit" << endl;

			int optionLimit = 4;
			int inputOption = inputCheck(optionLimit);
			switch (inputOption) {
			case 1:
				break;
			case 2:
				add = false;
				deleteLetters = true;
				break;
			case 3:
				add = false;
				break;
			}

		}
		if (add == true) {
			bool nooverLaps = false;
			while (true) {
				cout << "What are the yellow letter words? (*Note: The letters that are in the mystery word)" << endl;
				cout << "Enter them without spaces. Example: ABCED" << endl;
				newyellowLetter = getLettersOnly();
				newyellowLetter = capitalRemover(newyellowLetter);
				string cleanWord;
				for (char c : newyellowLetter) {
					if (!ispunct(static_cast<unsigned char>(c))) {
						cleanWord += c;
					}
				}

				newyellowLetter = cleanWord;

				nooverLaps = checkLetters(newyellowLetter, yellowLetters);
				nooverLaps = checkLetters(newyellowLetter, greyLetters);
				if (nooverLaps == true) {
					break;
				}
				cout << endl << "The words you inputed already exists in yellow Letters or grey Letters;"<<endl;
			}
			yellowLetters.append(newyellowLetter);
			parameter = true;
		}
		if (deleteLetters == true) {
			yellowLetters = "";
		}
	}
	void getgreenLetters() {
	
		bool add = true;
		bool looping = true;
		bool deleteLetters = false;
		bool samePosition = false;
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
		while (looping == true) {
			cout << "Enter '1' to Add green letters" << endl;
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
					cout << "What position is the green letter in?(*Note: the length of the mystery word is: " << getmysteryLength() << endl;
					cout << "Enter only intergers. Example: '2'" << endl;
					position = getpositionNumber();

					bool exist = false;
					for (auto pos: positionNumber) {
						if (position== pos) {
							samePosition = true;
							break;
						}
						samePosition = false;
					}
					if (samePosition == false) {

						break;
					}
					cout << endl << "The letter you inputed already exists in grey Letters;" << endl;
				}
				bool nooverLaps = false;
				while (true) {
					cout << "What is the green letter words? (*Note: The letters that are in the mystery word and are in the correct position)" << endl;
					cout << "Enter only one letter. Example: 'A'" << endl;
					newgreenLetter = getLetter();

					bool exist = false;
					for (char c : greyLetters) {
						if (c == newgreenLetter) {							
							break;
						}
						nooverLaps = true;
					}
					if (nooverLaps == true) {
						break;
					}
					cout << endl << "The letter you inputed already exists in grey Letters;" << endl;
				}

				positionNumber.push_back(position);


				greenLetters.push_back(newgreenLetter);
				remainingPostion -= 1;
				parameter = true;
				break;
			case 2:			
				deleteLetters = true;
				break;
			case 3:				
				break;
			}

		}		
			
		if (deleteLetters == true) {
			greenLetters = "";
			positionNumber.clear();
		}
	
	
	}
	int getmysteryLength() {
		return mysterywordLength;
	}
	void setmysteryLength(int length) {
		mysterywordLength = length;
	}



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
int getpositionNumber() {

	bool correctInput = false;
	int input;
	while (correctInput == false) {
		if (cin >> input) {
			if (input <= getmysteryLength() && input > 0) {
				correctInput = true;
				break;
			}	
			cout << endl << "Position of the letter need to be more than 0 and less then or equal to the length of the mystery word" << endl;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input the valid number corrosponding to the option you want to choose!!!" << endl << endl;


		}
	}
	return input;
}

void findmysteryWords() {
	string wordName;
	bool greyLetterExist;
	bool yellowLetterExist;
	bool greenLetterExist;
	if (parameter == true) {
		cout << endl << "Potential";
		for (Word word : Dictionary) {
			wordName = word.getWordName();
			if (getmysteryLength() != wordName.length()) {
				continue;
			}
			if (!greyLetters.empty()) {
				greyLetterExist = false;  
				if (checkLetters(wordName, greyLetters) == true) {
					greyLetterExist = true;
					break;
				}
			}
			if (greyLetterExist == true) {
				continue;
			}
			if (!yellowLetters.empty()) {
				yellowLetterExist = true;
				if (checkLetters(wordName, yellowLetters) == false) {
					yellowLetterExist = false;
					break;
				}
			}
			if (yellowLetterExist == false) {
				continue;
			}
			if (!greenLetters.empty() && !positionNumber.empty()) {
				greenLetterExist = true;
				for (char c : wordName) {

					for (char e : greenLetters) {
						if (e == c) {
							greenLetterExist = true;
							break;
						}
					}
					if (greenLetterExist == true) {
						break;
					}
				}
				
			}
			if (greenLetterExist == false) {
				continue;
			}
			cout <<"";
		}
	}
	else {
		cout << "Please input the parameters before searching for words!!!" << endl << endl;
	}

}

};



#endif

