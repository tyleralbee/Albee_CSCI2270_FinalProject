#include <iostream>
#include "TylersList.h"
#include <string.h>
#include <vector>

using namespace std;

HashTable::HashTable(){
    tableSize = 10;
}

HashTable::~HashTable(){
	for (int i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			delete hashTable[i];
		}
	}
}


void HashTable::printItemsForSale(){
	bool empty = true;

	for (int i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			for (int j = 0; j < hashTable[i]->size(); j++){
				cout << (*hashTable[index])[i].item << "is being sold for " << (*hashTable[index])[i].price << "dollars in " (*hashTable[index])[i].location << endl;
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
		hashTable[index] = new vector<HashItem>;
		hashTable[index]->push_back(HashItem(name,price,location));
	}

	else{
		for (int i = 0; i < hashTable[index]->size(); i++){
			if ((*hashTable[index])[i].item == name){
				cout << "duplicate" << endl;
				return;
			}
		}
		hashTable[index]->push_back(HashItem(name,price,location));
	}

	return;
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
				cout << (*hashTable[index])[i].item << "is being sold for " << (*hashTable[index])[i].price << "dollars in " (*hashTable[index])[i].location << endl;
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

int HashTable::hashSum(string inputString, int hashLen){
	int sum = 0;
    for (int i = 1; i < inputString.length(); i++){
    	sum = sum + inputString[i];  //ascii value of ith character in the string
    }
    sum = sum % hashLen;
    return sum;
}
