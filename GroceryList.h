#pragma once
#ifndef GROCERY_LIST_H
#define GROCERY_LIST_H

#include <string>
#include <map>
#include <vector>
using namespace std;

class GroceryList { // Declare GroceryList class
public: // Declare public constructor and methods 
    GroceryList(vector<string> t_items);// Constructor 
    void printItemQuantity(string t_itemToFind); // Search for item
    void printHistogram(); // Print histogram
    void printList(); // Print list
  
private:// Declare private variables/methods with m_ for member per naming guidelines
    map<string, int> m_groceryItems;
};
#endif
