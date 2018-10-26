#include <string>

class Staff{

public:
    void viewBooksAvailability();
    void returnBookInterface();
    void viewlog();
    int returnIssuedBook(std::string isbn, std::string username); //return type is string because it will return a message about returning book either success, isbn doen't exist, username doesn't exist, user has not issued this book.
    void staffInterface();
};