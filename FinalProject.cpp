#include <iostream>
#include "TylersList.h"
#include <string.h>
#include <vector>

using namespace std;

void displayMenu(){
    cout << "Welcome to Tyler's List! What would you like to do?" << endl;
    cout << "1. Sell Item" << endl;
    cout << "2. Buy Item" << endl;
    cout << "3. Retrieve Item Details" << endl;
    cout << "4. Print List of Items For Sale" << endl;
    cout << "5. Include Items Not in Your Area in Sale List" << endl;
    cout << "6. Quit" << endl;
    return;
}


int main(){
    int input;

    HashTable tylersList;

    bool quit = false;

    string input1;
    string input2;
    string input3 = "Boulder, CO";

    while(quit != true){
        displayMenu();
        cin >> input;

        cin.clear();
        cin.ignore(10000,'\n');

        switch (input){
            case 1:
                cout << "What item would you like to sell? " << endl;
                getline(cin,input1);
                cout << "How much would you like to sell it for? " << endl;
                getline(cin,input2);
                tylersList.sellItem(input1,stoi(input2),input3);
                break;
            case 2:
                cout << "What item would you like to purchase? " << endl;
                getline(cin,input1);
                tylersList.buyItem(input1);
                break;
            case 3:
                cout << "What item would you like to know the price of? " << endl;
                getline(cin,input1);
                tylersList.findItemPrice(input1);
                break;

            case 4:
                tylersList.printItemsForSale();
                break;

            case 5:
                tylersList.sellItem("Used Gear Bike", 290, "Golden, CO");
                tylersList.sellItem("Flatscreen TV, 52 Inch", 900, "Lafayette, CO");
                tylersList.sellItem("Hardwood Dinner Table, 4ft by 7ft", 150, "Golden, CO");
                tylersList.sellItem("Xbox 360, 2 Controllers", 120, "Denver, CO");
                tylersList.sellItem("Comfortable Desk Chair", 85, "Golden, CO");
                tylersList.sellItem("IPhone 5 Unlocked", 99, "Lafayette, CO");

                cout << "Retrieved a list of items being sold outside of your area. " << endl;

            case 6:
                cout << "Thanks for shopping! " << endl;
                quit = true;
                break;

            default:
                cout << "Invalid option, please try again." << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
    return 0;
}
