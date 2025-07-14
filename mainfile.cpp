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
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // get handle here
    SetConsoleTextAttribute(h, 11); // Bright Cyan for headings
        cout << "Book ID: " << bookId << ", Title: " << title
             << ", Author ID: " << authorId << ", Genre ID: " << genreId
             << ", Year Published: " << yearPublished
             << ", Price: $" << price
             << ", Copies Available: " << noOfCopies << endl<<endl;

             SetConsoleTextAttribute(h, 7); // Reset
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
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 9); // Aqua
        cout << "User ID: " << userId << ", Name: " << name << ", Email: " << email << endl<<endl;
        SetConsoleTextAttribute(h, 7); // Reset
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
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 3); // Aqua
        cout << "Transaction ID: " << transactionId << ", Book ID: " << bookId
             << ", User ID: " << userId << ", Issue Date: " << issueDate
             << ", Due Date: " << dueDate << ", Return Date: "
             << (returnDate.empty() ? "Not Returned" : returnDate)
             << ", Fine: Rs. " << fineAmount << endl<<endl;
            SetConsoleTextAttribute(h, 7); // Reset
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
    vector<Book> books = loadAllBooks();
    vector<user> users = loadAllUsers();
    vector<Transaction> transactions = loadAllTransactions();

    int choice;

    do {
        cout << "\n========== Library Menu ==========\n";
        cout << "1. View All Books\n";
        cout << "2. Add New Book\n";
        cout << "3. View All Users\n";
        cout << "4. Add New User\n";
        cout << "5. View All Transactions\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n--- Book List ---\n";
                for (const Book& b : books) {
                    b.display();
                }
                break;
            }
            case 2: {
                Book newBook;
                newBook.inputDetails();
                books.push_back(newBook);
                saveAllBooks(books);
                cout << "Book added and saved.\n";
                break;
            }
            case 3: {
                cout << "\n--- User List ---\n";
                for (const user& u : users) {
                    u.display();
                }
                break;
            }
            case 4: {
                user newUser;
                newUser.inputDetails();
                users.push_back(newUser);
                saveAllUsers(users);
                cout << "User added and saved.\n";
                break;
            }
            case 5: {
                cout << "\n--- Transactions ---\n";
                for (const Transaction& t : transactions) {
                    t.display();
                }
                break;
            }
            case 6: { // Issue book
                int tid, bid, uid;
                string issueDate, dueDate;
                cout << "Enter Transaction ID: ";
                cin >> tid;
                cout << "Enter Book ID to issue: ";
                cin >> bid;
                cout << "Enter User ID: ";
                cin >> uid;
                cout << "Enter Issue Date (yyyy-mm-dd): ";
                cin >> issueDate;
                cout << "Enter Due Date (yyyy-mm-dd): ";
                cin >> dueDate;

                bool found = false;
                for (Book& b : books) {
                    if (b.getBookId() == bid) {
                        if (b.isAvailable()) {
                            b.issueCopy();
                            transactions.emplace_back(tid, bid, uid, issueDate, dueDate);
                            saveAllBooks(books);
                            saveAllTransactions(transactions);
                            cout << "Book issued successfully.\n";
                        } else {
                            cout << "No copies available.\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Book not found.\n";
                break;
            }
            case 7: { // Return book
                int tid;
                string returnDate;
                cout << "Enter Transaction ID to return: ";
                cin >> tid;
                cout << "Enter Return Date (yyyy-mm-dd): ";
                cin >> returnDate;

                bool found = false;
                for (Transaction& t : transactions) {
                    if (t.getTransactionId() == tid && t.getReturnDate().empty()) {
                        t.returnBook(returnDate);

                        // Increment the book's copy count
                        for (Book& b : books) {
                            if (b.getBookId() == t.getBookId()) {
                                b.returnCopy();
                                break;
                            }
                        }

                        saveAllBooks(books);
                        saveAllTransactions(transactions);
                        cout << "Book returned. Fine: Rs. " << t.getFineAmount() << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Transaction not found or already returned.\n";
                break;
            }
            case 0: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Try again.\n";
        }

        system("pause");
        system("cls");
    } while (choice != 0);

    return 0;
}
