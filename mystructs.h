//useful defines
#define STARTBALANCE 200
#define RICH 1000
#define GREATARMYPOWER  100
#define NUMOFPLAYERS 2
#define UNIQUEUNITS 3
#define LINELENGTH 500


//useful structs
typedef struct units {

  char name[20];
  int att;
  int cost;
  int sup;
  int code;
  int num;

} Unit;


typedef struct players {
  char player_name[20];
  int army_size;
  int attack_damage;
  int money_balance;
  int cost_per_round;
  Unit *army;

}Player;



