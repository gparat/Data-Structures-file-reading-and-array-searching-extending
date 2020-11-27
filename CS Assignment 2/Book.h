// Name        : Book.h
// Author      : Giovanni Parati
// Date           : 10/15/2020
// Description : H file for the Book object.

#include <string>
using namespace std;

class Book{
    private:
    string title;
    string authors;
    string publisher;
    string ISBN;
public:
    Book();
    Book(string t, string i, string a, string p);
    Book(string i);

    void setTitle(string s);
    void setAuthors(string s);
    void setPublisher(string s);
    void setISBN(string i);

    string getTitle();
    string getAuthors();
    string getPublisher();
    string getISBN();

    void print();
};