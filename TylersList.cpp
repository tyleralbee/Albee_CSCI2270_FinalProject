#include <iostream>
#include "TylersList.h"
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

HashTable::HashTable(){

}

HashTable::~HashTable(){
	for (int i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			delete hashTable[i];
		}
		else{
            break;
		}
	}
}

void HashTable::displayMenu(){
    cout << "Welcome to Tyler's List! What would you like to do?" << endl;
    cout << "1. Sell Item" << endl;
    cout << "2. Buy Item" << endl;
    cout << "3. Retrieve Item Details" << endl;
    cout << "4. Print List of Items For Sale" << endl;
    cout << "5. Include Items Not in Your Area in Sale List" << endl;
    cout << "6. Quit" << endl;
    return;
}

int HashTable::hashSum(string inputString, int tableSize){
	int sum = 0;
    for (int i = 1; i < inputString.length(); i++){
    	sum = sum + inputString[i];  //ascii value of ith character in the string
    }
    sum = sum % tableSize;
    return sum;
}

void HashTable::printItemsForSale(){
	bool empty = true;

	for (int i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			for (int j = 0; j < hashTable[i]->size(); j++){
				cout << (*hashTable[i])[j].item << "is being sold for " << (*hashTable[i])[j].price << "dollars in " << (*hashTable[i])[j].location << endl;
				empty = false;
			}
		}
	}
	if (empty == true)
		cout << "There are currently no items in your area for sale. " << endl;
	return;
}

void HashTable::sellItem(string name, int price, string location){
	int index = hashSum(name,tableSize);
	if (hashTable[index] == NULL){
        hashTable[index] = new vector<ItemStruct>;
		hashTable[index]->push_back(ItemStruct(name,price,location));
	}

	else{
		for(int i = 0; i < hashTable[index]->size(); i++){
			if((*hashTable[index])[i].item == name){
				cout << "That item is already for sale!" << endl;
				break;
			}
		}
		hashTable[index]->push_back(ItemStruct(name,price,location));
	}
}

void HashTable::buyItem(string name){
	int index = hashSum(name,tableSize);
	bool found = false;

	if (hashTable[index] != NULL){
		for (int i = 0; i < hashTable[index]->size(); i++){
			if ((*hashTable[index])[i].item == name){
				hashTable[index]->erase(hashTable[index]->begin() + i);
				found = true;
				break;
			}
		}
		if (hashTable[index]->size() == 0){
			delete hashTable[index];
			hashTable[index] = NULL;
		}
	}
	if (found == false){
		cout << "Item not found." << endl;
	}
	return;
}

void HashTable::findItemPrice(string name){
	int index = hashSum(name,tableSize);
	bool found = false;

	if (hashTable[index] != NULL){
		for (int i = 0; i < hashTable[index]->size(); i++){
			if ((*hashTable[index])[i].item == name){
				cout << (*hashTable[index])[i].item << "is being sold for " << (*hashTable[index])[i].price << "dollars in " << (*hashTable[index])[i].location << endl;
				found = true;
				break;
			}
		}
	}
	if (found == false){
		cout << "Item not found." << endl;
	}
	return;
}
