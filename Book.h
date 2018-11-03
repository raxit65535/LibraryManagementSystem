
#ifndef book_h
#define book_h

#include <string>

using namespace std;

class Book{

    public:
    string getName() { return name; }
    string getIsbn() { return isbn; }
    string getAuthor() { return author; }
    string getInformation() { return information; }
    int getCount() {return count;}

    
    void setName(string new_name) { name = new_name; }
    void setIsbn(string new_isbn) { isbn = new_isbn; }
    void setAuthor(string new_author) { author = new_author; }
    void setInformation(string new_imfor) { information = new_imfor; }
    void setCount(int c) {count = c;}
    
private:

    //this is the way we will enter the book information. As of now we have not setup Manager's interface who can insert the book, but we will need book object 
    //for listbook() function.
    string name;
    string isbn; 
    string author;
    string information; 
    int count; //number of books in the system


};


#endif

