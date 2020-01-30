//HK Arial Wargames
//Drone Hunter search program

#include <iostream>
//Helps generate a random number
#include <cstdlib>
//Time function that random is using
#include <ctime>

using namespace std;

int main()
{
	//Seed random number generator
	srand(static_cast<unsigned int>(time(0)));

	//Initialize the simulation value
	int AI_binary_searchGridLowNumber = 1;
	int AI_binary_searchGridHighNumber = 64;
	int human_searchGridLowNumber = 1;
	int human_searchGridHighNumber = 64;

	//Tracks the number of predictions and the current prediction value
	int AI_Binary_Number_of_Predictions = 0;
	int AI_binary_current_location_prediction = 0;
	int human_Number_of_Predictions = 0;
	int human_current_location_prediction = 0;

	//Keep the actual target location the same for everyone!
	//Random number between 1 and 64 to hold the actual target location
	int actualTargetLocation = rand() % 64 + 1;
	
	//Title for simulation
	cout << "\tWelcome to AI Drone Hunter 3000\n\n";
	cout << "\n\nCreating an 8x8 search grid...\n\n";

	//************** Start Human Tries to find the target ******************
	do
	{
		//This is where the Human makes a target location guess
		cout << "\nThe real target location is at a secret location.\n";
		cout << "\nHuman please enter the target location (" << human_searchGridLowNumber << " - " << human_searchGridHighNumber << ") you think the enemy is hiding at: ";
		cin >> human_current_location_prediction;
		human_Number_of_Predictions++;

		if (human_current_location_prediction > actualTargetLocation)
		{
			cout << "The Human target prediction was too high.\n\n";
			human_searchGridHighNumber = human_current_location_prediction - 1;
		}
		else if (human_current_location_prediction < actualTargetLocation)
		{
			cout << "The Human target prediction was too low.\n\n";
			human_searchGridLowNumber = human_current_location_prediction + 1;
		}
		else if (human_current_location_prediction == actualTargetLocation)
		{
			cout << "\nThat's it! The Human got it in " << human_Number_of_Predictions << " guesses!\n";
			cout << "\nDrone engaging target...\n\n";
		}
	} while (human_current_location_prediction != actualTargetLocation);
	//************** End Human Tries to find the target ******************

	//Transition to the next guessing algorithm
	cout << "The Human is finished, to launch the Binary AI ";
	system("Pause");
	
	//************** Start Binary AI Tries to find the target ******************
	do
	{
		//This is where the AI makes a target location guess
		cout << "\nThe real target location is at " << actualTargetLocation << endl;
		cout << "\nThe AI guesses the target is at location  " << AI_binary_current_location_prediction << endl;
		AI_binary_current_location_prediction = ((AI_binary_searchGridHighNumber - AI_binary_searchGridLowNumber) / 2) + AI_binary_searchGridLowNumber;
		++AI_Binary_Number_of_Predictions;

		if (AI_binary_current_location_prediction > actualTargetLocation)
		{
			cout << "The AI target prediction was too high.\n\n";
			AI_binary_searchGridHighNumber = AI_binary_current_location_prediction - 1;
		}
		else if (AI_binary_current_location_prediction < actualTargetLocation)
		{
			cout << "The AI target prediction was too low.\n\n";
			AI_binary_searchGridLowNumber = AI_binary_current_location_prediction + 1;
		}
		else if (AI_binary_current_location_prediction == actualTargetLocation)
		{
			cout << "\nThat's it! The AI got it in " << AI_Binary_Number_of_Predictions << " guesses!\n";
			cout << "\nDrone engaging target...\n\n";
		}
	} while (AI_binary_current_location_prediction != actualTargetLocation);
	//************** End Binary AI Tries to find the target ******************


	
	return 0;
}