// CSC251 - C Lang Prog and Unix
// proj02
// Simple Number Guessing Game
// Steve Tapia
// 10/11/2024

#include <stdio.h> // Library for I/O
#include <stdlib.h> // Library for random
#include <time.h> // Library for time

int main() {
	int randNum;
	// Seed the random number with the current time
	// To ensure that the number is random each run
	srand(time(NULL));
	randNum = rand() % 10 + 1;

	// This is contols the while loop, to keep the game looping
	int x = 1;
	// This is the game loop
	// When x is 1 it let continue to loop
	// When x is 0 it will end the loop
	while(x == 1){
		// This label is used for jumping back to the start
		start:

		//Display the menu
		printf("\n--- Simple Number Guessing Game ---\n");
		printf("1. Guess the number\n2. Skip a turn\n3. Give up(exit)\n");
		
		int input;
		printf("Your choice(1-3): ");
		scanf("%d", &input);
		
		// This is a input validation loop
		// To ensure that the user input is valid
		while ( input < 1 || input > 3){
			printf("\nInvalid input. Please enter a number between 1 and 3.\n\n");
			printf("Your choise(1-3): ");
			scanf("%d", &input);
		}
		
		// Switch cases to handle the player's menu choice
		switch (input){
			case 1:
				int userGuess;
				printf("\nEnter your guess(between 1 and 10): ");
				scanf("%d", &userGuess);

				// A input validation loop to ensure the guess is valid
				while(userGuess < 1 || userGuess > 10){
					printf("\nInvalid guess input. Please enter a guess between 1 and 10.\n");
					printf("\nEnter your guess(between 1 and 10): ");
					scanf("%d", &userGuess);
				}
				//Checks if the guess is correct, too low, or too high
				if(userGuess == randNum){
					printf("\nCongratulations! You guessed the correct number: %d\n", randNum);
					x = 0; // Set x to 0 to end the loop
				}
				else if(userGuess < randNum){
					printf("\nToo low! Try again.\n");
					continue; // Continues the loop
				}
				else if(userGuess > randNum){
					printf("\nToo high! Try again.\n");
					continue; // Continues the loop
				}
				break;
			case 2:
				printf("\nYou choose to skip your turn.\n");
				goto start; // Jumps back to the start
			case 3:
				printf("\nYou choose to give up.\n");
				printf("\nHere is the answer: %d\n", randNum);
				goto end; // jumps to end of the game
			default:
				printf("Error. Try again.");
		}
		end: // Label is used for jumping to the end
		printf("\nThanks for playing the Simple Number Guessing Game!");
		return 0;
	}
}
