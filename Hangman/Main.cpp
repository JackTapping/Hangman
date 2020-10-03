#include <IOstream> //for using cin anc cout
#include <string>  // using this so we have acces to the String object for the words used in the game
#include <conio.h> // using this for _getch()
#include <ctime>  //so we can get a random number 
#include <vector> //using vectors to hold the players guess
 

// played the intro to the user and allows them to pick a difficulty
char Intro() 
{
	
	std::cout << "Hello and Welcome to Hangman" << "\n";
	std::cout << "Pres any key to continue..." << "\n";

	_getch();
	system("cls");
	
	std::cout << "<<<HANGMAN>>>" << "\n";
	std::cout << "Please select your dificulty" << "\n";
	std::cout << "1) Easy"  << "\n";
	std::cout << "2) Medium" << "\n";
	std::cout << "3) Hard" "\n";

	char cDificulty = 0;
	cDificulty = _getch();
	system("cls");
	return cDificulty;

}

void PrintWord(std::string sWord, std::vector<char> vPLayerGuss) 
{

	//this will print out letters or '_'
	for(int i  = 0 ; i < sWord.length() ; i++ )
	{
		// if the user has guessed a letter and it is in the Vetor loop will print out the letter
		if(std::count(vPLayerGuss.begin(), vPLayerGuss.end() , sWord[i]))
		{
			std::cout << sWord[i];
		}
		// if the user has not guessed that letter loop will print out a '_'
		else
		{
			std::cout << "_";
		}
	}
}

int WinCondition(std::string sWord, std::vector<char> vPlayerGuess, int iLives)
{

	//looking to see if the players latest guess is correct 
	bool bCorrect = false;
	for (int i = 0; i < sWord.length(); i++)
	{
		// if the last guess they player made is in the word bCorrect becomes true 
		if ( vPlayerGuess.back() == sWord[i])
		{
			bCorrect = true;
		}
	}

	if (!bCorrect)
	{
		iLives--;
	}

	std::cout << iLives << "\n";
	return iLives;
}


int main()
{


	// creating the arrays that will hold the words for the game
	std::string asEasyWords[3]{"dog", "log", "car"};
	std::string asMediumWords[3]{ "animal", "window", "purple" };
	std::string asHardWords[3]{ "razzberry", "blackjack", "jukebox" };

	// getting a random number between one and 3 to paick a word
	srand(time(NULL));
	int iRandomNumber = rand() % 3;
	

	//number of lives the player will have 
	 int iLives = 5;

	//crearting the vector that will hold the players guess
	std::vector<char> vcPlayersGuesses;

	// plaing the intro and letting the user pick there difficulty 
	char cDificulty = Intro();


	if(cDificulty == '1')
	{
		std::string sHiddenWord = asEasyWords[iRandomNumber];
		
		do
		{
			std::cout << "Guess : " << "\n";
			vcPlayersGuesses.push_back( _getch());
			PrintWord(sHiddenWord, vcPlayersGuesses);
			iLives = WinCondition(sHiddenWord, vcPlayersGuesses, iLives);

		} while (true);

	}
	else if(cDificulty == '2')
	{
		std::string sHiddenWord = asMediumWords[iRandomNumber];

		do
		{
			std::cout << "Guess : " << "\n";
			vcPlayersGuesses.push_back(_getch());
			PrintWord(sHiddenWord, vcPlayersGuesses);
			iLives = WinCondition(sHiddenWord, vcPlayersGuesses, iLives);

		} while (true);
	}
	else if(cDificulty == '3')
	{
		std::string sHiddenWord = asHardWords[iRandomNumber];

		do
		{
			std::cout << "Guess : " << "\n";
			vcPlayersGuesses.push_back(_getch());
			PrintWord(sHiddenWord, vcPlayersGuesses);
			iLives = WinCondition(sHiddenWord, vcPlayersGuesses, iLives);

		} while (true);
	}

	
}