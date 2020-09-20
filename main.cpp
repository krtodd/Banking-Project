/*
 * main.cpp
 *
 *  Created on: Jul 23, 2020
 *      Author: keri.todd
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;


int main() {
	double initialInvestment, monthlyDeposit, AnnualInterest, numMonths, numYears;
	double totalAmount, monthlyInterest, yearTotalInterest;//variables to store year end total amount, interest, and year end interest


	//Get data from user
	cout << "********************************\n";
	cout << "********** Data Input **********\n";
	cout << "Initial Investment Amount: ";
	cin >> initialInvestment;
	cout << "Monthly Deposit: ";
	cin >> monthlyDeposit;
	cout << "Annual Interest: ";
	cin >> AnnualInterest;
	cout << "Number of years: ";
	cin >> numYears;
	numMonths = numYears * 12;


	totalAmount = initialInvestment;//Set total amount to initial investment to be updated


	//Display year data without monthly deposits
	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";


	for (int i = 0; i < numYears; i++) {

		//Calculate yearly interest
		monthlyInterest = (totalAmount) * ((AnnualInterest / 100));

		//Calculate year end total
		totalAmount = totalAmount + monthlyInterest;

		//Print results to table showcasing only two decimal points
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << monthlyInterest << "\n";

		}

	//Set total amount to initial investment to be updated
	totalAmount = initialInvestment;

	//Display year data with monthly deposits
	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	for (int i = 0; i < numYears; i++) {

	yearTotalInterest = 0;	//Set yearly interest to zero at the start of the year

		for (int j = 0; j < 12; j++) {

			//Calculate monthly interest
			monthlyInterest = (totalAmount + monthlyDeposit) * ((AnnualInterest / 100) / 12);

			//Calculate month end interest
			yearTotalInterest = yearTotalInterest + monthlyInterest;

			//Calculate month end total
			totalAmount = totalAmount + monthlyDeposit + monthlyInterest;

			}

		//Print results to table showcasing only two decimal points
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << yearTotalInterest << "\n";


		}

	return 0;

}




