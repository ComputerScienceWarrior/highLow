#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int highLow(char *player1, char *player2, int random);

int main() {
	srand(time(NULL));
	int randomNumber = rand() % 100;

	char player1Name[20];
	char player2Name[] = "GAME_MASTER.exe";

	printf("Hello, what is your name?\n");

	fgets(player1Name, sizeof(player1Name), stdin);
	player1Name[strcspn(player1Name, "\n")] = 0;

	printf("Nice to meet you, %s.\nLets play a game called \"High Low\".\n", player1Name);
	highLow(player1Name, player2Name, randomNumber);

	return 0;
}

int highLow(char *player1, char *player2, int random) {
	int guess;

	printf("The random is: %d.\n", random);
	printf("Guess the number between 0 and 99.");
	scanf_s("%d", &guess);

	if (guess == random) {
		printf("You win, %s! Way to go!!!", player1);
		return 0;
	}
	if (guess < random) {
		printf("Sorry, that guess is too low. Try a higher guess.");
		highLow(player1, player2, random);
	}
	else if (guess > random) {
		printf("Sorry, that guess is too high. Try a lower guess.");
		highLow(player1, player2, random);
	}
}