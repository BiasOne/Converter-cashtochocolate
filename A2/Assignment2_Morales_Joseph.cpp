#include <iostream>

using namespace std;

//******************** Class chocCalc contains all the varying functions used to run the program
class chocCalc
{

//******************** Private variables to be accessed by the class
private:
	int userInput;
	int numberOfChocolates;
	int leftOverCoupons;

//******************** Public functions to be accessed by main
public:

	//******************** Constructors with default userInput value
	chocCalc()
	{
		userInput = 0;
	}

	//********************
	chocCalc(int userInput)
	{
		this->userInput = userInput;
	}

	//******************** Gets input from user and stores it as userInput
	int getUserInput()
	{
		cin >> userInput;
		return userInput;
	}

	//******************** This function performs all of the calculations used to determine the number of chocolates
	int chocCalculator()
	{
		//Temp variables that will reinitialize to zero when the user runs the program over
		int tempNumberOfChocolates=0;
		int tempLeftOverCoupons=0;

		//For loop increments the number of chocolates with a 1:1 ratio
		for (int i = 0; i < userInput; i++)
		{
			//Increments tempNumberOfChocolates
			tempNumberOfChocolates++;

			//If statement makes use of the modulo operator to account for chocolates acquired via coupons at a 7:1 retio
			if (tempNumberOfChocolates % 7 == 0) 
			{
				//Increments tempNumberOfChocolates
				tempNumberOfChocolates++;
			}
		}
			//Uses modulo operator to determine left over coupons once the program exits the for loop
			tempLeftOverCoupons = tempNumberOfChocolates % 7;
		
		//Stores the temp variables into the numberOfChocolates and leftOverCoupons
		numberOfChocolates = tempNumberOfChocolates;
		leftOverCoupons = tempLeftOverCoupons;
		
		//Returns numberOfChocolates and leftOverCoupons to be accessed by other functions 
		return numberOfChocolates;
		return leftOverCoupons;
	}

	//******************** Displays numberOfChocolates
	void dispNumberOfChocolates() const
	{
		cout << "You can buy " << numberOfChocolates << " chocolates" << endl;

	}

	//******************** Displays leftOverCoupons
	void dispLeftOverCoupons() const
	{
		cout << "you will have " << leftOverCoupons << " leftover coupons" << endl;
	}
};

//******************** Main class
int main()
{
	//Declares classOBJ to access its functions
	chocCalc chocCalcOBJ;

	//Boolean for whileLoop
	bool buying = true;
	bool quitting = false;
	 	
	//String to quit/continue
	string quitOrCont;

	//***** Keeps the program looping until the user decides to quit
	while (buying)
	{
		//Asks user for input
		cout << "How much would you like to spend on chocolates? ";

		//Calls chocCalc class function getUserInput to get input from user 
		chocCalcOBJ.getUserInput();

		//Calls chocCalc class function chocCalulator to perform arithmetic 
		chocCalcOBJ.chocCalculator();

		//Calls chocCalc class function to display the numberOfChoclates
		chocCalcOBJ.dispNumberOfChocolates();

		//Calls chocCalc class function to display the leftOverCoupons
		chocCalcOBJ.dispLeftOverCoupons();
		
		//***** While loops continues to ask user if they would like to continue if they do not enter "y" or "n"
		while (!quitting)
		{
			//Asks user if they want to quit or continue
			cout << "Would you like to use this program again? (y/n) ";
			cin >> quitOrCont;

			//If statement changes the default boolean value to exit the while loop
			if (quitOrCont == "n" || quitOrCont == "N")
			{
				//boolean values change to exit while loops
				buying = false;
				quitting = true;

				//booleans are returned
				return buying;
				return quitting;
			}
			 //Breaks out of the continue while loop and runs the proram
			else if (quitOrCont == "y" || quitOrCont == "Y")
			{
				break;
			}
		}
	}

	return 0;
	
	};

	

































