#include<iostream>
#include<windows.h>
#include<cstring>
#include<string>
#include<fstream>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <vector>
#include <fstream>
 
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

    // Save book to file (CSV format)
void saveToFile(ofstream& out) const {
    out << bookId << ',' << title << ',' << authorId << ',' << genreId << ','
        << yearPublished << ',' << price << ',' << noOfCopies << '\n';
}

// Load book from a CSV line
static Book fromString(const string& line) {
    Book b;
    stringstream ss(line);
    string temp;

    getline(ss, temp, ',');
    b.bookId = stoi(temp);
    getline(ss, b.title, ',');
    //b.title = stoi(temp);
    getline(ss, temp, ',');
    b.authorId = stoi(temp);
    getline(ss, temp, ',');
    b.genreId = stoi(temp);
    getline(ss, temp, ',');
    b.yearPublished = stoi(temp);
    getline(ss, temp, ',');
    b.price = stof(temp);
    getline(ss, temp, ',');
    b.noOfCopies = stoi(temp);

    return b;
}

};

vector<Book> loadAllBooks() {
    vector<Book> books;
    ifstream file("books.txt");
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            books.push_back(Book::fromString(line));
        }
    }
    return books;
}

void saveAllBooks(const vector<Book>& books) {
    ofstream file("books.txt");
    for (const Book& b : books) {
        b.saveToFile(file);
    }
}


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
    void saveToFile(ofstream& out) const {
    out << userId << "," << name << "," << email << "," << password << "\n";
}

static user fromString(const string& line) {
    user u;
    stringstream ss(line);
    string temp;

    getline(ss, temp, ',');
    u.userId = stoi(temp);
    getline(ss, u.name, ',');
    getline(ss, u.email, ',');
    getline(ss, u.password, ',');

    return u;
}

};
vector<user> loadAllUsers() {
    vector<user> users;
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            users.push_back(user::fromString(line));
        }
    }
    return users;
}

void saveAllUsers(const vector<user>& users) {
    ofstream file("users.txt");
    for (const user& u : users) {
        u.saveToFile(file);
    }
}



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
 Transaction() : transactionId(0), bookId(0), userId(0), issueDate(""), dueDate(""), returnDate(""), fineAmount(0.0f) {}

    // Parameterized constructor
    Transaction(int tid, int bid, int uid, const string& issue, const string& due)
        : transactionId(tid), bookId(bid), userId(uid), issueDate(issue), dueDate(due), returnDate(""), fineAmount(0.0f) {}

    // Create a new transaction
    void createTransaction(int tId, int bId, int uId, const string& issue, const string& due) {
        transactionId = tId;
        bookId = bId;
        userId = uId;
        issueDate = issue;
        dueDate = due;
        returnDate = "";
        fineAmount = 0.0f;
    }

    // Return a book and set return date
    void returnBook(const string& rDate) {
        returnDate = rDate;
        calculateFine(); // Automatically calculate fine on return
    }

    // Fine calculation based on dueDate and returnDate
    void calculateFine() {
    const float finePerDay = 5.0f;

    // Extract year, month, day from dueDate
    int dueY, dueM, dueD;
    sscanf(dueDate.c_str(), "%d-%d-%d", &dueY, &dueM, &dueD);

    int retY, retM, retD;
    sscanf(returnDate.c_str(), "%d-%d-%d", &retY, &retM, &retD);

    // Build tm structs
    tm due = {};
    due.tm_year = dueY - 1900;
    due.tm_mon = dueM - 1;
    due.tm_mday = dueD;

    tm ret = {};
    ret.tm_year = retY - 1900;
    ret.tm_mon = retM - 1;
    ret.tm_mday = retD;

    // Convert to time_t
    time_t dueTime = mktime(&due);
    time_t returnTime = mktime(&ret);

    // Calculate days late
    double seconds = difftime(returnTime, dueTime);
    int daysLate = static_cast<int>(seconds / (60 * 60 * 24));

    fineAmount = (daysLate > 0) ? daysLate * finePerDay : 0.0f;
}


    // Display transaction details
    void display() const {
        cout << "Transaction ID: " << transactionId << ", Book ID: " << bookId
             << ", User ID: " << userId << ", Issue Date: " << issueDate
             << ", Due Date: " << dueDate << ", Return Date: "
             << (returnDate.empty() ? "Not Returned" : returnDate)
             << ", Fine: Rs. " << fineAmount << endl;
    }

    // Getters
    int getTransactionId() const { return transactionId; }
    int getBookId() const { return bookId; }
    int getUserId() const { return userId; }
    string getIssueDate() const { return issueDate; }
    string getDueDate() const { return dueDate; }
    string getReturnDate() const { return returnDate; }
    float getFineAmount() const { return fineAmount; }

   void saveToFile(ofstream& out) const {
    out << transactionId << "," << bookId << "," << userId << ","
        << issueDate << "," << dueDate << "," << returnDate << "," << fineAmount << "\n";
}

static Transaction fromString(const string& line) {
    Transaction t;
    stringstream ss(line);
    string temp;

    getline(ss, temp, ',');
    t.transactionId = stoi(temp);
    getline(ss, temp, ',');
    t.bookId = stoi(temp);
    getline(ss, temp, ',');
    t.userId = stoi(temp);
    getline(ss, t.issueDate, ',');
    getline(ss, t.dueDate, ',');
    getline(ss, t.returnDate, ',');
    getline(ss, temp, ',');
    t.fineAmount = stof(temp);

    return t;
}

};
vector<Transaction> loadAllTransactions() {
    vector<Transaction> transactions;
    ifstream file("transactions.txt");
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            transactions.push_back(Transaction::fromString(line));
        }
    }
    return transactions;
}

void saveAllTransactions(const vector<Transaction>& transactions) {
    ofstream file("transactions.txt");
    for (const Transaction& t : transactions) {
        t.saveToFile(file);
    }
}

int main() {

    vector<Book> books = loadAllBooks(); // Load books from file
    vector<user> users = loadAllUsers();
    vector<Transaction> transactions = loadAllTransactions();
    cout << "--------------------------- All Books ---------------------------\n";
    for (const Book& b : books) {
        b.display();
    }

    /*cout << "\nAdding a new book...\n";
    Book newBook;
    newBook.inputDetails();
    books.push_back(newBook);

    saveAllBooks(books); // Save back to file
    cout << "\nUpdated book list saved.\n";*/
    

    cout << "--------------------------- Users ---------------------------\n";
    for (const user& u : users) {
        u.display();
    }

    cout << "\n--------------------------- Transactions ---------------------------\n";
    for (const Transaction& t : transactions) {
        t.display();
    }
    return 0;
}