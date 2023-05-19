#ifndef EXTENDEDDICTIONSRY_H
#define EXTENDEDDICTIONSRY_H 
#include "Dictionary.h"
class ExtendedDictionary : public Dictionary
{
private:
	int hightScore = 0;

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

			if (guessWord.compare(correctWord) == 0) {
				cout <<endl<< "Congratulations!!! You guessed correctly" << endl;
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
};
#endif

