#include<iostream>
#include<windows.h>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    int authorId;
    int genreId;
    int yearPublished;
    float price;
    int noOfCopies;

public:
    
    Book() : bookId(0), title(""), authorId(0), genreId(0), yearPublished(0), price(0.0), noOfCopies(0) {}

   
    Book(int id, const string& t, int aId, int gId, int year, float p, int copies)
        : bookId(id), title(t), authorId(aId), genreId(gId),
          yearPublished(year), price(p), noOfCopies(copies) {}

   
    Book(const Book& other)
        : bookId(other.bookId), title(other.title), authorId(other.authorId),
          genreId(other.genreId), yearPublished(other.yearPublished),
          price(other.price), noOfCopies(other.noOfCopies) {}

   
    ~Book() = default;

 
    void inputDetails() {
        cout << "Enter Book ID: ";
        cin >> bookId;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author ID: ";
        cin >> authorId;
        cout << "Enter Genre ID: ";
        cin >> genreId;
        cout << "Enter Year Published: ";
        cin >> yearPublished;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Number of Copies: ";
        cin >> noOfCopies;
    }

    
    void display() const {
        cout << "Book ID: " << bookId << ", Title: " << title
             << ", Author ID: " << authorId << ", Genre ID: " << genreId
             << ", Year Published: " << yearPublished
             << ", Price: $" << price
             << ", Copies Available: " << noOfCopies << endl;
    }

    
    void updateDetails() {
        cout << "Updating details for Book ID " << bookId << "...\n";
        cin.ignore();
        cout << "Enter new title: ";
        getline(cin, title);
        cout << "Enter new author ID: ";
        cin >> authorId;
        cout << "Enter new genre ID: ";
        cin >> genreId;
        cout << "Enter new year published: ";
        cin >> yearPublished;
        cout << "Enter new price: ";
        cin >> price;
        cout << "Enter new number of copies: ";
        cin >> noOfCopies;
    }

    // Issue a copy (decrement)
    void issueCopy() {
        if (noOfCopies > 0)
            noOfCopies--;
        else
            cout << "No copies available to issue.\n";
    }

    // Return a copy (increment)
    void returnCopy() {
        noOfCopies++;
    }

    // Check availability
    bool isAvailable() const {
        return noOfCopies > 0;
    }

    // Getters
    int getBookId() const { return bookId; }
    string getTitle() const { return title; }
    int getAuthorId() const { return authorId; }
    int getGenreId() const { return genreId; }
    int getYearPublished() const { return yearPublished; }
    float getPrice() const { return price; }
    int getNoOfCopies() const { return noOfCopies; }

    // Setters
    void setBookId(int id) { bookId = id; }
    void setTitle(const string& t) { title = t; }
    void setAuthorId(int id) { authorId = id; }
    void setGenreId(int id) { genreId = id; }
    void setYearPublished(int year) { yearPublished = year; }
    void setPrice(float p) { price = p; }
    void setNoOfCopies(int n) { noOfCopies = n; }

    // Operator overload for comparing books by ID
    bool operator==(const Book& other) const {
        return bookId == other.bookId;
    }

    // Optional: Return book info as string (for file I/O or debug)
    string toString() const {
        return to_string(bookId) + "," + title + "," +
               to_string(authorId) + "," + to_string(genreId) + "," +
               to_string(yearPublished) + "," + to_string(price) + "," +
               to_string(noOfCopies);
    }
};

class user{
    private:
    int userId;
    string name;
    string email;
    string password;
    public:
    user() : userId(0), name(""), email(""), password("") {}
    user(int id, const string& n, const string& e, const string& p)
        : userId(id), name(n), email(e), password(p) {}
    void display() const {
        cout << "User ID: " << userId << ", Name: " << name << ", Email: " << email << endl;
    }
    void inputDetails() {
        cout << "Enter User ID: ";
        cin >> userId;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Password: ";
        getline(cin, password);
    }

};

class Transaction {
private:
    int transactionId;
    int bookId;
    int userId;
    string issueDate;
    string dueDate;
    string returnDate;
    float fineAmount;
public:
    void createTransaction(int bookId, int userId);
    void returnBook(string returnDate);
    void calculateFine(); // logic based on dueDate and returnDate
    void displayTransaction() const {
        cout << "Transaction ID: " << transactionId
             << ", Book ID: " << bookId
             << ", User ID: " << userId
             << ", Issue Date: " << issueDate
             << ", Due Date: " << dueDate
             << ", Return Date: " << returnDate
             << ", Fine Amount: $" << fineAmount << endl;
    }
    
};
 

int main() {

}