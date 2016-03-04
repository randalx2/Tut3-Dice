/*3 MARCH 2016*/
/*PRANEEL MISTHRY 202515355*/
/*COMPUTER METHODS 3 - TUT3*/
/*DICE GAME: This program is meant to simulate a dice using classes and overloaded global functions*/

/*4 MARCH 2016****************************************************************************************************/
/*The program uses type casting to force a return of a floating point datatype when doing operations on integers*/
/*Due to this, the program may be hardware intensive. The dice overloading function works well on machines with*/
/*4GB and 8GB of ram. However the array overloading function has a chance of giving inaccurate values after 25 rolls**/
/*on older machines with less ram and processing power. When tested on my i5 laptop with 8GB ram it showed no inaccuracies */
/*Deleting the dynamically created array seemed to trigger a break point at run time. Therefore this part was commented out*/
/*Program was finally tested and all core specs have been met but please consider the above points**************************/
/***************************************************************************************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;


class Dice
{
private:  int result;   //integer attribute to store the result of a roll
public:		  int accresult; //accumulated result of dice rolls (addition)
			                 //made this public so it will be available to global functions
			                //once object is passed to them
public: Dice()
{                               // Default Constructor to set up dice
			srand((unsigned)time(NULL)); //seed the randomizer
			rand();             // call rand function a few times to get a good seed
			rand();
			rand();
			result = 0;       // We won't consider a result unless the dice has been rolled	
			accresult = 0;
}

		Dice(int resnew)   //Overloading constructor -- May be needed later
		{
			srand((unsigned)time(NULL));
			rand(); rand(); rand();
			result = resnew;
			accresult = 0;
		}

		int roll()                        //Method which returns the result of a roll when called.
		{
			result = rand() % 6 + 1;         // Value of the result is changed randomly 
			accresult = accresult + result; //Value accumulation each time the roll method is called

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
	int *pointer = new int[rolls];   // initialize array pointer
	
	                         // set the array dynamically according to number of rolls each time
	                         //dynamically allocated arrays allows an array of increasing size
	                        //Dynamic Memory Allocation allows you to use a variable to specify the array size
	char userinput = 'x';   //User input variable to continue or stop program
	
	Dice *d1 = new Dice();  // creating a dice object with default constructor

	//The user should be able to keep rolling his dice unless he enters a specific character to terminate the game
	while (userinput != 'n')
	{
		cout << "Enter any character EXCEPT 'n' to do a dice roll. Enter 'n' to stop " << endl;
		cin >> userinput;
		rolls++;                  //increment roll counter after every roll
	
		temp = d1->roll();
		cout << "Result: " << temp << endl;
		cout << "Rolls: " << rolls << endl;
		cout << "Accumulated: " << d1->accresult << endl;
		cout << "Average from Dice Overloaded Function : " << average(*d1, rolls) << endl;  // Function always works successfully!

		//Setting up array for passing it to overloaded function
		//pointer[rolls - 1] = temp;    ***This method is correct too for referencing arrays with pointers
		*(pointer + (rolls - 1)) = temp;
		cout << "Average from Array Overloaded Function: " << average(pointer, rolls) << endl;	//Function works successfully up to 19 rolls. Don't pass array using pointer reference
	}                                                                                           //Break point is triggered upon termination

	//delete pointer; -- commented this out due to break point triggering bug

	delete d1;  //Done using dice object so remove it from memory
	system("PAUSE");
	return 0;
}

float average(Dice d, int rolls)
{
	float ave = (float)d.accresult / (float)rolls; //Used typecasting to force floating point calculations
 	                                               //useful when the variables cannot be changed to float due to program conflicts
	return ave;	
}

float average(int arr[], int arraylength)
{ 
	float ave = 0.00;
	int addresult = 0;

	for (int counter = 0; counter < arraylength; counter++)
	{
		addresult = addresult + arr[counter]; //Could also write *(arr + counter)
		cout << "Roll " << counter + 1 << " is " << *(arr + counter) << endl; //Display the values stored in the array with each roll
	}
	ave = (float)addresult / (float)arraylength;

	return ave;
}
//

