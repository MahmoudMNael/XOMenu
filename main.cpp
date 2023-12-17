#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"

using namespace std;

void displayMenu(){
	cout << "Welcome to The XO Bundle games!\n";
	cout << "We've got a bunch of games for you:\n";
	cout << "1. The plain old XO Game.\n";
	cout << "2. The Pyramic XO.\n";
	cout << "3. The 4x4 XO.\n";
	cout << "4. The 5x5 XO.\n";
}

int inputNumOfPlayers(){
	cout << "How many players are gonna play?\n";
	cout << "1. One Player\n";
	cout << "2. Two Players\n";
	int choice;
	while(cin >> choice){
		if (choice < 1 || choice > 2){
			cout << "Please enter a valid number from 1~2\n";
			continue;
		}
		return choice;
	}
}

int chosenGame(){
	cout << "Choose a number from 1~4: \n";
	int choice;
	while(cin >> choice){
		if (choice < 1 || choice > 4){
			cout << "Please enter a valid number from 1~4\n";
			continue;
		}
		return choice;
	}
}

void initiateXO(Player* players[2]){
	GameManager XOGame(new X_O_Board(), players);
	XOGame.run();
}

void initiatePyramicXO(Player* players[2]){
	GameManager XOGame(new XOBoardPyramic(), players);
	XOGame.run();
}

void initiate4XO(Player* players[2]){
	GameManager XOGame(new X_O_Board_4(), players);
	XOGame.run();
}

void initiate5x5XO(Player* players[2]){
	GameManager_5x5 XOGame(new X_O_Board_5x5, players);
	XOGame.run();
}

int main() {
	displayMenu();
	int chosenGameNum = chosenGame();
	int chosenNumOfPlayers = inputNumOfPlayers();
	bool isPlayersComplete = false;
	
	Player* players[2];
	
	players[0] = new Player (1, 'x');
	
	if (chosenNumOfPlayers == 2){
		players[1] = new Player (2, 'o');
		isPlayersComplete = true;
	}
	
	
	switch (chosenGameNum) {
		case 1:
			if (!isPlayersComplete)
				players[1] = new RandomPlayer ('o', 3);
			initiateXO(players);
			break;
		case 2:
			if (!isPlayersComplete)
				players[1] = new RandomPlayer ('o', 5);
			initiatePyramicXO(players);
			break;
		case 3:
			if (!isPlayersComplete)
				players[1] = new RandomPlayer ('o', 7);
			initiate4XO(players);
			break;
		case 4:
			if (!isPlayersComplete)
				players[1] = new RandomPlayer ('o', 5);
			initiate5x5XO(players);
			break;
	}
	system ("pause");
	
	return 0;
}
