/*3 MARCH 2016*/
/*PRANEEL MISTHRY 202515355*/
/*COMPUTER METHODS 3 - TUT3*/
/*DICE GAME: This program is meant to simulate a dice using classes and overloaded global functions*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;


class Dice
{
private:  int result;   //integer attribute to store the result of a roll
public:	  int rolls;   //integer attribute to store the number of rolls

public: Dice()
{                               // Default Constructor to set up dice
			srand(time(NULL)); //seed the randomizer
			result = 0;       // We won't consider a result unless the dice has been rolled
			rolls = 0;        //initially we have no rolls unless we call the roll method
			
}

		Dice(int resnew, int rollsnew)   //Overloading constructor
		{
			result = resnew;
			rolls = rollsnew;
		}

		int roll() //Method which return the result of a roll when called. Also increments roll count
		{
			//int resnew = 0, rollsnew = 0; //initialize variables to hold updated values
			rolls++;                     //Each time this method is called, the value of the number of rolls is incremented
			result = rand() % 6 + 1;     // Value of the result is changed randomly 

			return result; 			
		}    //insert a conditional loop in main program to keep rolling unless a termination character is input

		~Dice()
		{
			//Empty Default Destructor
		}
};



//Defining global overloaded functions prototypes
float average(Dice d, int rolls);          //receives a dice object and the number of rolls
float average(int arr[], int arraylength); // receives an integer array as well as the number of integers for that array

int main()
{
	char userinput = 'x';
	Dice *d1 = new Dice(); // creating a dice object with default constructor

	//The user should be able to keep rolling his dice unless he enters a specific character to terminate the game
	while (userinput != 'n')
	{
		cout << "Enter any character EXCEPT 'n' to do a dice roll. Enter 'n' to stop " << endl;
		cin >> userinput;
		cout << "Result is: " << d1->roll() << endl; //Display the result
		cout << "Number of Rolls: " << d1->rolls << endl;
	}

	delete d1;  //Done using dice object so remove it from memory
	system("PAUSE");
	return 0;
}

//

