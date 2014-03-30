//  Prog-Challenge-4
//
//  From http://beginnerscpp.com/?cat=129
//
//  Created by Timothy Kolstrom on 3/30/14.
//  Copyright (c) 2014 tkolsty89. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <cmath>
#include <stdio.h>      
#include <stdlib.h>


using namespace std;


// Declares an array of up to 100 integers
int num[100];

// Function prototypes
void guessNum(int);
void displayNums(int);


// Main function
int main()
{
    
    // Local main variables
    int playAgain;

    int totalNums;
    

    do
    {
        
        // Title screen
        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "--------------------------------------------";
        cout << endl;
        
        
        
        
        // Asks the user how many numbers they would like
        cout << endl << "How many numbers would you like? ";
        cin >> totalNums;
        
        // Calls the number displaying function passing the total amt of nums decided by the user
        displayNums(totalNums);
    
        // Calls the guessNum fn in which the user plays the game
        guessNum(num[rand() % 10]);
    
        
        
        cout << endl << "Play again? (0 for No / 1 for Yes) "; // Prompts the user if they want to quit
        cin >> playAgain;
        
        
    }while(playAgain == 1); // Loop that keeps allowing user to play the game until they hit zero
        
    
  
        
  
    return 0;
    
}



// FUNCTION -- To display the random numbers

void displayNums(int totalNums)
{
    srand(time(0));
    
    
    
    cout << endl;
    cout << "*********************************************" << endl << endl;
    
    // Runs a for loop to display the amount of numbers that the user has chosen
    for(int i = 0; i < totalNums; i++)
    {
        
        // Sets each element of the array equal to a random number between 0-99 (incl)
        num[i] = rand() % 100;
        
        // Displays the number
        cout << num[i] << " ";
        
    }
    
    cout << endl << endl;
    cout << "*********************************************" << endl;
    
    return; // Breaks from the function
    
}



// FUNCTION -- Runs the guessing game

void guessNum(int correctNum)
{
    
   
    // Declare local variables
    int userNum;
    int guesses = 1; // Var guesses is set equal to 1 for display purposes
    int totalGuesses;
    
    
    // Prompts the user as to how many guesses they would like to have
    cout << endl << "How many guesses would you like? ";
    cin >> totalGuesses;
    cout << endl;
    
    cout << endl << "See if you can guess the number: " << endl;
    
    // Do-while loop that executes until the max number of guesses is reached
    do
    {
        cout << "? ";
        cin >> userNum;
       
        // Validates that the number is within range
        if (userNum >= 0 && userNum < 100)
        {
       
            
            
            // Alerts the user whether the number is too high, too low or just right
            if(userNum > correctNum)
            {
                cout << userNum << " is too high!" << endl;
                guesses++; // Adds one to the guesses counter
            }
            else if(userNum < correctNum)
            {
                cout << userNum << " is too low!" << endl;
                guesses++;
            }
            else if(userNum == correctNum) // If the user guesses the correct number, a win message will display
            {
                
                cout << "******************************************" << endl;
                
                if(guesses == 1)
                {
                
                    cout << "Great job, you guessed it in " << guesses << " try!" << endl;
                    
                }
                else
                {
                    cout << "Great job, you guessed it in " << guesses << " tries!" << endl;
                }
                cout << "******************************************" << endl;
                
                
                return; // Breaks from the function
                
            }
        }
        else
        {
            cout << "Invalid number, try again!" << endl; // Invalid number, no guesses are eliminated
            
        }
            
        cout << "Guess Again (# "<< guesses << " ): ";
            
    }while(guesses <= totalGuesses); // Executes until the user has surpassed the total amount of guesses allowed
    
  
    cout << endl << "Sorry, game over!" << endl; // Displays a game over message
    
    return; // Breaks from the function
    
    
    
    
    
}

