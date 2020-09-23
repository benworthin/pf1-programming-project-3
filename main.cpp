#include <iostream>
using namespace std;

int getUserInput() {

    int input;

    cout << "> ";
    cin >> input;

    return input;

}

int validateUserInput(int userInput, int lowestValue, int highestValue) {

    bool loopAgain = true;

    while(loopAgain) {
        if((userInput < lowestValue) || (userInput > highestValue)) {
            cout << "Invalid input. Please enter a value between " << lowestValue << " and " << highestValue << "." << endl;
            userInput = getUserInput();
        } else {
            loopAgain = false;
        }
    }

    return userInput;

}

int main() {

    // TODO: Number of man hours spent digging in a week
    //  How many people do you want hired to dig? (1-5)
    //  Decide if its a cold or hot week for # of hours worked
    //  20 if hot, 30 if cold (coin flip)
    //  Use this to calculate how many hours spent digging a week
    cout << "--- Atari Vintage Game Profit Calculator ---" << endl;
    cout << "Amount of diggers to hire (1-5): " << endl;
    int diggersHired = getUserInput();
    diggersHired = validateUserInput(diggersHired, 1, 5);
    cout << diggersHired;


    // TODO: Number of game cartridges found in a week
    //  How many game cartridges are found for each man hour of digging
    //  Roll a dice (1-6) to decide
    //  Use this to calculate how many found in a week

    // TODO: Sales price of the game cartridges found in a week
    //  If you sell 1-99 games, $10/game
    //  100-199 games, ($20 - count/10)
    //  >=200 games, $1/game
    //  Use this to calculate money made that week based on games found

    // TODO: Profit/loss for that week
    //  User at start should enter wage for diggers ($9/hr - $35/hr)
    //  Calculate the profit/loss with number of man hours, number of games, and sale price

    // TODO: Profit/loss for the year
    //  Using the numbers above calculate the profit/loss for the year

    return 0;

}