#include <iostream>
using namespace std;

#include "GroceryList.h"
#include <iomanip>
#include <map>
#include <vector>

// Define constructor for new GroceryList
GroceryList::GroceryList(vector<string> t_items) { // Take vector as parameter
	for (int i = 0; i < t_items.size(); i++) { // Loop through vector
		m_groceryItems[t_items[i]]++; // Add into map and iterate to count duplicates
	}
}

void GroceryList::addPrice(string t_itemToFindPrice) {
	float itemPrice = 0.00;
	cout << "What is the value of the item? $";
	cin >> itemPrice;
	// Format string by removing whitespace
	t_itemToFindPrice.erase(std::remove(t_itemToFindPrice.begin(), t_itemToFindPrice.end(), ' '), t_itemToFindPrice.end());
	t_itemToFindPrice[0] = toupper(t_itemToFindPrice[0]); // Make sure first character is uppercase

	// Check to ensure item is in list of possible items to add price to 
	if (m_groceryItems.count(t_itemToFindPrice) == 1) {
		if (m_itemsWithPrice.count(t_itemToFindPrice) == 0) { // If count returns 0 because item is not in map
			m_itemsWithPrice.insert({ t_itemToFindPrice, itemPrice }); // Insert new pair with price
		}
		else { // Change existing price if key exists
			m_itemsWithPrice[t_itemToFindPrice] = itemPrice;
		}
	}
	else {
		cout << "Sorry, that item does not exist in your collection." << endl;
	}
	return;
}

// Define function to print list of items and quantity
void GroceryList::printList() {
	for (auto& pair : m_groceryItems) { // Break map into key value pairs
		cout << pair.first << " - " << pair.second << endl; // Print key - value
	}
	return;
}

// Define function to print list of items and price
void GroceryList::printListWithPrices() {
	for (auto& pair : m_itemsWithPrice) { // Break map into key value pairs
		cout << endl << pair.first << " - $" << pair.second << endl; // Print key - value
	}
	return;
}

// Define function to print list of item, quantitiy, and price
void GroceryList::printListAllData() {
	int totalItemCount = 0;
	float totalValue = 0.00;
	for (auto& pair : m_itemsWithPrice) { // Break map into key value pairs
		totalValue += (pair.second * m_groceryItems[pair.first]);
		totalItemCount += m_groceryItems[pair.first];
		cout << endl << pair.first << " - $" << pair.second << " x " << m_groceryItems[pair.first] << endl;
	}
	cout << endl << "You have a total of " << totalItemCount << " item(s) worth $" << totalValue << endl;
	return;
}

// Define function to print list as histogram
void GroceryList::printHistogram() {
	for (auto& pair : m_groceryItems) { // Break map into key value pairs
		cout << pair.first << " "; // Print key/item name
		for (int i = 0; i < pair.second; i++) { // Loop number of times as value and print *
			cout << '*'; 
		}
		cout << endl;
	}
	return;
}

// Define function to search list of items for specific item
void GroceryList::printItemQuantity(string t_itemToFind) { // Take user input as parameter
	// Format string by removing whitespace
	t_itemToFind.erase(std::remove(t_itemToFind.begin(), t_itemToFind.end(), ' '), t_itemToFind.end()); 
	t_itemToFind[0] = toupper(t_itemToFind[0]); // Make sure first character is uppercase

	if (m_groceryItems.count(t_itemToFind) == 0) { // If count returns 0 because item is not in map
		cout << t_itemToFind << " - " << "0" << endl; // Print 0 for quantity
	}
	else { // If count returns 1 because item is in the map, print the value/quantity
		cout << t_itemToFind << " - " << m_groceryItems.at(t_itemToFind) << endl;
	}
	return;
}
