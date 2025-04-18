#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int highLow(char *player1, char *player2, int random, int counter);

int main() {
	srand(time(NULL));
	int randomNumber = rand() % 100;
	int attemptCounter = 0;
	char player1Name[20];
	char player2Name[] = "GAME_MASTER.exe";

	printf("Hello, what is your name?\n");

	fgets(player1Name, sizeof(player1Name), stdin);
	player1Name[strcspn(player1Name, "\n")] = 0;

	printf("Nice to meet you, %s.\nLets play a game called \"High Low\".\n", player1Name);
	highLow(player1Name, player2Name, randomNumber, attemptCounter);

	return 0;
}

int highLow(char *player1, char *player2, int random, int counter) {
	int guess;

	if (counter == 7) {
		printf("Sorry, you've reached the maximum number of attempts. Try again next time!");
		return 0;
	}

	printf("Guess the number between 0 and 99.\n");
	scanf_s("%d", &guess);
	
		if (guess == random) {
			printf("You win, %s! Way to go!!!\n", player1);
			return 0;
		}
		if (guess < random) {
			counter++;
			printf("Sorry, that guess is too low. Try a higher guess. That was %d/7 attempts.\n", counter);
			highLow(player1, player2, random, counter);
		}
		else if (guess > random) {
			counter++;
			printf("Sorry, that guess is too high. Try a lower guess. That was %d/7 attempts.\n", counter);
			highLow(player1, player2, random, counter);
		}

	return 0;
}