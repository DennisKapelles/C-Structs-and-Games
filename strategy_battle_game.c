#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mystructs.h"
#include "myfunctions.h"

int main(){


  Player* player1 = initializePlayer("player 1");
  Player* player2 = initializePlayer("player 2");
  Player* winner = 0;


  Unit* army_of_player1 = (Unit *)calloc(UNIQUEUNITS, sizeof( Unit));
  player1->army = army_of_player1;

  Unit* army_of_player2 = (Unit *)calloc(UNIQUEUNITS, sizeof( Unit));
  player2->army = army_of_player2;

  FILE *fp;
  fp = fopen("units.txt", "r");

  if (fp == NULL) {
    printf("Could not open units.txt\n");
    exit(0);
  }
  initializePlayersArmiesFromFile(player1, player2, fp);
  printf("The game is about to start!!! Get Ready:\n");
  printRules();
  while(1){
    printf("******************* New Round **********************\n");
    playRound(player1);
    printf("##################  Next player #####################\n");
    playRound(player2);
    winner = checkForWinner(player1, player2);
    if(winner != NULL){
      printf("Congatulations %s, you won here are your stats\n",winner->player_name);
      printPlayerStats(winner);
      break;
    }
    printf("******************* End of Round **********************\n");
  }

  printf("Game is over, please play again whenever you wish\n");
  fclose(fp);
  exit(0);
}


//initialize player struct
Player* initializePlayer(char playerName[20]) {
  Player* player = (Player *)calloc(1, sizeof(Player));
  strcpy(player->player_name, playerName);
  player-> army_size = 0;
  player-> money_balance = STARTBALANCE;
  return player;
}

//initialize all players armies while readinf from file unit's stats
void  initializePlayersArmiesFromFile(Player *player1, Player *player2, FILE *fp){
  int code=0;
  char line[LINELENGTH];
  char name[20];
  int att, cost, sup;
  Unit *unit;

  while (fgets(line,LINELENGTH, fp) != NULL) {
    //read a line from file
    sscanf(line, "%s%d%d%d", name, &att, &cost, &sup);
    //initialize units stats using the data from the line
    //do the same for both players units
    initializeUnitWithValues(player1->army + code, code, name, att, cost, sup);
    unit = &player2->army[code];
    initializeUnitWithValues(player2-> army + code, code, name, att, cost, sup);
    code++;
  }

}
//initialize unit with stats
void initializeUnitWithValues(Unit *unit, int code, char name[20], int att, int cost, int sup){
  strcpy( unit->name , name);
  unit->att = att;
  unit->cost = cost;
  unit->sup = sup;
  unit->num = 0;
  unit->code = code;
}


void printOptionsMenu(){
  printf("What would you like to do next? \n");
  printf("1) Buy some new units \n");
  printf("2) Show Game Rules \n");
  printf("3) Show my army stats \n");
  printf("4) Do nothing \n");
}

//inteface main menu
void printRules(){
  printf("Simple rules:\n");
  printf("1) The first one whose army power is greater than others by 100,at the end of the round is declared as a winner\n");
  printf("2) The first one whose money balance reachs 200 euros will be the winner\n");
  printf("3) You all start with %d euros", STARTBALANCE);
  printf("4) You can only buy one type of unit during your turn\n");
  printf("5) If your money balance get to be negative it's over mannn.. Take care what you choose to buy\n");
}

void printPurchaseOptions(Unit *army){
  int i =0;
  printf("Choose what kind of unit would you like to buy ? \n");
  for(i=0; i<UNIQUEUNITS; i++){
    printf("%d)Buy some %ss?", i, (army+i)->name);
    printf("(cost per unit: %d , attack dmg per unit: %d, maintanance cost per round for each unit: %d)\n",(army+i)-> cost, (army+i)->att, (army+i)-> sup);
  }
}

//show unit info
void printUnitInfo(Unit *unit){
  printf("Unit Name: %s\n", unit->name);
  printf("Unit purchae cost: %d\n", unit->cost);
  printf("Unit support cost: %d\n", unit->sup);
  printf("Unit code: %d\n", unit->code);
  printf("Players unit size: %d\n", unit->num);
}

void printPlayerStats(Player *player){
  printf("Your finance balance is: %d \n", player->money_balance);
  printf("Your army cost per round is: %d \n", player-> cost_per_round);
  printf("Your army size is: %d units total\n" , player->army_size);
  printf("Your army attack damage is: %d \n", player-> attack_damage);
}

void printPlayersArmyStats(Player *player){
  Unit *unit;
  for(unit = player->army; unit< player-> army + UNIQUEUNITS; unit++){
    printf(" You have %d %ss\n",unit->num, unit->name);
  }
}

//central function for our logic
//simulation of one round for a player
void playRound(Player *player){
  int choice=-1;
  int purchaceChoice = -1;
  printf("It's your turn %s\n", player->player_name);
  printPlayerStats(player);
  do{
    //get what to do next from players input
    printOptionsMenu();
    scanf("%d", &choice);
    while ( getchar() != '\n' );
    switch (choice){
      case(1):
        //if he wants to buy something, show him his options
        printPurchaseOptions(player-> army);
        purchaceChoice = choosePurchaseOption();
        //purchase what he asked for
        purchaseUnitWithCode( purchaceChoice, player);
        break;
      case(2):
        printRules();
        break;
      case(3):
        printPlayersArmyStats(player);
        break;
      case(4):
        choice = 1;
        break;
      default:
        printf("Not a valid option \n");
        break;
    }
  }while(choice != 1);
  calculateRoundCostFor(player);
  printf("Your turn ended, your new stats are: \n");
  printPlayerStats(player);
}

int choosePurchaseOption(){
  int choice = -1;
  while(choice <0 || choice >= UNIQUEUNITS){
    printf("What is your choice? You must enter a value from 0 to %d \n", UNIQUEUNITS-1);
    scanf("%d", &choice);
    while ( getchar() != '\n' );

  }
  return choice;
}

void purchaseUnitWithCode(int choice, Player *player){
  int size = -1;
  int cost = 0;

  while (1){

    while(size == -1){
      printf("How many units would you like to buy? Choose wise ...The total cost of the units cannot exceed your money balance\n");
      printf("Also remeber that after the round ends you cannot owe money\n");

      scanf("%d", &size);

      while ( getchar() != '\n' );
    }

    cost = size * player->army[choice].cost;
    if (player-> money_balance >= cost){
      break;
    }
    else{
      printf("Your cannot afford so many units , choose again..\n");
    }
  }
  player-> money_balance -= cost;
  printf("New balance after purchase is %d\n", player-> money_balance);
  player-> army_size += size;
  player-> army[choice].num += size;
  player-> attack_damage += size * player-> army[choice].att;
}
//well having an army costs a lot
//depending on the total cost ( or gain ) of units 
//we calculate the new balance
//and we also calculate the total cost per round .
void calculateRoundCostFor(Player *player){
  int i;
  player-> cost_per_round = 0;
  for(i =0; i<UNIQUEUNITS; i++){
    player-> cost_per_round += player->army[i].sup * player->army[i].num;
    player-> money_balance -= player->army[i].sup * player->army[i].num;
  }
}

// We should have a winner
// this functions tries to find if we have a winner in this round
Player* checkForWinner(Player *player1, Player *player2){
  Player *winner = NULL;
  //check if someone bankrupted
  if(player1->money_balance < 0){
    winner = player2;
    return winner;
  }

  if(player2-> money_balance <0){
    winner = player1;
    return winner;
  }

  //check if someones balance is much greater than others
  if(player1-> money_balance  != player2-> money_balance){
    if(player1-> money_balance >= RICH)
      winner = player1;
    if(player2-> money_balance >= RICH)
      winner = player2;
  }
  //army power is more important than just being rich
  if((player1-> attack_damage  - player2-> attack_damage) == GREATARMYPOWER){
    winner = player1;

  }else if((player2-> attack_damage -player1-> attack_damage) == GREATARMYPOWER){
    winner = player2;
  }
  return winner;
}





