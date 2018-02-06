
//Include all libraries needed
#include "stdafx.h"
#include <iostream>
//Random Number Seeding
#include <ctime>
using std::cout;
using std::endl;
using std::cin;
int main()
{	//start randomly generating
	cout << "Generate Random Enemy Location on 8x8 grid..." << endl;
	srand(time(0));

	//define the high and low number and come up with a random location for the missle
	int searchGridHighNumber = 64;
	int searchGridLowNumber = 1;
	int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber;
	int constGridHigh = 64;
	int constGridLow = 1;
	int randPredictionCount = 0;
	int targetLocationPredictionCounterL = 0;
	int hGuesses = 0;
	int numCompletesearches = 0;




	//Print enemy location and some stuff about the program
	cout << "The Missle is on an 8x8 grid with sectors 1-64 find the missle" << endl;
	cout << "US Anti-Missle Protection Program Initializing software... " << endl;

	//define number of predictions
	int targetLocationPredictionCounter = 0;

	// set if the target is found
	bool targetFound = false;
	bool rtargetFound = false;
	bool htargetFound = false;
	bool ltargetFound = false;
	bool stargetFound = false;

	//Run the program while the enemy is not found
	while (targetFound == false)
	{

		//come up with a random guess for the location
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		targetLocationPredictionCounter++;

		//create linear search system
		int one = 1;
		int targetLocationPredictionL = (0 + targetLocationPredictionCounter);

		//create random guess
		int randomTargetLocationPrediction = rand() % constGridHigh + constGridLow;

		//create human guess
		int humanLocationPrediction;
		




		//print the guess number 
		cout << "===========================================================" << endl;
		cout << "US Anti-Missle Protection Program sending out ping #" << targetLocationPredictionCounter << endl;

		if (stargetFound == true) {
			cout << "US anti-missle program has found the number already waiting on the other programs" << endl;
		}
		else {
			//If the guess is higher remove all numbers plus the guessed number and reguess and adds one to the guesses
		if (targetLocationPrediction > enemyLocation) {
			searchGridHighNumber = targetLocationPrediction - 1;
			cout << "The target location predeiction of " << targetLocationPrediction << " was higher then the actual location" << endl;
			cout << "The program is now searching in areas below  = " << searchGridHighNumber << endl;
			numCompletesearches + 1;

		}
		//If the guess is lower remove all numbers plus the guessed number and reguess and adds one to the guesses
		else if (targetLocationPrediction < enemyLocation) {
			searchGridLowNumber = targetLocationPrediction + 1;
			cout << "The target location predeiction of " << targetLocationPrediction << " was lower then the actual location" << endl;
			cout << "The program is now searching in areas above = " << searchGridLowNumber << endl;
			numCompletesearches + 1;
		}
		//if the guess is correct print the location and how many tries it took
		else if (targetLocationPrediction == enemyLocation)
		{
			cout << "US Anti-Missle protection had found the missle " << endl;
			stargetFound = true;
			numCompletesearches + 1;
		}
		}










		// create the display method for linear search
		cout << "Linear guess is " << targetLocationPredictionL;
		
		if (ltargetFound == true) {
			cout << "Linear has found the number already waiting on the other programs" << endl;
		}
		else {
		if (targetLocationPredictionL == enemyLocation) {
			targetLocationPredictionCounterL++;
			cout << "Linear search algorithm has found the missle at " << targetLocationPredictionL;
			cout << "US Anti-Missle Protection Program took " << targetLocationPredictionCounterL << " tries to find the Missle." << endl;
			ltargetFound = true;
		}
		else if (targetLocationPredictionL < enemyLocation) {
			cout << " Linear search algorithm was unable to find the missle, moving on the the next zone" << endl;
			targetLocationPredictionCounterL + 1;
		}
		}





		//Create random guess display system
		if (rtargetFound == true) {
			cout << "Random has found the number already waiting on the other programs";
		}
		else {

		if (randomTargetLocationPrediction > enemyLocation) {
			searchGridHighNumber = randomTargetLocationPrediction - 1;
			cout << "The target location predeiction of " << randomTargetLocationPrediction << " was higher then the actual location" << endl;
			randPredictionCount + 1;
		}
		//If the guess is lower remove all numbers plus the guessed number and reguess and adds one to the guesses
		else if (randomTargetLocationPrediction < enemyLocation) {
			searchGridLowNumber = randomTargetLocationPrediction + 1;
			cout << "The target location predeiction of " << randomTargetLocationPrediction << " was lower then the actual location" << endl;
			randPredictionCount + 1;
		}
		//if the guess is correct print the location and how many tries it took
		else if (randomTargetLocationPrediction == enemyLocation)
		{
			cout << "Random guess has found the missle" << endl;
			randPredictionCount + 1;
			rtargetFound = true;
		}
		}

		//create player guess method
		if (htargetFound == true) {
			cout << "Human has found the number already waiting on the other programs";
		}
		else if (htargetFound == false) {
			cout << "Enter your guess." << endl;
			cin >> humanLocationPrediction;
			hGuesses + 1;

		if (humanLocationPrediction > enemyLocation) {
			cout << "guess was too high." << endl;
			
		}
		else if (humanLocationPrediction < enemyLocation) {
			cout << "guess was too low." << endl;
			
		}
		else if (humanLocationPrediction == enemyLocation) {
			cout << "human found missle at" << humanLocationPrediction << endl;
			htargetFound = true;

		}
		}

		if ((rtargetFound == true) && (htargetFound == true) && (ltargetFound == true) && (stargetFound == true)) {
			cout <<"_______________________________________________________________________________________________________" << endl;
			cout << "The Missle was found at zone #" << enemyLocation << endl;
			cout << "It took the Anti-Missle protection system took " << targetLocationPredictionCounter << " tries to find the missle. " << endl;
			cout << "It took linear search system " << targetLocationPredictionCounterL << " tries to find the missle. " << endl;
			cout << "It took random guessing system" << randPredictionCount << " tries to find the missle" << endl;
			cout << "It took Human guesses " << hGuesses << " tries to find the missle" << endl;
			targetFound = true;
		}
	}

	system("pause");
	return 0;
}
