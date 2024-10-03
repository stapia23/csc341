// CSC251 - C Lang Prog and Unix
// proj02
// Simple Number Guessing Game
// Steve Tapia
// 10/11/2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int randNum;
	srand(time(NULL));
	randNum = rand() % 10 + 1;

	int x = 1;
	while(x == 1){
		start:
		printf("\n--- Simple Number Guessing Game ---\n");
		
		printf("1. Guess the number\n2. Skip a turn\n3. Give up(exit)\n");
		
		int input;
		printf("Your choice(1-3): ");
		scanf("%d", &input);
		
		while ( input < 1 || input > 3){
			printf("\nInvalid input. Please enter a number between 1 and 3.\n\n");
			printf("Your choise(1-3): ");
			scanf("%d", &input);
		}

		switch (input){
			case 1:
				int userGuess;
				printf("\nEnter your guess(between 1 and 10): ");
				scanf("%d", &userGuess);

				while(userGuess < 1 || userGuess > 10){
					printf("\nInvalid guess input. Please enter a guess between 1 and 10.\n");
					printf("\nEnter your guess(between 1 and 10): ");
					scanf("%d", &userGuess);
				}
				
				if(userGuess == randNum){
					printf("\nCongratulations! You guessed the correct number: %d\n", randNum);
					x = 0;
				}
				else if(userGuess < randNum){
					printf("\nToo low! Try again.\n");
					continue;
				}
				else if(userGuess > randNum){
					printf("\nToo high! Try again.\n");
					continue;
				}
				break;
			case 2:
				printf("\nYou choose to skip your turn.\n");
				goto start;
				break;
			case 3:
				printf("\nYou choose to give up.\n");
				printf("\nHere is the answer: %d\n", randNum);
				x = 0;
				break;
			default:
				printf("Error. Try again.");
		}

		printf("\nThanks for playing the Simple Number Guessing Game!");
		
		return 0;
	}
}
