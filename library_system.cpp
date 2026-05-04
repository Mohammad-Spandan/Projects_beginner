// Smart Library Management System Code

#include <iostream>
#include <string>
#include <vector>

class Library {
private:
    std::vector<std::string> books;

public:
    void addBook(const std::string& book) {
        books.push_back(book);
    }

    void displayBooks() {
        std::cout << "Available books:\n";
        for (const auto& book : books) {
            std::cout << "- " << book << std::endl;
        }
    }
};

int main() {
    Library myLibrary;
    myLibrary.addBook("C++ Programming");
    myLibrary.addBook("Data Structures and Algorithms");
    myLibrary.displayBooks();
    return 0;
}