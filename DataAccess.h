#include <iostream>
#include "BookData.h"
#include "BookDataDBA.h"

using namespace std;
namespace DataAccess
{

    BookDataDBA bDBA;

    vector<Book> Bookvector1 ;
    vector<Log> IssuedBookvector;

    void LoadData()
    {
        Bookvector1 = bDBA.LoadBookDataDBA();
    }

    void LoadIssueBookData()
    {
        IssuedBookvector = bDBA.LoadIssueBookDataDBA();
    }

    void UpdateBookData()
    {
        bDBA.UpdateBookDataDBA();
    }

    void UpdateIssueBookData()
    {
        bDBA.UpdateIssueBookDataDBA();
    }

} // namespace DataAccess