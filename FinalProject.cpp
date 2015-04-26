#include <iostream>
#include "/home/user/Desktop/Assignment9P/include/HashTable.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

void displayMenu(){
    cout << "======Main Menu======" << endl;
    cout << "1. Insert movie" << endl;
    cout << "2. Delete movie" << endl;
    cout << "3. Find movie" << endl;
    cout << "4. Print table contents" << endl;
    cout << "5. Quit" << endl;
    return;
}

int main()
{
    int those = 0;
    int input = NULL;
    bool quit = false;
    string inputTitle, inputYear;
    HashTable Hasher;
    Movie* found;

    while(quit != true){
        displayMenu();
        cin >> input;
        cin.clear();
        cin.ignore(10000,'\n');
        switch (input){
            case 1:
                cout << "Enter title:" << endl;
                getline(cin, inputTitle);
                cout << "Enter year:" << endl;
                getline(cin, inputYear);
                Hasher.insertMovie(inputTitle, inputYear);
                break;
            case 2:
                cout << "Enter title:" << endl;
                getline(cin,inputTitle);
                Hasher.deleteMovie(inputTitle);
                break;
            case 3:
                cout << "Enter title:" << endl;
                getline(cin,inputTitle);
                Hasher.FindMovie(inputTitle);
                break;
            case 4:
                Hasher.printInventory();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
}
