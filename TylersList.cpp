#include <iostream>
#include "TylersList.h"
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

HashTable::HashTable(int size){
    tableSize = size;
    hashTable = new ItemStruct[size];
}

HashTable::~HashTable(){
    for(int i = 0; i < tableSize; i++){
        ItemStruct *deleter = hashTable[i].next;
        ItemStruct *next = deleter;
        while(next != NULL){
            next = next->next;
            delete deleter;
            deleter = next;
        }
    }
    delete []hashTable;
}

void HashTable::displayMenu(){
    cout << "Welcome to Tyler's List! What would you like to do?" << endl;
    cout << "1. Sell Item" << endl;
    cout << "2. Buy Item" << endl;
    cout << "3. Retrieve Item Details" << endl;
    cout << "4. Print List of Items For Sale" << endl;
    cout << "5. Set location" << endl;
    cout << "6. Include Items Not in Your Area in Sale List" << endl;
    cout << "7. Quit" << endl;
    return;
}

int HashTable::hashSum(string inputString){
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
		if (hashTable[i].item != ""){
            ItemStruct *itemhandler = &hashTable[i];
            while(itemhandler != NULL){
                if(itemhandler->location == myLocation){
                    cout << itemhandler->item << " is being sold for " << itemhandler->price << " dollars in " << itemhandler->location << endl;
                    empty = false;
                }
                itemhandler = itemhandler->next;
            }
		}
	}
	if (empty == true)
		cout << "There are currently no items in your area for sale. " << endl;
		cout << "Change your location to see items in those locations." << endl;
	return;
}

void HashTable::setLocation(string place){
    myLocation = place;
}

void HashTable::sellItem(string name, int price, string location){
	int index = hashSum(name);
	if (hashTable[index].item == ""){
        hashTable[index].item = name;
		hashTable[index].location = location;
		hashTable[index].price = price;
	}

	else{
        ItemStruct *itemHandler = &hashTable[index];
        while(itemHandler->next != NULL){
            if(itemHandler->item == name){
                cout << "That item is already for sale!" << endl;
                return;
            }
            itemHandler = itemHandler->next;
        }
        if(itemHandler->item == name){
            cout << "That item is already for sale!" << endl;
            return;
        }
        ItemStruct *newSellingItem = new ItemStruct;
        newSellingItem->item = name;
        newSellingItem->price = price;
        newSellingItem->location = location;
        newSellingItem->next = NULL;
        itemHandler->next = newSellingItem;
	}
}

ItemStruct *HashTable::findItemNode(string name){
    int index = hashSum(name);
    ItemStruct *itemHandler = &hashTable[index];
    while(itemHandler != NULL){
        if(itemHandler->item == name){
            break;
        }
        itemHandler = itemHandler->next;
    }
    return itemHandler;
}

void HashTable::buyItem(string name){
	ItemStruct *itemHandler = findItemNode(name);
	if (itemHandler == NULL){
		cout << "Item not found." << endl;
		return;
	}
	if(itemHandler->location != myLocation){
        cout << "Item is not in your location" << endl;
        return;
	}
    int index = hashSum(name);
    if(hashTable[index].item == name){
        hashTable[index].item = hashTable[index].next->item;
        hashTable[index].price = hashTable[index].next->price;
        hashTable[index].location = hashTable[index].next->location;
        itemHandler = hashTable[index].next;
        hashTable[index].next = hashTable[index].next->next;
    }
    else{
        ItemStruct *itemPrior = &hashTable[index];
        while(itemPrior->next->item != name){
            itemPrior = itemPrior->next;
        }
        itemPrior->next = itemPrior->next->next;
    }
    delete itemHandler;
	return;
}

void HashTable::findItemPrice(string name){

	ItemStruct *itemHandler = findItemNode(name);
	if(itemHandler == NULL){
        cout << "Item not found." << endl;
        return;
	}
    else{
        cout << itemHandler->item << " is being sold for " << itemHandler->price << " dollars in " << itemHandler->location << endl;
    }
	return;
}
