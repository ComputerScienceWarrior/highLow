#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	char player1Name[20];
	printf("Hello, what is your name?\n");

	fgets(player1Name, sizeof(player1Name), stdin);
	player1Name[strcspn(player1Name, "\n")] = 0;

	printf("Nice to meet you, %s.\nLets play a game called \"High Low\".\n", player1Name);

	return 0;
}