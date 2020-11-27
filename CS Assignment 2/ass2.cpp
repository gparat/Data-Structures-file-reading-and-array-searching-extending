// Name        : main.cpp
// Author      : Provided by Professor Li, modified by Giovanni Parati by changing some cin to getline, and some other minor edits
// Date           : 10/15/2020
// Description : Test main method.

#include <iostream>
#include "Book.h"
#include "BookstoreManager.h"

using namespace std;

int main() { 
    BookstoreManager bookstoreManager;

    //prints true if the bookstore is empty
    bookstoreManager.isEmpty();

    //insert 4 books
    string title, authors, isbn, publisher;
    for(int i=0;i<4;i++){
        cout<<"Enter book title: ";
        getline (cin,title);
        cout<<"Enter authors: ";
        getline (cin,authors);
        cout<<"Enter ISBN: "; 
        getline (cin,isbn);
        cout<<"Enter publisher: ";
        getline (cin,publisher);
        Book aBook(title, isbn, authors, publisher);
        bookstoreManager.insert(aBook); 
        cout<<endl;
    }

    //print bookstore
    bookstoreManager.print();

    //search for books
    cout<<"Searching…"<<endl;
    cout<<"ISBN:";
    cin>>isbn;
    Book b2(isbn);
    bookstoreManager.search(b2);

    //remove a book
    cout<<"Removing…"<<endl;
    cout<<"ISBN:";
    cin>>isbn;
    Book b1(isbn);
    bookstoreManager.remove(b1);
    cout<<endl;

    //print bookstore
    bookstoreManager.print();

    //remove books from a particular publisher
    cout<<"Removing all books for a publisher"<<endl;
    cout<<"Publisher:";
    cin>>publisher; 
    bookstoreManager.removePublisher(publisher);
    cout<<endl;

    //print bookstore
    bookstoreManager.print();


    //prints the number of books 
    bookstoreManager.listSize();

}