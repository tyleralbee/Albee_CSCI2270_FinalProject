#include <iostream>
#include "TylersList.h"
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){
    int input;
    HashTable tylersList(10);
    bool quit = false;

    string input1;
    string input2;
    string input3 = "Boulder, CO";

    while(quit != true){
        tylersList.displayMenu();
        cin >> input;

        cin.clear();
        cin.ignore(10000,'\n');

        switch (input){
            case 1:
                cout << "What item would you like to sell? " << endl;
                getline(cin,input1);
                cout << "How much would you like to sell it for? " << endl;
                getline(cin,input2);
                tylersList.sellItem(input1,atoi(input2.c_str()),input3);
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
                cout << "Set location: ";
                getline(cin,input3);
                tylersList.setLocation(input3);
            case 6:
                tylersList.sellItem("Used Gear Bike", 290, "Golden, CO");
                tylersList.sellItem("Flatscreen TV, 52 Inch", 900, "Lafayette, CO");
                tylersList.sellItem("Hardwood Dinner Table, 4ft by 7ft", 150, "Golden, CO");
                tylersList.sellItem("Xbox 360, 2 Controllers", 120, "Denver, CO");
                tylersList.sellItem("Comfortable Desk Chair", 85, "Golden, CO");
                tylersList.sellItem("IPhone 5 Unlocked", 99, "Lafayette, CO");
                cout << "Retrieved a list of items being sold outside of your area. " << endl;
                break;
            case 7:
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
