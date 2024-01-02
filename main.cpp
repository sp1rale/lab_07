#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    int year;
    int pageCount;

public:
    explicit Book(const std::string& a, const std::string& t, const std::string& p, int y, int pc)
        : author(a), title(t), publisher(p), year(y), pageCount(pc) {}

    void displayInfo() const {
        cout << "Author: " << author << "\n";
        cout << "Title: " << title << "\n";
        cout << "Publisher: " << publisher << "\n";
        cout << "Year: " << year << "\n";
        cout << "Page Count: " << pageCount << "\n";
    }

    int getYear() const {
        return year;
    }

    string getAuthor() const {
        return author;
    }

    string getPublisher() const {
        return publisher;
    }
};

int main() {
    vector<Book> books = {
        Book("Author1", "Title1", "Publisher1", 2000, 300),
        Book("Author2", "Title2", "Publisher2", 2010, 250),
        Book("Author1", "Title3", "Publisher1", 2015, 400),
        Book("Author3", "Title4", "Publisher3", 2020, 350)
    };

    int choice;
   string searchParam;

    do {
       cout << "Menu:\n"
            << "1. Search by Author\n"
            << "2. Search by Publisher\n"
            << "3. Search by Year\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter author to search: ";
           cin >> searchParam;
            cout << "\nBooks by author " << searchParam << ":\n";
            for (const auto& book : books) {
                if (book.getAuthor() == searchParam) {
                    book.displayInfo();
                    cout << "---------------\n";
                }
            }
            break;

        case 2:
           cout << "Enter publisher to search: ";
           cin >> searchParam;
           cout << "\nBooks by publisher " << searchParam << ":\n";
            for (const auto& book : books) {
                if (book.getPublisher() == searchParam) {
                    book.displayInfo();
                    cout << "---------------\n";
                }
            }
            break;

        case 3:
            int yearToSearch;
            cout << "Enter year to search: ";
            cin >> yearToSearch;
            cout << "\nBooks published after " << yearToSearch << ":\n";
            for (const auto& book : books) {
                if (book.getYear() > yearToSearch) {
                    book.displayInfo();
                    cout << "---------------\n";
                }
            }
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}