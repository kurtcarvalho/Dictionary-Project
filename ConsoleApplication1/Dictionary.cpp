#include "stdafx.h"
#include "Dictionary.h"




void Dictionary::loadDictionary() {
	for (size_t idx = 0; idx < thedictionary.size(); idx++) {
		delete thedictionary[idx];
	}
	cout << "Attempting to read text file..." << endl;
	ifstream myfile(filename);
	if (myfile.is_open()) {
		string record;
		string *rec = &record;
		string word = "none";
		string definition = "none";
		string type = "none";
		
		
		while (!myfile.eof())
		{
			
			getline(myfile, *rec);
			// check that the current line is not a comment
			if (!(record.substr(0, 2) == "//"))
			{
				// put the word record into the vector 
				// first line holds the first word
				word = *rec; // using string to int conversion
							 // second line holds the definition
				getline(myfile, *rec);
				definition = *rec;
				// third line holds the position
				getline(myfile, *rec);
				type = *rec;
				// fourth is the blank line
				getline(myfile, *rec);
				

				TotalNumberOfWords = TotalNumberOfWords++;
				if (type == "n") {
					thedictionary.push_back(new Noun(word, definition, type));
				}

				if (type == "v") {
					thedictionary.push_back(new Verb(word, definition, type));
				}

				if (type == "n_and_v") {
					thedictionary.push_back(new NounandVerb(word, definition, type));
				}
				if (type == "adv") {
					thedictionary.push_back(new Adverb(word, definition, type));
				}
				if (type == "adj") {
					thedictionary.push_back(new Adjective(word, definition, type));
				}
				if (type == "misc") {
					thedictionary.push_back(new MiscWord(word, definition, type));
				}
				if (type == "prep") {
					thedictionary.push_back(new Preposition(word, definition, type));
				}
				if (type == "pn") {
					thedictionary.push_back(new ProperNoun(word, definition, type));
				}
				else {
					continue;
				}
			}

		}
		cout << "The Dictionary has Loaded Properly " << endl;
		cout << "There are " << getTotalNumberOfWords() << " Words";
		
		myfile.close();

	}

	else
	{
		cout << "Unable to read file";
	}

}
	


	int Dictionary::getTotalNumberOfWords() {
	return Dictionary::TotalNumberOfWords;
}

//Search for a word specified by user
void Dictionary::findWord() {
	string queryWordname;
	bool found = false;
	// ask for a name and print the Word and Definition
	cout << "\n\n\n\n\n";
	cout << "---- W O R D   Q U E R Y ----\n\n";
	cout << "Enter the Word and press enter:";
	cin >> queryWordname;
	transform(queryWordname.begin(), queryWordname.end(), queryWordname.begin(), std::tolower);
	queryWordname = queryWordname;
	for (int i = 0; i != thedictionary.size(); i++)
	{
		if (thedictionary[i]->getWord().find(queryWordname) != string::npos)
		{

			if (queryWordname.compare(thedictionary[i]->getWord()) == 0)
			{
				found = true;
				// found a matching Word name
				cout << "Match found:" << endl << "---------------------" << endl;
				cout << "Word:  " << thedictionary[i]->getWord() << endl << "Meaning:  " << thedictionary[i]->getDefinition() << endl << "Type:  " << thedictionary[i]->getType() << "\n\n";

			}
		}
		else if (found = false) {
			cout << "/n word not found /n";
		}

	}
}

//Find words with 3 z's
void Dictionary::search() {
	char d;
	char x = 'a';
	cout << "---- Z   W O R D   Q U E R Y ----\n\n";
	cout << "Finding a word(s) with three z's.... \n";
	for (int i = 0; i != thedictionary.size(); i++)
	{
		std::size_t found = thedictionary[i]->getWord().find('z');
		if (found != std::string::npos)
		{
			found = thedictionary[i]->getWord().find('z', found + 1);
			if (found != std::string::npos)
			{
				found = thedictionary[i]->getWord().find('z', found + 2);
				if (found != std::string::npos)
				{
					cout << "Match Found: " << endl;
					cout << "---------------------" << endl << "Word: " << endl;
					cout << thedictionary[i]->getWord() << endl;
					cout << "Wanna know the definition?" << endl << "y for yes, n for no: ";
					while (x != 'y') {

						cin >> d;
						if (d == 'y')
						{
							cout << endl << "Definition: " << thedictionary[i]->getDefinition();
							getOption();
						}
						else
						{
							cout << "Heading back to the menu..." << endl;
							getOption();
						}
					}
				}

			}
		}
	}
}

//find a word with a q and no u following
void Dictionary::QUsearch()
{

	cout << "\n ---- Q U   W O R D   Q U E R Y ----\n\n" << endl;
	cout << "Searching for word(s) with a Q and no following U" << endl;
	for (int i = 0; i != thedictionary.size(); i++)
	{
		std::size_t found = thedictionary[i]->getWord().find('q');
		if (found != std::string::npos)
		{
			found = thedictionary[i]->getWord().find('u', found + 1);
			if (found != std::string::npos)
			{
			}
			else
			{
				cout << "\nMatch Found: " << endl
					<< "------------------" << endl
					<< "Word: " << thedictionary[i]->getWord() << endl;
			}
		}
	}
}

//Find all the palindromes
void Dictionary::findPalindrome() {
	cout << "\n ---- P A L I N D R O M E   S E A R C H ----\n\n";
	cout << "Finding all the Palindromes..." << endl;
	
	for (int i = 0; i != thedictionary.size(); i++)
	{
		bool pali;
		string wordy = thedictionary[i]->getWord();
		pali = thedictionary[i]->isPalindrome();
		if (pali == 1)
		{
			cout << wordy << endl;
		}
		else ;
	}
}

//Print all the NounandVerbs
void Dictionary::isNounandVerb() {
	cout << "\n ---- N O U N    A N D   V E R B   Q U E R Y ----\n\n" << endl;
	cout << "Searching for word(s) that are both a Noun and Verb...." << endl;
	for (int i = 0; i != thedictionary.size(); i++)
	{
		bool N;
		bool V;
		string theword = thedictionary[i]->getWord();
		N = thedictionary[i]->isNoun();
		V = thedictionary[i]->isVerb();
		if (N == 1) {
			if (V == 1) {
				cout << theword << endl;
			}
			else continue;
		}
		else continue;
	}
}

//Guessing Game 
void Dictionary::guessingGame() {
	cout << "\n ---- G U E S S I N G   G A M E ----\n\n" << endl;
	cout << "Guess the Word by Definition!" << endl;
	string guess;
	int num = thedictionary.size();

	int random = rand() % (num)+1; //Random Number
	string answer = thedictionary[random]->getWord();//GEt the Word
	string def = thedictionary[random]->getDefinition(); //Get the definition
	cout << endl
		<< "\nThe Definition is: " << def;
	cout << "\nEnter the Word > ";
	cin >> guess;
	for (int i = 0; i < guess.length(); ++i)
	{
		guess[i] = std::tolower(guess[i]);
	}
	if (guess == answer) {
		cout << "Thats Correct!" << endl;
	}
	else {
		cout << "Sorry thats wrong!" << endl
			<< "Here's a Hint - The first letter is " << answer[0] << endl
			<< "Answer: ";
		cin >> guess;

		for (int i = 0; i < guess.length(); ++i)
		{
			guess[i] = std::tolower(guess[i]);
		}
		if (guess == answer) {
			cout << "Congratulations! - You're a Genius";
		}
		if (guess != answer) {
			cout << "Sorry thats also wrong!" << endl
				<< "To help you out here's the second letter too: " << answer[0] << answer[1] << endl
				<< "Answer: ";
			cin >> guess;

			for (int i = 0; i < guess.length(); ++i)
			{
				guess[i] = std::tolower(guess[i]);
			}
			if (guess == answer) {
				cout << "Congratulations! - You're a Genius";
			}
		}
		if (guess != answer) {
			cout << "Sorry thats no correct! " << endl
				<< "You are out of attempts! \nThe Word Was " << answer << "\nBetter luck next time!" << endl;
		}
		
	}
}



void Dictionary::findAnagrams()
{
	string queryWord;
	cout << "---- A N A G R A M   S E A R C H ---\n\n";
	cout << "Enter a word and press enter:";
	cin >> queryWord;
	//changing search word to lowercase for the search
	transform(queryWord.begin(), queryWord.end(), queryWord.begin(), ::tolower);
																			
	std::sort(queryWord.begin(), queryWord.end());
	//loop through the dictionary
	for (int i = 0; i != thedictionary.size(); i++)
	{
		string theword = thedictionary[i]->getWord();

		sort(theword.begin(), theword.end());

		if (queryWord == theword) {
			cout << thedictionary[i]->getWord() << "\n";
		}

		
		

	}

}
	

Dictionary::~Dictionary()
{
	thedictionary.clear();
}




//Menu for the User
void Dictionary::getOption() {
	while (true) {
		char option;
		cout << "\n\n-------------  M E N U  -------------\n\n"
			<< "Welcome to the dictionary" << endl
			<< "\n\n" << endl
			<< "Please select one of the following Options" << endl
			<< "1. Search a word " << endl
			<< "2. Find the word(s) with more than three z's" << endl
			<< "3. List the words that have a 'q' without a following 'u'" << endl
			<< "4. List All the words that are Nouns and Verbs" << endl
			<< "5. Find all Palindromes" << endl
			<< "6. Guessing Game " << endl
			<< "7. Find Anagrams" << endl
			<< "Enter a Corresponding Number" << endl
			<< ">";
		cin >> option;
		switch (option)
		{
		case '1':
			findWord();
			break;
		case '2':
			search();
			break;
		case '3':
			QUsearch();
			break;
		case '4':
			isNounandVerb();
			break;
		case '5':
			findPalindrome();
			break;
		case '6':
			guessingGame();
			break;
		case '7':
			findAnagrams();
		default:
			cout << "\nInvalid option, try again \n" << endl;
			break;
		}
	}
};
