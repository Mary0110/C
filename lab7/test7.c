#include <assert.h>
#include <stdio.h>
#include "readers.h"
#include <math.h>

void testreadBookList(bookList_t* list)
{
	list = readBookList("lib.txt");
	assert(list != NULL);
}

void testreadReaderList(readerList_t* list)
{
	 list= readReaderList("readers.txt");
	assert(list != NULL);
}
void  testdeleteReaderList(readerList_t** list)
{
	assert(deleteReaderList(list) == 0);
}
void  testaddReader(readerList_t* list, readerNode_t* reader)
{
	assert(addReader(list, reader) == 0);
}
	
void testdeleteReader(readerList_t** list, readerNode_t* del)
{
	assert(deleteReader(list, del) == 0);
}
void  testsearchReader(readerList_t* readerList)
{	
	assert(searchReader(readerList, 1264893) != NULL);
}
void testprint_readers(readerList_t* list)
{
	FILE* outputFile = NULL; fopen_s(&outputFile, "output.txt", "w");
	if (outputFile == NULL)
		exit(1);
	assert(print_readers(list, outputFile) == 0);
}

void testgiveOutBook(bookNode_t* b, readerNode_t* current)
{
	assert(giveOutBook(current->reader, b, 01, 10, 2021) == 0);
	assert(current->reader.borrowedList.head == b);
	assert(current->reader.borrowedList.head->book.returnDate.day == 01);
	assert(current->reader.borrowedList.head->book.returnDate.month == 10);
	assert(current->reader.borrowedList.head->book.returnDate.year == 2021);
}
void testreturnBook(bookNode_t* b, readerNode_t* current)
{
	assert(returnBook(&current->reader, b) == 0);
	assert(current->reader.borrowedList.head == NULL);
}
void testfineReader(reader_t* reader)
{	
	assert(fineReader(reader, 1) == 0);
}
void testcountReaders(readerList_t* list)
{
	assert(countReaders(list) == 3);
}

void testaddBook(bookList_t* lib, bookNode_t* reader)
{
	
	assert(addBook(lib, reader) == 0);
}

void testdeleteBook(bookList_t** lib, bookNode_t* del)
{
	assert(deleteBook(lib, del) == 0);
}
void testcount(bookList_t* list)
{
	assert(count(list) == 5);
	bookNode_t* newBook = (bookNode_t*)malloc(sizeof(bookNode_t));
	if (newBook == NULL)
		exit(1);
		
	addBook(list, newBook);
	assert(count(list) == 6);
	deleteBook(&list, newBook);
	assert(count(list) == 5);
}
void testoverallPrice(bookList_t* list)
{
	assert(abs(overallPrice(list) - 10.0f) < 0.00001);
}
void testcountBorrowed(bookList_t* list)
{
	assert(countBorrowed(list) == 1);
}

void testprint_list(bookList_t* list)
{
	FILE* outputFile = NULL; fopen_s(&outputFile, "output2.txt", "w");
	if (outputFile == NULL)
		exit(1);
	assert(print_list(list, outputFile) == 0);
}
void testsearchBook(bookList_t* List)
{
	const char* name = "1984";
	assert(searchBook(List, name) != NULL);
}

#undef main
int main(void)
{
	readerList_t* list = NULL;
	bookList_t* blist = NULL;
    readerNode_t* reader = (readerNode_t*)malloc(sizeof(readerNode_t));
    bookNode_t* book = (bookNode_t*)malloc(sizeof(bookNode_t));

	testreadBookList(blist);
	testreadReaderList(list);
	
	testaddReader(list, reader);
	testdeleteReader(&list, reader); 
	
	testaddBook(blist, book);
	testdeleteBook(&blist, book);

	testsearchReader(list);
	testsearchBook(blist);
    
	readerNode_t* current = list->head;
	bookNode_t* b = blist->head;
	testgiveOutBook(b, current);
	testreturnBook(b, current);
	testfineReader(&current->reader);
	testcountReaders(list);
	testcount(blist);
	testoverallPrice(blist);
	testcountBorrowed(blist);
	testprint_list(blist);
	testprint_readers(list);
	testdeleteReaderList(&list);
	/*testdeleteReaderList(&blist);*/
}