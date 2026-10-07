#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LibraryItem
{
public:
    virtual void display() = 0;
    virtual string getName() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p)
    {
        title = t;
        author = a;
        pages = p;
    }

    void display() override
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }

    string getName() override
    {
        return title;
    }

    string getTitle()
    {
        return title;
    }

    int getPages()
    {
        return pages;
    }
};

class Newspaper : public LibraryItem
{
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n, string d, string e)
    {
        name = n;
        date = d;
        edition = e;
    }

    void display() override
    {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }

    string getName() override
    {
        return name;
    }

    string getNewspaperName()
    {
        return name;
    }

    string getEdition()
    {
        return edition;
    }
};

template <class T>
T* linearSearch(vector<T>& arr, string key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].getName() == key)
        {
            return &arr[i];
        }
    }

    return nullptr;
}

template <class T>
T* binarySearch(vector<T>& arr, string key)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid].getName() == key)
        {
            return &arr[mid];
        }
        else if (arr[mid].getName() < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return nullptr;
}

class Library
{
private:
    vector<Book> books;
    vector<Newspaper> newspapers;

public:
    void addBook(Book book)
    {
        books.push_back(book);
    }

    void addNewspaper(Newspaper newspaper)
    {
        newspapers.push_back(newspaper);
    }

    void displayCollection()
    {
        cout << "\n--- Books ---\n";

        for (int i = 0; i < books.size(); i++)
        {
            books[i].display();
            cout << endl;
        }

        cout << "--- Newspapers ---\n";

        for (int i = 0; i < newspapers.size(); i++)
        {
            newspapers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages()
    {
        for (int i = 0; i < books.size() - 1; i++)
        {
            for (int j = 0; j < books.size() - i - 1; j++)
            {
                if (books[j].getPages() > books[j + 1].getPages())
                {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition()
    {
        for (int i = 0; i < newspapers.size() - 1; i++)
        {
            for (int j = 0; j < newspapers.size() - i - 1; j++)
            {
                if (newspapers[j].getEdition() >
                    newspapers[j + 1].getEdition())
                {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title)
    {
        return linearSearch(books, title);
    }

    Newspaper* searchNewspaperByName(string name)
    {
        for (int i = 0; i < newspapers.size() - 1; i++)
        {
            for (int j = 0; j < newspapers.size() - i - 1; j++)
            {
                if (newspapers[j].getName() >
                    newspapers[j + 1].getName())
                {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }

        return binarySearch(newspapers, name);
    }
};

int main()
{
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13",
        "Morning Edition");

    Newspaper newspaper2("The Times", "2024-10-12",
        "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook =
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook)
    {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else
    {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper)
    {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else
    {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}