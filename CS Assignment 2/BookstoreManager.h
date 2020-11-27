// Name        : BookstoreManager.h
// Author      : Giovanni Parati
// Date           : 10/15/2020
// Description : H file for the BookstoreManager object.

#include <string>
using namespace std;
//#include "Book.h"

class BookstoreManager{
private:
    Book* array;
    int size;
    int items;
public:
    BookstoreManager();
    BookstoreManager(Book* a, int s);
    ~BookstoreManager();

    bool isEmpty();
    bool isFull();
    int listSize();
    void print();
    void insert(Book b);
    void remove(Book b);
    void removePublisher(string s);
    void search(Book b);
    void extend();
};