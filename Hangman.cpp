#include <iostream>
#include <string>
#include <time.h>
using namespace std;
void title();
void head();
void back();
void leftarm();
void rightarm();
void leftleg();
void rightleg();
void gameplay(int wordlength, int fail, 
			  string randomword,string hiddenword,
			  string input, string guess);
void howtoplay();
void winscreen(string a, string b);
void losescreen(string a, string b);
void tryagain();
void wordgen();

int main()
{
select:
	title();
	int option;
	cin >> option;
	switch(option)
	{
	case 1:
		system("cls"); //Clear screen
		wordgen();
		break;

	case 2:
		system("cls"); //Clear screen
		howtoplay();
		break;

	case 3:
		exit(0);
		break;

	default:
		system("cls"); //Clear screen
		goto select;
		break;
	}
	
	system("pause>0");
}


void howtoplay(){
	int goback;
	cout << "Hangman is a word-guessing game where the user " << endl;
	cout << "is given a random word where they have to guess " << endl;
	cout << "it by one character at a time. If you fail each character, " << endl;
	cout << "a hangman is drawn with the chance of it being hanged. " << endl;
	cout << "Guess the word correctly before the hangman gets hanged and you win." << endl;
	cout << endl << "Enter '2' to go back to main menu" << endl;
	cin >> goback;
	if(goback == 2)
	{
		system("cls");
		main();
	}
	else
	{
		system("cls");
		howtoplay();
	}
}

void winscreen(string a, string b)
{
	// String a -> Actual word and String b -> Your guessed word
	cout << "Congratulations! You won! " << endl;
	cout << "The word : " << a << endl;
	cout << "Your guess : " << b << endl;
}

void losescreen(string a, string b)
{
	// String a -> Actual word and String b -> Your guessed word
	rightleg();
	cout << "Sorry you lose! Better luck next time." << endl;
	cout << "The word : " << a << endl;
	cout << "Your guess : " << b << endl;
}

void wordgen()
{
	string guess = ""; // Word user guesses
	string hiddenword = ""; // Hidden word that gets filled by a character if it matches the actual word
	string input; // User inputs one character at a time
	int fail = 0; // No of failed attempts;
	srand(time(NULL)); // Seeds random number based on computer's clock
	int random_number = rand()%30; // A random number which is in between 0-29 range
	string listofwords[30] ={"pakistan","afghanistan","india","china","england","scotland","ireland",
	"australia","newzealand","canada","unitedstates","mexico","spain","portugal","argentina","brazil",
	"france","italy","russia","turkey","greece","saudiarabia","egypt","iran","japan","wales","bangladesh",
	"cuba","southafrica","ukraine"}; // String array that contains 30 words which are country names 
	string randomword = listofwords[random_number]; // The word given by the program that the user guesses
	cout << "Random generated word : " << randomword << endl; // Only for testing
	string hintword; // Hint word 
	int wordlength = randomword.length();
	// Hint word generation 
	int r1 = rand()%wordlength;
	int r2 = rand()%wordlength;
	int r3 = rand()%wordlength;
	int r4 = rand()%wordlength;
	int r5 = rand()%wordlength;
	string randomletter1, randomletter2, 
		randomletter3, randomletter4, randomletter5;
	if(wordlength == 4)
	{
		/*If country name has 4 characters, 
		the hint word will generate with only 3 characters from
		the word and the rest will be hidden by "-"
		*/
		randomletter1 = randomword.substr(r1,1);
		randomletter2 = randomword.substr(r2,1);
		
		
	}
	else if(wordlength == 5)
	{
		/*If country name 5 characters, 
		the hint word will generate with only 3 characters from
		the word and the rest will be hidden by "-"
		*/
		randomletter1 = randomword.substr(r1,1);
		randomletter2 = randomword.substr(r2,1);
		randomletter3 = randomword.substr(r3,1);
		
	}
	else if(wordlength >= 10)
	{
		/*If country name is greater than 10 characters, 
		the hint word will generate with only 5 characters from
		the word and the rest will be hidden by "-"
		*/
		randomletter1 = randomword.substr(r1,1);
		randomletter2 = randomword.substr(r2,1);
		randomletter3 = randomword.substr(r3,1);
		randomletter4 = randomword.substr(r4,1);
		randomletter5 = randomword.substr(r5,1);
	}
	else
	{
		randomletter1 = randomword.substr(r1,1);
		randomletter2 = randomword.substr(r2,1);
		randomletter3 = randomword.substr(r3,1);
		randomletter4 = randomword.substr(r4,1);
	}
	

	//Hidden word generation
	for(int i = 0; i<wordlength; i++)
	{
			hiddenword.insert(i,"-"); // Fills hiddenword with "-"
			hintword.insert(i,"-"); // Fills hintword with "-"
	}

	
		hintword.replace(r1,1,randomletter1);
		hintword.replace(r2,1,randomletter2);
		hintword.replace(r3,1,randomletter3);
		hintword.replace(r4,1,randomletter4);

	cout << "Hint : Country name " << endl;
	cout <<  hintword << endl; // Shows a hint word

	// Calling the game function
	gameplay(wordlength,fail,randomword,hiddenword,input,guess);

}

void gameplay(int wordlength, int fail, 
			  string randomword,string hiddenword,
			  string input, string guess){ 

	while(fail != 6 || randomword == guess)
	{
		
		for(int j = 0; j<wordlength; j++)
		{
			cout << "Word to guess : " << hiddenword << endl;
			cout << "Enter letter to complete the word : " << endl;
			cin >> input;
			guess.insert(j,input);
			

			if(guess[j] == randomword[j])
			{
				hiddenword.replace(j,1,input);
			}
			else 
			{
				fail++;
			}
			
			// If-else statement to check the value of fail
			if(fail == 1)
			{
				head();
				j = 0;
				guess.clear();
				break;
			}
			else if(fail == 2)
			{
				back();
				break;
			
			}
			else if(fail == 3)
			{
				leftarm();
				break;
	
			}
			else if(fail == 4)
			{
				rightarm();
				break;
			}
			else if(fail == 5)
			{
				leftleg();
				break;
			 
			}
			else if(fail == 6)
			{
				rightleg(); 
				break;
			}
			else
			{
				//Nothing to be added here
			}
		
		}
		
		if(guess == randomword)
		{
			goto result; //Result label has a win function and lose function

		}
		else if(fail == 6)
		{
			reverse(guess.begin(),guess.end());
			goto result;   
		}

	}

result:
	system("cls");
	if(guess == randomword)
	{
		winscreen(randomword, guess);
		tryagain();
	}
	else
	{
		losescreen(randomword, guess);
		tryagain();
	}
}

void title(){
	cout << " --------------------------------------------------------------------\n";
	cout << "|                                                                    |\n";
	cout << "|                           HANGMAN GAME                             |\n";
	cout << "|                                                                    |\n";
	cout << "|                     Developed by Hussain Rafi                      |\n";
	cout << "|                                                                    |\n";
	cout << "|                                                                    |\n";
	cout << "|                                                                    |\n";
	cout << " --------------------------------------------------------------------\n";
	cout << "1- Play" << endl;
	cout << "2- How to Play" << endl;
	cout << "3- Exit" << endl;
	cout << "Please enter your option" << endl;
}


void head(){
	cout << " --------------- \n";
	cout << "|              | \n";
	cout << "|              O \n";
	cout << "|               \n";
	cout << "|               \n";
	cout << "|               \n";
	cout << "__\n";
}

void back(){
	cout << " --------------- \n";
	cout << "|              | \n";
	cout << "|              O \n";
	cout << "|              | \n";
	cout << "|               \n";
	cout << "|               \n";
	cout << "__\n";
}

void leftarm(){
	cout << " --------------- \n";
	cout << "|              | \n";
	cout << "|              O \n";
	cout << "|             /| \n";
	cout << "|               \n";
	cout << "|               \n";
	cout << "__\n";
}

void rightarm(){
	cout << " --------------- \n";
	cout << "|              | \n";
	cout << "|              O \n";
	cout << "|             /|\\ \n";
	cout << "|               \n";
	cout << "|               \n";
	cout << "__\n";
}

void leftleg(){
	cout << " --------------- \n";
	cout << "|              | \n";
	cout << "|              O \n";
	cout << "|             /|\\ \n";
	cout << "|             / \n";
	cout << "|               \n";
	cout << "__\n";
}

void rightleg(){
	cout << " --------------- \n";
	cout << "|              | \n";
	cout << "|              O \n";
	cout << "|             /|\\ \n";
	cout << "|             / \\\n";
	cout << "|               \n";
	cout << "__\n";
}


void tryagain(){
	char op;
	cout << "Would you like to play again? Y/n?" << endl;
	cin >> op;
	if(op == 'Y' || op == 'y')
	{
		system("cls");
		wordgen();
	}
	else if(op == 'N' || op == 'n')
	{
		exit(0);
	}
	else
	{
		system("cls");
		tryagain();

	}

}
