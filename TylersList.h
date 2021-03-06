#ifndef TYLERSLIST_H
#define TYLERSLIST_H
#include <vector>
#include <string>

struct ItemStruct{
    std::string item;
    std::string location;
    int price;
    ItemStruct *next;

    ItemStruct(){};

    ItemStruct(std::string in_item, int in_price, std::string in_location){
        item = in_item;
        price = in_price;
        location = in_location;
        next = NULL;
    }

};

class HashTable{
    private:
        int tableSize;
        ItemStruct *hashTable;
        string myLocation;
    public:
        HashTable(int);
        ~HashTable();
        void sellItem(std::string, int, std::string);
        void buyItem(std::string);
        void printItemsForSale();
        void findItemPrice(std::string);
        int hashSum(std::string);
        void displayMenu();
        ItemStruct *findItemNode(std::string);
        void setLocation(string);
    protected:
};

#endif // TYLERSLIST_H
