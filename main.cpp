#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Worker {
private:
   string fullName;
   string position;
    int startYear;
    double salary;

public:
    explicit Worker(const std::string& name, const std::string& pos, int year, double sal)
        : fullName(name), position(pos), startYear(year), salary(sal) {}

    void displayInfo() const {
        cout << "Full Name: " << fullName << "\n";
        cout << "Position: " << position << "\n";
        cout << "Start Year: " << startYear << "\n";
        cout << "Salary: " << salary << "\n";
    }

    int getExperience(int currentYear) const {
        return currentYear - startYear;
    }

    double getSalary() const {
        return salary;
    }

    string getPosition() const {
        return position;
    }
};

int main() {
     vector<Worker> workers = {
        Worker("John Doe", "Manager", 2010, 50000),
        Worker("Jane Smith", "Developer", 2015, 60000),
        Worker("Alice Johnson", "Accountant", 2012, 55000),
        Worker("Bob Brown", "Manager", 2018, 70000)
    };

    int choice;
    string searchParam;
    int yearsExperience;
    double salaryLimit;

    do {
        cout << "Menu:\n"
            << "1. Search by Experience\n"
            << "2. Search by Salary\n"
            << "3. Search by Position\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter minimum years of experience: ";
            cin >> yearsExperience;
            cout << "\nWorkers with more than " << yearsExperience << " years of experience:\n";
            for (const auto& worker : workers) {
                if (worker.getExperience(2023) > yearsExperience) {
                    worker.displayInfo();
                    cout << "---------------\n";
                }
            }
            break;

        case 2:
            cout << "Enter minimum salary: ";
            cin >> salaryLimit;
            cout << "\nWorkers with salary exceeding " << salaryLimit << ":\n";
            for (const auto& worker : workers) {
                if (worker.getSalary() > salaryLimit) {
                    worker.displayInfo();
                    cout << "---------------\n";
                }
            }
            break;

        case 3:
           cout << "Enter position to search: ";
           cin >> searchParam;
           cout << "\nWorkers with position " << searchParam << ":\n";
            for (const auto& worker : workers) {
                if (worker.getPosition() == searchParam) {
                    worker.displayInfo();
                    cout << "---------------\n";
                }
            }
            break;

        case 0:
           cout << "Exiting program.\n";
            break;

        default:
            std:: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}