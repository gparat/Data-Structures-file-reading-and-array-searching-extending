// Name        : Book.cpp
// Author      : Giovanni Parati
// Date           : 10/15/2020
// Description : The Book object. Holds Authors, ISBN, Publisher, and title. Can be printed to the console.

#include <iostream>
#include "Book.h"
#include <iostream>
using namespace std;

Book::Book()
{
    title = "None";
    authors = "None";
    publisher="None";
    ISBN="";
}

Book::Book(string t, string i, string a, string p): title(t), ISBN(i), authors(a), publisher(p){}
Book::Book(string i){
    title = "None";
    authors = "None";
    publisher="None";
    ISBN=i;
}

void Book::setTitle(string s){
    title=s;
}
void Book::setAuthors(string s){
    authors=s;
}
void Book::setPublisher(string s){
    publisher=s;
}
void Book::setISBN(string n){
    ISBN=n;
}

string Book::getTitle(){
    return title;
}
string Book::getAuthors(){
    return authors;
}
string Book::getPublisher(){
    return publisher;
}
string Book::getISBN(){
    return ISBN;
}

void Book::print(){
    cout<<title<<endl;
    cout<<"by "<<authors<<endl;
    cout<<ISBN<<endl;
    cout<<publisher<<endl;
    cout<<endl;
}