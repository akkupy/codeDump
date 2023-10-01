#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class books
{
public:
    struct details
    {
        string title;
        string author;
        string publisher;
        int price;
        int stockpos;
    };

    vector<details> *library;

    books()
    {
        library = new vector<details>;
        library->push_back({"To Kill a Mockingbird", "Harper Lee", "HarperCollins Publishers", 654, 15});
        library->push_back({"1984", "George Orwell", "Secker & Warburg", 329, 15});
        library->push_back({"The Lord of the Rings", "J.R.R. Tolkien", "Houghton Mifflin", 713, 14});
        library->push_back({"The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", 407, 14});
        library->push_back({"The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", 419, 13});
        library->push_back({"The Lion, the Witch and the Wardrobe", "C.S. Lewis", "Geoffrey Bles", 979, 13});
        library->push_back({"Lord of the Flies", "William Golding", "Faber and Faber", 971, 12});
        library->push_back({"Animal Farm", "George Orwell", "Simon & Schuster", 299, 12});
        library->push_back({"Catch-22", "Joseph Heller", "Simon & Schuster", 997, 11});
        library->push_back({"The Grapes of Wrath", "John Steinbeck", "The Viking Press-James Lloyd", 852, 11});

    }


    void display(int i)
    {
        cout << "\nTitle: " << (*library)[i].title << endl;
        cout << "Author: " << (*library)[i].author << endl;
        cout << "Publisher: " << (*library)[i].publisher << endl;
        cout << "Price: Rs. " << (*library)[i].price << endl;
        cout << "Stock Position: " << (*library)[i].stockpos << endl;
    }

    int search(string a, string b)
    {
        string lowtitle, lowauthor;
        for (int i = 0; i < library->size(); i++)
        {
            lowtitle = (*library)[i].title;
            lowauthor = (*library)[i].author;
            transform(lowtitle.begin(), lowtitle.end(), lowtitle.begin(), ::tolower);
            transform(lowauthor.begin(), lowauthor.end(), lowauthor.begin(), ::tolower);
            if (lowtitle == a && lowauthor == b)
            {
                cout << "\nTitle Found.\n";
                return i;
            }
        }
        cout << "\nTitle Not Found.\n" << endl;
        return -1;
    }
    ~books()
    {
        delete library;
    }
};

class LibraryWithNewBook : public books
{
public:
    void newbook(string a, string b, string c, int x, int y)
    {
        library->push_back({a, b, c, x, y});
    }
};

int main()
{
    int choice, nos;
    LibraryWithNewBook *Searched = new LibraryWithNewBook();

    string title, author;

    while (true)
    {
        cout << "\n***Welcome to Tasdeeque's Library***" << endl;
        cout << "\n1. Search for a Book. (Case Insensitive)" << endl;
        cout << "2. Add a New Book." << endl;
        cout << "3. Display All Books Available." << endl;
        cout << "4. Exit." << endl;
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
            {
                cout << "\nEnter the Title of The Book: ";
                getline(cin, title);
                transform(title.begin(), title.end(), title.begin(), ::tolower);
                cout << "Name of The Author: ";
                getline(cin, author);
                transform(author.begin(), author.end(), author.begin(), ::tolower);
                int i = Searched->search(title, author);
                if (i != -1)
                {
                    Searched->display(i);
                }
                else
                {
                    break;
                }
                cout << "\nEnter the Number of Required Copies: ";
                cin >> nos;
                if (nos <= (*Searched->library)[i].stockpos)
                {
                    cout << "\nTotal Payable Amount: Rs " << nos * (*Searched->library)[i].price << endl;
                    char a;
                    cout << "\nAmount Paid (Yes-y Or No-n): ";
                    cin >> a;
                    if (a == 'y' || a == 'Y')
                    {
                        (*Searched->library)[i].stockpos -= nos;
                        cout << "\nAmount of Copies Left of \"" << (*Searched->library)[i].title << "\": " << (*Searched->library)[i].stockpos << endl;
                    }
                    else if (a == 'n' || a == 'N')
                    {
                        cout << "\nAmount of Copies Left of " << (*Searched->library)[i].title << ": " << (*Searched->library)[i].stockpos << endl;
                    }
                    else
                    {
                        cout << "\nInvalid. Try Again.\n" << endl;
                    }
                }
                else
                {
                    cout << "\nRequired copies not in stock. Available Stock: " << (*Searched->library)[i].stockpos << endl;
                }
                break;
            }
            case 2:
            {
                string a, b, c;
                int x, y;
                cout << "\nEnter Title of the Book: ";
                getline(cin, a);
                cout << "Enter Name of the Author: ";
                getline(cin, b);
                cout << "Enter Publisher of the Book: ";
                getline(cin, c);
                cout << "Enter Price of the Book: Rs. ";
                cin >> x;
                cout << "Enter Stock Position of the Book: ";
                cin >> y;

                Searched->newbook(a, b, c, x, y);
                break;
            }
            case 3:
            {
                cout << "\nList of all books in the library:" << endl;
                for (int i = 0; i < Searched->library->size(); i++)
                {
                    Searched->display(i);
                    cout << "\n***********************" << endl;
                }
                break;
            }
            case 4:
            {
                cout << "\nGoodbye User! See you soon.\n" << endl;
                delete Searched;
                return 0;
            }
            default:
            {
                cout << "\nInvalid Choice. Try Again." << endl;
                break;
            }
        }
    }
}
