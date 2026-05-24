#include <iostream>
#include <string>
using namespace std;

class Book
{
	private:
		string title;
		string author;
		string isbn;
		bool isAvailable;

	public:
		Book(const string& titile, const string& author, const string& isbn)
		{
			this -> title = title;
			this -> author = author;
			this -> isbn = isbn;
			this -> isAvailable = true;
		}

 bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        isAvailable = true;
    }

    void displayInfo() const {
        string status = isAvailable ? "Available" : "Borrowed";
        cout << title << " by " << author << " (ISBN: " << isbn << ") - " << status << endl;
    }
};

int main() {
    Book book("The Pragmatic Programmer", "David Thomas", "978-0135957059");
    book.displayInfo();

    bool success = book.borrowBook();
    cout << "Borrow successful: " << boolalpha << success << endl;
    book.displayInfo();

    success = book.borrowBook();
    cout << "Borrow successful: " << success << endl;

    book.returnBook();
    book.displayInfo();

    return 0;
}
