#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//enumerator to hold possible genres
enum Genre {
    Fiction,
    NonFiction,
    Periodical,
    Biography,
    Children
};

//Define the class Book
class Book {
private:
    string ISBN;
    string title;
    string author;
    int copyrightDate;
    bool checkedOut;
    Genre genre;

public:
    // Constructors
    Book(const string& isbn, const string& title, const string& author, int copyrightDate, Genre genre)
        : ISBN(isbn), title(title), author(author), copyrightDate(copyrightDate), checkedOut(false), genre(genre) {}

    // Getter functions
    string getISBN() const { return ISBN; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getCopyrightDate() const { return copyrightDate; }
    bool isCheckedOut() const { return checkedOut; }
    Genre getGenre() const { return genre; }

    // Check out a book
    void checkOut() { checkedOut = true; }

    // Check in a book
    void checkIn() { checkedOut = false; }

     // Overload the == operator
    bool operator==(const Book& other) const {
        return ISBN == other.ISBN;
    }

    // Overload the != operator
    bool operator!=(const Book& other) const {
        return !(*this == other);
    }

    // Overload the << operator for output
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Title: " << book.title << "\nAuthor: " << book.author << "\nISBN: " << book.ISBN << "\nGenre: ";
        switch (book.getGenre()) {
        case Fiction: os << "Fiction"; break;
        case NonFiction: os << "Non-Fiction"; break;
        case Periodical: os << "Periodical"; break;
        case Biography: os << "Biography"; break;
        case Children: os << "Children"; break;
        default: os <<"Invalid genre";
    };
        return os;
    }
};

//Define the class Patron
class Patron {
    private://private attributes
        string userNname;
        string cardNumber;
        int ownedFees;
    public:
        //constructor
        Patron(string u, string c, int f) : userNname(u), cardNumber(c), ownedFees(f) {}
        
        //getter functions
        string getUserName() {return userNname;}
        string getCardNumber() {return cardNumber;}
        int getOwnedFees() {return ownedFees;}

        //owesFees figures out if the patron owes fees
        bool owesFees() {
            if(ownedFees > 0) {return true;}
            else{return false;}
        }

        //setFees sets fees for the patron
        void setFees(int f) {
            if(f >= 0) {
                ownedFees = f;
            }
        }
        //Overloading the == operator to be able to compare patron objects
        bool operator==(const Patron& other) const {
            return cardNumber == other.cardNumber;
        }
};

class Transaction {
    private://private attributes
        Book book;
        Patron patron;
        string activity;
        string date;
    public:
        //constructor
        Transaction(Book& b, Patron& p, string a, string d) : book(b), patron(p), activity(a), date(d) {}

};
// Defining the Libary class
class Library {
    private://private attributes
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> transactions;
        vector<Patron> debtors;
    public:
        //Definition of the addBook() function
        void addBook(Book& book) {
            books.push_back(book);
        }
        //Definition of the addPatron() function
        void addPatron(Patron& p) {
            patrons.push_back(p);
        }

        //debtorsFinder() finds debtor patrons in the patrons vector
        vector<Patron> debtorsFinder() {
            for(auto i : patrons) {
                if(i.getOwnedFees() > 0) {
                    debtors.push_back(i);
                }
            }
            return debtors;
        }
        
        //CheckOut function allows to check out books if patron is registered and owes no fees
        void checkOut(Patron& patron, Book& book, string activity, string date) {
            debtorsFinder();// find debtors

            auto bookIter = find(books.begin(), books.end(), book);
            auto patronIter = find(patrons.begin(), patrons.end(), patron);

            //Is patron and book registered?
            if(patronIter == patrons.end() || bookIter == books.end()) {
                cout<<"Error the user or the book is not registered."<<endl;
            }else if(find(debtors.begin(), debtors.end(), patron) != debtors.end()) { //Does debtor owe fees?
                cout<<"The user owes fees."<<endl;
            }else {//Otherwise record the transaction.
                Transaction tran1(book, patron, activity, date);
                transactions.push_back(tran1);
                cout<<"Activity recorded"<<endl;
            }
        }
        
};

int main() {
    //Testing Code...
    Book book1("978-0-12-345678-9", "Sample Book 1", "Author 1", 2023, Fiction);
    Book book2("978-9-87-654321-0", "Sample Book 2", "Author 2", 2022, Biography);
    Patron person1("Furaha", "0283928", 0);
    Library tran;

    tran.addBook(book1);
    tran.addBook(book2);
    tran.addPatron(person1);
    tran.checkOut(person1, book1, "checkOut", "0/0/2023");

    cout << "Book 1:\n" << book1 <<endl<<endl;
    cout << "Book 2:\n" << book2 <<endl<<endl;

    if (book1 == book2) {
        cout << "Book 1 and Book 2 have the same ISBN." <<endl;
    } else {
        cout << "Book 1 and Book 2 have different ISBNs." <<endl;
    }

    return 0;
}
