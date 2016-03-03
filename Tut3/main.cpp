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


public: Dice()
{                               // Default Constructor to set up dice
			srand((unsigned)time(NULL)); //seed the randomizer
			rand();             // call rand function a few times to get a good seed
			rand();
			rand();
			result = 0;       // We won't consider a result unless the dice has been rolled	
}

		Dice(int resnew)   //Overloading constructor
		{
			srand((unsigned)time(NULL));
			rand(); rand(); rand();
			result = resnew;
			//rolls = rollsnew;
		}

		int roll()                        //Method which returns the result of a roll when called.
		{
			result = rand() % 6 + 1;     // Value of the result is changed randomly 
			return result; 			
		}                               //insert a conditional loop in main program to keep rolling unless a termination character is input

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
	int temp = 0;          //temporarily hold the result of the roll here to avoid using the randomizer by calling the roll method
	int rolls = 0;
	int *pointer = NULL;   // initialize array pointer
	char userinput = 'x';   //User input variable to continue or stop program

	Dice *d1 = new Dice();  // creating a dice object with default constructor

	//The user should be able to keep rolling his dice unless he enters a specific character to terminate the game
	while (userinput != 'n')
	{
		cout << "Enter any character EXCEPT 'n' to do a dice roll. Enter 'n' to stop " << endl;
		cin >> userinput;
		rolls++;                  //increment roll counter after every roll
		pointer = new int[rolls]; // set the array dynamically according to number of rolls each time
		                          //dynamically allocated arrays allows an array of increasing size
		                          //Dynamic Memory Allocation allows you to use a variable to specify the array size

		temp = d1->roll();
		*(pointer + (rolls - 1)) = temp; //write the result successively to an array index

	
		/*Attempt to print out the entire array with the recorded values to verify*/

		cout << "Result: " << temp << endl;
		cout << "Rolls: " << rolls << endl;
		cout << "Average: " << average(pointer[rolls], rolls) << endl;
		cout << "Index " << (rolls - 1) << " is " << *(pointer + (rolls - 1)) << endl;
	}

	//Print out array to show recorded values
	/**for (int counter = 0; counter < rolls; counter++)
	{
		cout << "Index " << counter << " is " << *(pointer + counter) << endl;
	}**/
	

	delete pointer;
	delete d1;  //Done using dice object so remove it from memory
	system("PAUSE");
	return 0;
}

float average(Dice d, int rolls)
{
	float ave = 0.00;
	int addresult = 0;

	addresult = addresult + d.roll();
	ave = float(addresult / rolls);

	return ave;	
}

float average(int arr[], int arraylength)
{ 
	float ave = 0.00;
	int addresult = 0;

	for (int counter = 0; counter < arraylength; counter++)
	{
		addresult = addresult + arr[counter];
		ave = float(addresult / arraylength);
	}

	return ave;
}
//

