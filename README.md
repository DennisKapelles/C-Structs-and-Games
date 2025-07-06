# Hangman Game

This project implements a simplified version of the classic Hangman word-guessing game in C.

## 🕹️ How It Works

1. **Player 1** inputs a secret word.
2. The screen is cleared and **Player 2** tries to guess the word, one letter at a time.
3. For each wrong guess, the remaining attempts counter decreases.
4. If a guessed letter exists in the word, it is revealed in its correct positions.
5. The game ends when:
   - All letters are guessed correctly ✅
   - The player runs out of attempts ❌

## 🔧 Features

- Converts all input characters to lowercase.
- Checks for repeated guesses and informs the user.
- Clears screen with `system("cls")` or `system("clear")` depending on OS.
- Uses a helper function to check letter existence in word.

## 🛠️ Requirements

- C compiler (e.g. `gcc`)
- Runs on Linux/Windows

## 📦 Compilation

gcc hangman_game.c -o hangman_game

./hangman_game


---

## 📁 `linked_queue.c`

# Linked List Queue Implementation

This project implements a FIFO (First-In-First-Out) Queue using a singly linked list in C.

## 📋 Description

The program defines a `struct node` and allows the user to perform queue operations via a menu:

- `Insert`: Add a new element to the end of the queue.
- `Delete`: Remove and return the element at the front of the queue.
- `GetNth`: Retrieve the value at a specific position in the queue.
- `Count`: Count how many times a specific value appears in the queue.

## 📂 Data Structure

struct node {
    int data;
    struct node* next;
};


🖥️ Menu Options
Insert
Delete
Get-Nth
Count
Exit

📦 Compilation

gcc linked_queue.c -o linked_queue
./linked_queue

---

## Strategy battle game

# Turn-Based Strategy Game

This project simulates a simplified two-player turn-based strategy game in C, involving unit purchasing, resource management, and combat strength.

## 🧱 Structure

A `unit` structure holds attributes like name, attack power, cost, upkeep, and quantity owned.

struct unit {
    char name[20];
    int att;
    int cost;
    int sup;
    int code;
    int num;
};

🎮 Gameplay
Each player takes turns to buy units (e.g. Peon, Grunt, Troll).
Workers generate money, military units consume money and increase attack power.
The game tracks each player’s money and army power.
Victory is achieved when one player has:
Significantly more army power, or
Accumulated enough money.

🛠️ Features
Initialization of unit types (can be read from file).
Two arrays of units, one for each player.
Turn-based input loop for unit purchases.
Dynamic tracking of total money and army strength.

🏁 Victory Conditions
Money-based or army-based win.
Game ends immediately upon victory condition met.

📦 Compilation

gcc strategy_game.c -o strategy_game
./strategy_game
