
class Customer{

    void listbooks(); //list all the books
    void showdetails(); //show details of when the book is due
    int RequestBookLoan(int isbn); //just manage the request for the same customer who is loggedin --kind of session management, feel free to change method parameters.
    bool isAvailable(int isbn);
    bool isAlreadyissued(int isbn);



};