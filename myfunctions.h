
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//initialization functions
Player * initializePlayer(char playerName[20]);
void  initializePlayersArmiesFromFile(Player *player1, Player *player2, FILE *fp);
void initializeUnitWithValues(Unit *unit, int code, char name[20], int att, int cost, int sup);

//inteface and menu functions
void printOptionsMenu();
void printRules();
void printPurchaseOptions(Unit *army);
void printUnitInfo(Unit *unit);
void printPlayerStats(Player *player);
void printPlayersArmyStats(Player *player);

//user interaction and system functions
void playRound(Player *player);
int choosePurchaseOption();
void purchaseUnitWithCode(int choice, Player *player);
void calculateRoundCostFor(Player *player);
Player* checkForWinner(Player *player1, Player *player2);

