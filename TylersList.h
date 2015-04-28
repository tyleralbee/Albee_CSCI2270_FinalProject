#ifndef TYLERSLIST_H
#define TYLERSLIST_H

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
    }

};

class HashTable{
    public:
        HashTable(int);
        ~HashTable();
        void sellItem(std::string in_item, int, std::string);
        ItemStruct* findItemPrice(std::string in_item);
        void buyItem(std::string in_item);
        void printItemsForSale();
    protected:
    private:
        ItemStruct *hashTable;
};

#endif // TYLERSLIST_H
