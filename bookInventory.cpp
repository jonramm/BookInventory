#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <fstream>

using namespace std;

class Book
{
private:
    string title;
    string author;
    string date_published;
public:
    Book();
    Book(string t, string a, string d);
    string getTitle();
    string getAuthor();
    string getDatePublished();
    void setTitle(string t);
    void setAuthor(string a);
    void setDatePublished(string d);
    void printBook();
};

vector<Book*> bookArr;

/*********************************************************************
 * 
 * addBook
 * 
 * Params: None
 * Returns: pointer to Book object
 * 
 * ******************************************************************/

Book* addBook()
{
    string title, author, date_published;
    cin.ignore();
    cout<<"Enter the title:\n";
    getline(cin, title);
    cout<<"Enter the author:\n";
    getline(cin, author);
    cout<<"Enter date published:\n";
    getline(cin, date_published);
    Book* book = new Book(title, author, date_published);
    cout<<endl<<"--Added book--"<<endl;
    book->printBook();
    sleep(2);
    return book;
}

/*********************************************************************
 * 
 * showBooks
 * 
 * Params: None
 * Returns: None
 * 
 * ******************************************************************/

void showBooks()
{
    system("clear");
    cout<<"Books in inventory:"<<endl;
    for (Book* book: bookArr)
    {
        book->printBook();
        cout<<endl;
    }
}

/*********************************************************************
 * 
 * writeBook
 * 
 * Params: Book object
 * Returns: status int
 * 
 * ******************************************************************/

int writeBook(Book* book)
{
    ofstream bookFile;
    bookFile.open("books.txt", ios::app);
    bookFile<<book->getTitle()<<endl;
    bookFile<<book->getAuthor()<<endl;
    bookFile<<book->getDatePublished()<<endl;
    bookFile.close();
    return 0;
}

/*********************************************************************
 * 
 * loadBooks
 * 
 * Params: None
 * Returns: None
 * 
 * ******************************************************************/

void loadBooks()
{
    string title, author, date_published;
    ifstream bookFile;
    bookFile.open("books.txt");
    while (getline(bookFile, title))
    {
        Book* book = new Book();
        getline(bookFile, author);
        getline(bookFile, date_published);
        book->setTitle(title);
        book->setAuthor(author);
        book->setDatePublished(date_published);
        bookArr.push_back(book);
    }
    bookFile.close();
    
}

/*********************************************************************
 * 
 * main
 * 
 * ******************************************************************/

int main()
{
    int choice;
    Book* book;

    loadBooks();
    
    while (1)
    {
        system("clear");
        cout<<"Hello, welcome to your book collection!"<<endl;
        cout<<"What would you like to do?"<<endl<<endl;
        cout<<"1. Add a book."<<endl;
        cout<<"2. Show collection."<<endl;
        cout<<"3. Exit."<<endl<<endl;
        cout<<"Please enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                book = addBook();
                bookArr.push_back(book);
                writeBook(book);
                break;
            case 2:
                showBooks();
                cout<<"Press enter to return to menu"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                exit(0);
        }


    }
    return 0;
}

Book::Book()
{
    title = "";
    author = "";
    date_published = "";
}

Book::Book(string t, string a, string d)
{
    title = t;
    author = a;
    date_published = d;
}
void Book::setTitle(string t)
{
    title = t;
}
void Book::setAuthor(string a)
{
    author = a;
}
void Book::setDatePublished(string d)
{
    date_published = d;
}
string Book::getTitle()
{
    return title;
}
string Book::getAuthor()
{
    return author;
}
string Book::getDatePublished()
{
    return date_published;
}
void Book::printBook()
{
    cout<<"Title: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"Date Published: "<<date_published<<endl;
    cout<<endl;
}