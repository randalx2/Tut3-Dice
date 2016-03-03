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
//public:	  int rolls;   //integer attribute to store the number of rolls

public: Dice()
{                               // Default Constructor to set up dice
			srand((unsigned)time(NULL)); //seed the randomizer
			rand(); // call rand function a few times to get a good seed
			rand();
			rand();
			result = 0;       // We won't consider a result unless the dice has been rolled
			//rolls = 0;        //initially we have no rolls unless we call the roll method
			
}

		Dice(int resnew)   //Overloading constructor
		{
			srand(time(NULL));
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
		temp = d1->roll();
		rolls++;
		pointer = new int[rolls]; // set the array dynamically according to number of rolls each time
		                          //dynamically allocated arrays allows an array of increasing size
		                          //Dynamic Memory Allocation allows you to use a variable to specify the array size

		cout << "Result is: " << temp << endl; //Display the result
		cout << "Number of Rolls: " << rolls << endl;
		cout << "Average is " << average(*d1, rolls) << endl;


		//Fill out the array with each index holding the result value of each of the rolls respectively
		for (int counter = 0; counter < rolls; counter++)
		{
			*(pointer + counter) = temp; // assign the next array index value with the value stored in temp			   
			//memory addresses in arrays are left justified so increment by one to get to next value	
		}
		for (int counter = 0; counter < rolls; counter++)
		{
			cout << "Index " << counter << " is " << *(pointer + counter) << endl; //We already filled out the array previously
		}

	}
	

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

//

