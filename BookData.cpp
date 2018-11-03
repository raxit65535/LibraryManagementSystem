#include "BookData.h"
#include "BookDataDBA.h"

BookDataDBA bDBA;

extern vector<Book> Bookvector;
extern vector<Log> IssuedBookvector;

void BookData::LoadData()
{
    Bookvector = bDBA.LoadBookDataDBA();
}

void BookData :: LoadIssueBookData()
{
    IssuedBookvector = bDBA.LoadIssueBookDataDBA();
}

void BookData::UpdateBookData()
{
    bDBA.UpdateBookDataDBA();
}

void BookData :: UpdateIssueBookData()
{
    bDBA.UpdateIssueBookDataDBA();
}