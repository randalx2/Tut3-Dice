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
private: int result;  //integer attribute to store the result of a roll
		 int rolls;   //integer attribute to store the number of rolls

public: Dice()
{                               // Default Constructor to set up dice
			srand(time(NULL)); //seed the randomizer
			result = rand() % 6 + 1;   //The initial result of the dice can be anything between 1 and 6
			rolls = 0;                //initially we have no rolls unless we call the roll method
			cout << "Dice created with " << rolls << " rolls and " << result << " as the result" << endl;
}

		int roll()
		{
			rolls++;                  //Each time this method is called, the value of the number of rolls is incremented
			result = rand() % 6 + 1; // Value of the result is changed randomly once again
			cout << "Result of new roll is " << result << endl;
			cout << "Number of rolls performed is " << rolls << endl;

			return result;
		}    //insert a conditional loop in main program to keep rolling unless a termination character is input

		~Dice()
		{
			//Empty Default Destructor
		}
};



//Defining global overloaded functions prototypes
float average(Dice d, int rolls);        //receives a dice object and the number of rolls
float average(int arr[], int arrinput); // receives an integer array as well as the number of integers for that array

int main()
{
	char userinput = 'x';
	Dice *d1 = new Dice(); // creating a dice object with default constructor

	//Do a roll
	d1->roll();

	system("PAUSE");
	return 0;
}