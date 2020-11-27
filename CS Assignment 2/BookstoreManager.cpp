// Name        : BookstoreManager.cpp
// Author      : Giovanni Parati
// Date           : 10/15/2020
// Description : The BookstoreManager object. Holds an array of books, the number of books in the array, amd the size of the array.
//New books can be inserted and are automatically sorted. Books can be searched for by ISBN, and removed by ISBN or publisher.
//The whole array can be printed to the console. Has methods that return true/false based on wether the array is full/empty,
//or return the number of books in the array.

#include <string>
#include <iostream>
#include "Book.h"
#include "BookstoreManager.h"
using namespace std;

BookstoreManager::BookstoreManager(){
    array=new Book[2];
    size=2;
    items=0;
}

BookstoreManager::BookstoreManager(Book* a, int s){
    array=a;
    size=s;
    items=0;
}

BookstoreManager::~BookstoreManager(){
    delete[] array;
}

bool BookstoreManager::isFull(){
    if(items==size){
        cout<<"BookstoreManager.isFull()==true"<<endl;
        return true;
    }
    cout<<"BookstoreManager.isFull()==false"<<endl;
    return false;
}
bool BookstoreManager::isEmpty(){
    if(items==0){
        cout<<"BookstoreManager.isEmpty()==true"<<endl;
        return true;
    }
    cout<<"BookstoreManager.isEmpty()==false"<<endl;
    return false;
}

//returns # of books in array
int BookstoreManager::listSize(){
    cout<<items<<endl;
    return items;
}

//prints the whole array
void BookstoreManager::print(){
    for(int i = 0; i<items; i++){
        array[i].print();
    }
}

//binary search by ISBN, prints the searched book or Not Found if the book isnt there
void BookstoreManager::search(Book b){
    string n = b.getISBN();
    bool found=false;
    int last=items-1;
    int first=0;
    int pos=(last+first)/2;
    while(last-first>1&&!found){
        //cout<<last-first<<endl;
        if(array[pos].getISBN().compare(n)>0){
            last=pos;
            pos=(last+first)/2;
        }
        else if(array[pos].getISBN().compare(n)<0){
            first=pos;
            pos=(last+first)/2;
        }
        else{
            found=true;
        }
    }
    if(found){
        array[pos].print();
    }
    else if(last-first<=1){
        //cout<<last<<" "<<first<<endl;
        if(array[last].getISBN().compare(n)==0){
            array[last].print();
        }
        else if(array[first].getISBN().compare(n)==0){
            array[first].print();
        }
        else{
            cout<<"Not Found"<<endl;
        }
    }
    else{
        cout<<"Not Found"<<endl;
    }
}

//double the length of the array
void BookstoreManager::extend(){
    Book *temp=new Book[size*2];
    for(int i=0; i<size; i++){
        temp[i]=array[i];
    }
    delete[] array;
    array=temp;
    size*=2;
}

//insert a book at an index determined by its ISBN
void BookstoreManager::insert(Book b){
    bool done=false;
    int pos=0;
    string num=b.getISBN();

    if(items+1>=size){
        extend();
    }
    while(pos<items&&!done){
        if(num<=array[pos].getISBN()){
            done=true;
            pos--;
        }
        pos++;
    }
    items++;
    if(!done){
        array[items-1]=b;
    }
    else{
        for(int i=items; i>pos; i--){
            array[i]=array[i-1];
        }
        array[pos]=b;
    }
}

//remove a book by ISBN, or print Not Found if no matching ISBN
void BookstoreManager::remove(Book b){
    bool found=false;
    int pos=0;
    string num=b.getISBN();
    int apos=0;
    int napos=0;

    while(apos<items){
        if(array[apos].getISBN().compare(num)!=0){
            array[napos]=array[apos];
            napos++;
            found=true;
        }
        apos++;
    }

    if(!found){
        cout<<"Not Found"<<endl;
    }
    else{
        items--;
    }
}

//remove one or more boks by publisher, or print Not Found if no matching publisher
void BookstoreManager::removePublisher(string s){
    bool found=false;
    int idec=0;//# of deleted items
    int apos=0;//source index
    int napos=0;//destination index

    while(apos<items){
        if(array[apos].getPublisher().compare(s)!=0){
            array[napos]=array[apos];
            napos++;
        }
        else{
            idec++;
            found=true;
        }
        apos++;
    }

    if(!found){
        cout<<"Not Found"<<endl;
    }
    else{
        //reduce count of items in list
        items-=idec;
    }
}