#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>

struct Movie{
    std::string title;
    int year;
    Movie *next;

    Movie(){};

    Movie(std::string in_title, int in_year)
    {
        title = in_title;
        year = in_year;
    }

};

class HashTable
{
    private:
        static const int tableSize = 10;
        Movie *hashTable[tableSize];
    public:
        HashTable();
        ~HashTable();
        int hash(std::string x);
        int numberOfItems(int index);
        void insertMovie(std::string, std::string);
        void FindMovie(std::string in_title);
        void deleteMovie(std::string in_title);
        void printInventory();
    protected:

};

#endif // HASHTABLE_H
