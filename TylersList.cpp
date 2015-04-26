#include "/home/user/Desktop/Assignment9P/include/HashTable.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

HashTable::HashTable()
{
    for(int i = 0; i < tableSize; i++){
        hashTable[i] = new Movie;
        hashTable[i]->title = "empty";
        hashTable[i]->year = 0;
        hashTable[i]->next = NULL;
    }
}

HashTable::~HashTable()
{
    //dtor
}



int HashTable::hash(string x){ //x is the string to hash, s is the array size
    int hash = 0;
    int index;

    for(int i = 0; i < x.length(); i++){
        hash = hash + (int)x[i];  //ascii value of ith character in the string
    }

    index = hash % tableSize;

    return index;
}

void HashTable::insertMovie(std::string in_title, std::string in_year){
    int index = hash(in_title);
    int intYear = atoi(in_year.c_str());

    if(hashTable[index]->title == "empty"){
        hashTable[index]->title = in_title;
        hashTable[index]->year = intYear;
        //cout<<"d"<<endl;
    }
    else{
        Movie* ptr = hashTable[index];
        Movie* n = new Movie;
        n->title = in_title;
        n->year = int(intYear);
        n->next = NULL;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

int HashTable::numberOfItems(int index){
    int count = 0;

    if(hashTable[index]->title == "empty"){
        return count;
    }
    else{
        count++;
        Movie* ptr = hashTable[index];
        while(ptr->next != NULL){
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void HashTable::printInventory(){
    int number;
    for(int i = 0; i < tableSize; i++){
        number = numberOfItems(i);
        cout << hashTable[i]->title << ":" << hashTable[i]->year << endl;
        }
    }

void HashTable::FindMovie(string in_title){
    bool foundName = false;
    Movie* movie;

    Movie* ptr2 = hashTable[*index];
    while(ptr2 != NULL){
        if(ptr2->title == in_title){
            foundName = true;
            movie->title = ptr2->title;
        }
        ptr2 = ptr2->next;
    }
    if(foundName){
        cout << hash(movie->title) << ":" << movie->title << ":" << movie->year << endl;
    }
    else{
        cout << "not found" << endl;
    }
}

void HashTable::deleteMovie(string in_title){
    int index = hash(in_title);

    Movie* delPtr;
    Movie* P1;
    Movie* P2;

    if(hashTable[index]->title == "empty" && hashTable[index]->year == 0){
        cout << "not found" << endl;
    }

    else if(hashTable[index]->title == in_title && hashTable[index]->next == NULL){
        hashTable[index]->title = "empty";
        hashTable[index]->year = 0;
    }
    else if(hashTable[index]->title == in_title){
        delPtr = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        delete delPtr;
    }
    else{
        P1 = hashTable[index]->next;
        P2 = hashTable[index];

        while(P1 != NULL && P1->title != in_title){
            P2 = P1;
            P1 = P1->next;
        }
        if(P1 == NULL){
            cout << "not found" << endl;
        }
        else{
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;

            delete delPtr;
        }
    }
}

