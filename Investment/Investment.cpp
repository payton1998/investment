/*
 * investment.cpp
 *
 *  Created on: Nov 29, 2020
 *      Author: Payton
 */


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



class Investment{
	//all variables are floats because of the facts that we have to calculate 2 decimal paces
	// within the interest with and withoutn monthly payments
	float initialInvestmentAmount;
	float monthlyDeposit;
	float annualInterest;
	float numberYears;

public:
	//constructor that initially sets all the values to 0.
	Investment(){
		this->initialInvestmentAmount = 0;
				this->monthlyDeposit = 0;
				this->annualInterest = 0;
				this->numberYears = 0;
	}





public:

	//method to display the opening screen where we will get the user input
	void openingScreen(){
						cout << "*************************" << endl;
						cout << "******Data Input*********" << endl;
						cout << "Initial Investment Amount:" << endl;
						cin >> this->initialInvestmentAmount;
						cout << "Monthly Deposit:" << endl;
						cin >> this->monthlyDeposit;
						cout << "Annual Interest:" << endl;
						cin >> this->annualInterest;
						cout << "Number of Years:" << endl;
						cin >> this->numberYears;
						cout << "Press Any Key To Continue..." << endl;

	}

	//This is the method where we actually get the input from the user and set them equal to the local
	//float variables
	void displayInfo(){
		cout << "*************************" << endl;
		cout << "******Data Input*********" << endl;
		cout << "Initial Investment Amount:  $" << this->initialInvestmentAmount << endl;
		cout << "Monthly Deposit:  $" << this->monthlyDeposit << endl;
		cout << "Annual Interest:  %" << this->annualInterest << endl;
		cout << "Number of Years:" << this->numberYears << endl;
		cout << "Press Any Key To Continue..." << endl;


	}



	// This is the method that actually calculates the interest with and without the monthly payments
	void balanceAndInterest(){
		//two float variables to aid in the calculation of the interest without monthly payments
		float earnedInterest;
		float balance = this->initialInvestmentAmount;

		//displays the header
		cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
		cout << "========================================================" << endl;
		cout << "Year     Year End Balance       Year End Earned Interest" << endl;
		cout << "--------------------------------------------------------" << endl;




		//for loop that goes through each year and calculates the interest for the year without
		//monthly payments
		for(int i = 0; i < this->numberYears; i++ ){
			//interest formula
			earnedInterest = (balance)*((this->annualInterest/100));
			balance += earnedInterest;
			//prints calculated values
			cout << i+1 << "          " <<fixed << setprecision(2)<< balance << "            " << earnedInterest<<endl;

		}
		//reset the amount for the balance after the interest without monthly deposits
		//Calculated for the interest with monthly payments
		balance = this->initialInvestmentAmount;
		// one more float variable to help in the calculation of the interest with monthly payments
		float monthlyInterest;

		//Displays the header
		cout << "Balance and Interest With Additional Monthly Deposits" << endl;
		cout << "========================================================" << endl;
		cout << "Year     Year End Balance       Year End Earned Interest" << endl;
		cout << "--------------------------------------------------------" << endl;

		//for loop that goes through every year and calculates the interest with the monthly deposits
		for(int i = 0; i < this->numberYears; i++){
			earnedInterest = 0;
			//nested for loop that goes through every month, calculates the interest for the month
			//and adds each month's to the year's balance
			for(int j = 0; j < 12; j++){
				monthlyInterest = (balance + this->monthlyDeposit) * ((this->annualInterest / 100) / 12);
				earnedInterest += monthlyInterest;
				balance = balance + this->monthlyDeposit + monthlyInterest;
			}

			//prints calculted values
			cout << i+1 << "          " <<fixed << setprecision(2)<< balance << "            " << earnedInterest<<endl;



		}
	}


};

