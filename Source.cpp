/*  Name: Ryan Hubbuck
*   CS-210
*   Project 3
*   Date: 04/13/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "GroceryList.h"
using namespace std;

void printUserMenu() { // Define function to print menu for user to make selections
    cout << endl << endl << "****************************************" << endl;
    cout << "Please make a selection:" << endl;
    cout << "1 - Search for an item" << endl;
    cout << "2 - Print list of items and quantities" << endl;
    cout << "3 - Print histogram of items" << endl;
    cout << "4 - Add/Change value of item" << endl;
    cout << "5 - Print list of items with values" << endl;
    cout << "6 - Print list of items and quantity with values" << endl;
    cout << "7 - Exit program" << endl;
    cout << "****************************************" << endl;
}

int main() {
    ifstream listFS; // Declare variable to store instream file
    ofstream outFS; // Output file stream

    map<string, int> backupFileList; // Declare map to store data for backup file
    vector<string> groceryStoreList; // Declare vector to transfer into map
    string listItem; // Declare variable to store item being read in
    int userSelection; // Declare variable for user menu input
    string userInput; // Declare variable for user input search
    bool runProgram = true; // Declare boolean to exit/continue program
    string itemToAddPriceTo; // Declare variable to search for 

    // Open file to read from on my local device
    listFS.open("C:\\Users\\rhubb\\OneDrive\\Desktop\\CS210_Project_Three_Input_File.txt");

    // Open file to write to
    outFS.open("frequency.dat");

    if (!outFS.is_open()) { // Display error if out file cannot open
        cout << "Could not open file frequency.dat." << endl;
        return 1;
    }

    if (!listFS.is_open()) { // Display error message if in file could not open
        cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
        return 1;
    }

    while (!listFS.eof()) {
        listFS >> listItem;
        if (!listFS.fail()) { // If the file read doesn't fail, add items into vector    
            groceryStoreList.push_back(listItem);    
        }
    }

    GroceryList newList(groceryStoreList); // Create new GroceryList object

    for (int i = 0; i < groceryStoreList.size(); i++) { // Transfer vector data into backup file map
        backupFileList[groceryStoreList[i]]++;
    }
    for (auto& pair : backupFileList) { // Print backup file map into frequency.dat
        outFS << pair.first << " - " << pair.second << endl;
    }
    
    listFS.close(); // Close the file being read in
    outFS.close(); // Close the file being written to

    while (runProgram) { // While boolean is true
        printUserMenu(); // Print menu to user
        cin >> userSelection; // Take user selection input

        if (userSelection == 1) { // If 1, take user string input 
            cout << "Enter an item name" << endl;
            cin >> userInput;
            newList.printItemQuantity(userInput); // Search for item in map
        }

        else if (userSelection == 2) { // If 2, print list
            newList.printList();
        }

        else if (userSelection == 3) { // If 3, print histogram
            newList.printHistogram();
        }


        else if (userSelection == 4) { // If 4, allow user to input a value
            cout << "Please enter an item to add/change value of." << endl;
            cin >> itemToAddPriceTo;
            newList.addPrice(itemToAddPriceTo);
        }

        else if (userSelection == 5) { // If 5, print list of items and values
            newList.printListWithPrices();
        }

        else if (userSelection == 6) { // If 6, print list of item, quantity, and value
            newList.printListAllData();
        }

        else if (userSelection == 7) { // If 7, exit program
            cout << "Thank you for using CornerGrocerApp" << endl;
            runProgram = false;
        }

        else { // If input is not a valid choice, clear cin and display error message
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl << "Please enter a valid menu input (1,2,3,4)" << endl;
        }
    }

    return 0;
}