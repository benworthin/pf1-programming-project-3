#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Function to get user input
int getUserInput() {

    int input;

    cout << "> ";
    cin >> input;

    return input;

}

// Function to validate user input
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

// Function to generate random number based on max value parameter
int generateRandomNumber(int max) {

    return rand() % max + 1;

}

int main() {

    // Declaration of all constants and variables needed outside for loop scope
    const int MIN_DIGGERS = 1;
    const int MAX_DIGGERS = 5;
    const int MIN_WAGE = 9;
    const int MAX_WAGE = 35;
    const int COLD_WEEK_HOURS = 30;
    const int HOT_WEEK_HOURS = 20;
    int totalProfit = 0;

    // Get number of diggers hired
    cout << "--- Atari Vintage Game Profit Calculator ---" << endl;
    cout << "Amount of diggers to hire (1-5): " << endl;
    int diggersHired = getUserInput();
    diggersHired = validateUserInput(diggersHired, MIN_DIGGERS, MAX_DIGGERS);

    // Get wage paid to diggers
    cout << "Diggers Wage (9-35): " << endl;
    int diggersWage = getUserInput();
    diggersWage = validateUserInput(diggersWage, MIN_WAGE, MAX_WAGE);

    // Output table labels
    cout << setw(5) << "Week" << setw(15) << "Hours" << setw(15) << "Games" << setw(15)
         << "Price" << setw(15) << "Profit" << setw(15) << "Total" << endl;

    // 52 week simulation
    for (int week = 1; week <= 52; week++) {

        // Declare all variables so the values aren't reset every iteration
        int weekManHours;
        int gamesFoundInAManHour;
        int gamesFoundInAWeek;
        int gameSalePrice;
        int weekProfit;
        int weekWagesPaid;
        int coldOrHotWeek;

        // Get random value and decide on hot or cold week
        coldOrHotWeek = generateRandomNumber(2);
        if (coldOrHotWeek == 1) {
            coldOrHotWeek = HOT_WEEK_HOURS;
        } else {
            coldOrHotWeek = COLD_WEEK_HOURS;
        }

        // Calculate man hours that week
        weekManHours = diggersHired * coldOrHotWeek;

        // Get random number of games found and calculate games found in a week
        gamesFoundInAManHour = generateRandomNumber(6);
        gamesFoundInAWeek = gamesFoundInAManHour * weekManHours;

        // Decide sales price for games
        if (gamesFoundInAWeek <= 99) {
            gameSalePrice = 10;
        } else if (gamesFoundInAWeek <= 199) {
            gameSalePrice = (20 - (gamesFoundInAWeek / 10));
        } else {
            gameSalePrice = 1;
        }

        // Calculate wages paid a week, week profit and total profit
        weekWagesPaid = diggersWage * weekManHours;
        weekProfit = (gamesFoundInAWeek * gameSalePrice) - weekWagesPaid;
        totalProfit += weekProfit;

        // Output numbers to user
        cout << setw(5) << week << setw(15) << weekManHours << setw(15) << gamesFoundInAWeek << setw(15)
             << gameSalePrice << setw(15) << weekProfit << setw(15) << totalProfit << endl;

    }

    cout << "Congratulations! You made $" << totalProfit << " total profit!" << endl;

    return 0;

}