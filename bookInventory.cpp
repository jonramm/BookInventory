#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
    string title;
    string author;
    string date_published;
public:
    Book(string t, string a, string d);
    string getTitle();
    string getAuthor();
    string getDatePublished();
    void setTitle(string t);
    void setAuthor(string a);
    void setDatePublished(string d);
    void printBook();
};

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
    book->printBook();
    return book;
}

/*********************************************************************
 * 
 * main
 * 
 * ******************************************************************/

int main()
{
    int choice;
    vector<Book*> bookArr;

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
                bookArr.push_back(addBook());
                break;
            case 2:
                cout<<"Books in inventory:"<<endl;
                for (Book* book: bookArr)
                {
                    cout<<book->getTitle()<<endl;
                }
                break;
            case 3:
                exit(0);
        }


    }
    return 0;
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