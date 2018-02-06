// SkynetProject.cpp : Defines the entry point for the console application.
//

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
	int randPredictionCount = 1;
	int numCompletedSearches = 0;
	int targetLocationPredictionCounterL = 0;
	int hGuesses = 0;
	int randGuesses = 0;




	//Print enemy location and some stuff about the program
	cout << "The Missle is on an 8x8 grid with sectors 1-64 find the missle" << endl;
	cout << "US Anti-Missle Protection Program Initializing software... " << endl;

	//define number of predictions
	int targetLocationPredictionCounter = 0;

	// set if the target is found
	bool targetFound = false;


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
		cout << "Enter your guess.";
		cin >> humanLocationPrediction;




			//print the guess number 
			cout << "===========================================================" << endl;
		cout << "US Anti-Missle Protection Program sending out ping #" << targetLocationPredictionCounter << endl;

		//If the guess is higher remove all numbers plus the guessed number and reguess and adds one to the guesses
		if (targetLocationPrediction > enemyLocation) {
			searchGridHighNumber = targetLocationPrediction - 1;
			cout << "The target location predeiction of " << targetLocationPrediction << " was higher then the actual location\n";
			cout << "The program is now searching in areas below  = " << searchGridHighNumber << endl;
		}
		//If the guess is lower remove all numbers plus the guessed number and reguess and adds one to the guesses
		else if (targetLocationPrediction < enemyLocation) {
			searchGridLowNumber = targetLocationPrediction + 1;
			cout << "The target location predeiction of " << targetLocationPrediction << " was lower then the actual location\n";
			cout << "The program is now searching in areas above = " << searchGridLowNumber << endl;
		}
		//if the guess is correct print the location and how many tries it took
		else if (targetLocationPrediction == enemyLocation)
		{
			cout << "US Anti-Missle protection had found the missle " << endl;
			numCompletedSearches++;
		}
		
		









		// create the display method for linear search
		cout << "Linear guess is " << targetLocationPredictionL;
		if (targetLocationPredictionL == enemyLocation) {
			cout << "Linear search algorithm has found the missle at " << targetLocationPredictionL;
				cout << "US Anti-Missle Protection Program took " << targetLocationPredictionCounterL << " tries to find the Missle." << endl;
				numCompletedSearches++;
		}
		else if (targetLocationPredictionL < enemyLocation) {
			cout <<" Linear search algorithm was unable to find the missle, moving on the the next zone" << endl;
			targetLocationPredictionCounterL++;
		}






		//Create random guess display system
		if (randomTargetLocationPrediction > enemyLocation) {
			searchGridHighNumber = randomTargetLocationPrediction - 1;
			cout << "The target location predeiction of " << randomTargetLocationPrediction << " was higher then the actual location" << endl;
			
		}
		//If the guess is lower remove all numbers plus the guessed number and reguess and adds one to the guesses
		else if (randomTargetLocationPrediction < enemyLocation) {
			searchGridLowNumber = randomTargetLocationPrediction + 1;
			cout << "The target location predeiction of " << randomTargetLocationPrediction << " was lower then the actual location" << endl;
			
		}
		//if the guess is correct print the location and how many tries it took
		else if (randomTargetLocationPrediction == enemyLocation)
		{
			cout << "Random guess has found the missle" << endl;
			numCompletedSearches++;
		}


		//create player guess method
		if (humanLocationPrediction > enemyLocation) {
			cout << "guess was too high.";
		}
		else if (humanLocationPrediction < enemyLocation) {
			cout << "guess was too low.";
		}
		else if (humanLocationPrediction == enemyLocation) {
			cout << "human found missle at" << humanLocationPrediction << endl;
			numCompletedSearches++;

		}

		if (numCompletedSearches == 4) {
			targetFound = true;
		}
	}

	system("pause");
	cout << "The Missle was found at zone #" << enemyLocation << endl ; 
	cout << "It took the Anti-Missle protection system took " << targetLocationPredictionCounter << " tries to find the missle. " << endl;
	cout << "It took linear search system " << targetLocationPredictionCounterL << " tries to find the missle. " << endl;
	cout << "It took random guessing system" << randGuesses << " tries to find the missle" << endl;
	cout << "It took Human guesses " << hGuesses << " tries to find the missle" << endl;

	return 0;
}





// it doesnt quite work and I cant figure out whats wrong 
//if you see what I did wrong while grading tell me in the comments for my grade on the assignment
//I am happy to fix it to improve my grade if you can find the issue