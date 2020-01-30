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
	//For holding data on low and high numbers which may change
	int human_searchGridLowNumber = 1;
	int human_searchGridHighNumber = 64;
	int AI_binary_searchGridLowNumber = 1;
	int AI_binary_searchGridHighNumber = 64;
	int AI_linear_searchGridLowNumber = 1;
	int AI_linear_searchGridHighNumber = 64;
	int AI_random_searchGridLowNumber = 1;
	int AI_random_searchGridHighNumber = 64;

	//Tracks the number of predictions and the current prediction value
	int human_Number_of_Predictions = 0;
	int human_current_location_prediction = 0;
	int AI_Binary_Number_of_Predictions = 0;
	int AI_binary_current_location_prediction = 0;
	int AI_linear_Number_of_Predictions = 0;
	int AI_linear_current_location_prediction = 0;
	int AI_random_Number_of_Predictions = 0;
	int AI_random_current_location_prediction = 0;

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
		cout << "\nThe Binary AI guesses the target is at location  " << AI_binary_current_location_prediction << endl;
		AI_binary_current_location_prediction = ((AI_binary_searchGridHighNumber - AI_binary_searchGridLowNumber) / 2) + AI_binary_searchGridLowNumber;
		++AI_Binary_Number_of_Predictions;

		if (AI_binary_current_location_prediction > actualTargetLocation)
		{
			cout << "The Binary AI target prediction was too high.\n\n";
			AI_binary_searchGridHighNumber = AI_binary_current_location_prediction - 1;
		}
		else if (AI_binary_current_location_prediction < actualTargetLocation)
		{
			cout << "The Binary AI target prediction was too low.\n\n";
			AI_binary_searchGridLowNumber = AI_binary_current_location_prediction + 1;
		}
		else if (AI_binary_current_location_prediction == actualTargetLocation)
		{
			cout << "\nThat's it! The Binary AI got it in " << AI_Binary_Number_of_Predictions << " guesses!\n";
			cout << "\nDrone engaging target...\n\n";
		}
	} while (AI_binary_current_location_prediction != actualTargetLocation);
	//************** End Binary AI Tries to find the target ******************

	//Transition to the next guessing algorithm
	cout << "The Binary AI is finished, to launch the Linear AI ";
	system("Pause");
	
	//************** Start Linear AI Tries to find the target ******************
	do
	{
		//This is where the AI makes a target location guess
		cout << "\nThe real target location is at " << actualTargetLocation << endl;
		//This is the algorithm which makes the linear AI prediction
		AI_linear_current_location_prediction++;
		cout << "\nThe Linear AI guesses the target is at location  " << AI_linear_current_location_prediction << endl;
		AI_linear_Number_of_Predictions++;

		if (AI_linear_current_location_prediction > actualTargetLocation)
		{
			cout << "The Linear AI target prediction was too high.\n\n";
		}
		else if (AI_linear_current_location_prediction < actualTargetLocation)
		{
			cout << "The Linear AI target prediction was too low.\n\n";
		}
		else if (AI_linear_current_location_prediction == actualTargetLocation)
		{
			cout << "\nThat's it! The Linear AI got it in " << AI_linear_Number_of_Predictions << " guesses!\n";
			cout << "\nDrone engaging target...\n\n";
		}
	} while (AI_linear_current_location_prediction != actualTargetLocation);
	//************** End Linear AI Tries to find the target ******************

	//Transition to the next guessing algorithm
	cout << "The Linear AI is finished, to launch the Random AI ";
	system("Pause");

	//************** Start Random AI Tries to find the target ******************
	do
	{
		//This is where the AI makes a target location guess
		cout << "\nThe real target location is at " << actualTargetLocation << endl;
		//This is the algorithm which makes the random AI prediction
		AI_random_current_location_prediction = rand() % AI_random_searchGridHighNumber + AI_random_searchGridLowNumber;
		cout << "\nThe Random AI guesses the target is at location  " << AI_random_current_location_prediction << endl;
		AI_random_Number_of_Predictions++;

		if (AI_random_current_location_prediction > actualTargetLocation)
		{
			cout << "The Random AI target prediction was too high.\n\n";
		}
		else if (AI_random_current_location_prediction < actualTargetLocation)
		{
			cout << "The Random AI target prediction was too low.\n\n";
		}
		else if (AI_random_current_location_prediction == actualTargetLocation)
		{
			cout << "\nThat's it! The Random AI got it in " << AI_random_Number_of_Predictions << " guesses!\n";
			cout << "\nDrone engaging target...\n\n";
		}
	} while (AI_random_current_location_prediction != actualTargetLocation);
	//************** End Random AI Tries to find the target ******************

	cout << "The Random AI is finished, to see who won ";
	system("Pause");

	// ********************************* Who won? ***************************************
	cout << "\n\n\t *** The Final Results *** \n\n";
	cout << "The Human AI found the target in " << human_Number_of_Predictions << " attempts." << endl;
	cout << "The Binary AI found the target in " << AI_Binary_Number_of_Predictions << " attempts." << endl;
	cout << "The Linear AI found the target in " << AI_linear_Number_of_Predictions << " attempts." << endl;
	cout << "The Random AI found the target in " << AI_random_Number_of_Predictions << " attempts." << endl;

	if (human_Number_of_Predictions < AI_Binary_Number_of_Predictions && human_Number_of_Predictions < AI_linear_Number_of_Predictions && human_Number_of_Predictions < AI_random_Number_of_Predictions)
	{
		cout << "\n\n The Human won the search! Congrats! \n\n";
	}
	else if (AI_Binary_Number_of_Predictions < human_Number_of_Predictions && AI_Binary_Number_of_Predictions < AI_linear_Number_of_Predictions && AI_Binary_Number_of_Predictions < AI_random_Number_of_Predictions)
	{
		cout << "\n\n The Binary AI won the search! Better luck next time. \n\n";
	}
	else if (AI_linear_Number_of_Predictions < human_Number_of_Predictions && AI_linear_Number_of_Predictions < AI_Binary_Number_of_Predictions && AI_linear_Number_of_Predictions < AI_random_Number_of_Predictions)
	{
		cout << "\n\n The Linear AI won the search! Better luck next time. \n\n";
	}
	else if (AI_random_Number_of_Predictions < human_Number_of_Predictions && AI_random_Number_of_Predictions < AI_Binary_Number_of_Predictions && AI_random_Number_of_Predictions < AI_linear_Number_of_Predictions)
	{
		cout << "\n\n The Random AI won the search! How the heck did that happen? Better luck next time. \n\n";
	}
	
	return 0;
}