#define BOOK_SIZE 2 //change the value here to change the size of the array
#pragma warning(disable: 0020)

#include <iostream>	
#include <windows.h>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

#include <App/LibraryApp.hpp>
#include <App/Application.hpp>
#include <App/FileManager.hpp>
#include <App/Log.hpp>

LibraryApp::BookSearch bookSearch;
LibraryApp::BookSorting bookSorting;
//Array of structures
LibraryApp::Book book[BOOK_SIZE];
bool isFilled = false;

// The Print function, is not a function of any class / functions
// This is done for ease of use
void Print()
{
	cout << "[==============================]\n";
	for (int i = 0; i < BOOK_SIZE; i++)
		cout << "Book #" << i << endl,
		cout << "* Title: " << book[i].title << endl,
		cout << "* Author name: " << book[i].authorName << endl,
		cout << "* Publisher: " << book[i].publisher << endl,
		cout << "* Genre: " << book[i].genre << endl,
		cout << "[==============================]\n";
}
// Checks if the array of structures is full
void LibraryApp::checkIsFilled(bool isFilled, void func())
{
	if (isFilled)
		func();
	else
		LOG_ERROR("You must fill in an array of books before displaying it on the screen\n"),
		system("pause"),
		LibraryApp::LibraryAppStartScreen();
}
// LibraryApp application Start Screen
void LibraryApp::LibraryAppStartScreen()
{
	system("cls");

	int choice = 0;

	cout << "-=[Library App]=-\n";
	cout << "1. Fill Data\n";
	cout << "2. Show Data\n";
	cout << "3. Edit book\n";
	cout << "4. Show All Data\n";
	cout << "5. Save to file\n";
	cout << "6. Book Search\n";
	cout << "7. Sorting\n\n";

	cout << "0. Back\n";
	cout << "Your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		Application::StartScreen();
		break;
	case 1:
		LibraryApp::FillData();
		break;
	case 2:
		LibraryApp::checkIsFilled(isFilled, LibraryApp::ShowData);
		break;
	case 3:
		LibraryApp::checkIsFilled(isFilled, LibraryApp::EditBook);
		break;
	case 4:
		LibraryApp::checkIsFilled(isFilled, LibraryApp::ShowAllData);
		break;
	case 5:
		FileManager::GetFileData(isFilled, book, BOOK_SIZE);
		break;
	case 6:
		LibraryApp::checkIsFilled(isFilled, LibraryApp::fBookSearch);
		break;
	case 7:
		LibraryApp::checkIsFilled(isFilled, LibraryApp::fBookSorting);
		break;
	default:
		LOG_ERROR("Not found!\n");
		system("pause");
		LibraryApp::LibraryAppStartScreen();
		break;
	}
}
// Getting data from the keyboard
void LibraryApp::FillData()
{
	cin.ignore();
	for (int i = 0; i < BOOK_SIZE; i++)
	{
		system("cls");
		cout << "Book #" << i + 1 << endl;

		cout << "* Title: ";
		getline(cin, book[i].title);

		cout << "* Author name: ";
		getline(cin, book[i].authorName);

		cout << "* Publisher: ";
		getline(cin, book[i].publisher);

		cout << "* Genre: ";
		getline(cin, book[i].genre);

		cout << endl;
		system("pause");
	}
	system("cls");
	isFilled = true;

	LOG_INFO("Filling in the array: completed!\n");
	system("pause");

	LibraryApp::LibraryAppStartScreen();
}
// Shows the data written to the array
void LibraryApp::ShowData()
{
	system("cls");
	int bookID = 0;

	cout << "Enter the book ID(1-" << BOOK_SIZE <<"): ";
	cin >> bookID;

	if (bookID <= BOOK_SIZE && bookID >= 1)
	{
		cout << "\nBook #" << bookID << endl;

		cout << "* Title: "			<< book[bookID - 1].title		 << endl;
		cout << "* Author name: "	<< book[bookID - 1].authorName   << endl;
		cout << "* Publisher: "		<< book[bookID - 1].publisher    << endl;
		cout << "* Genre: "			<< book[bookID - 1].genre		 << endl;

		cout << endl;
		system("pause");
		LibraryApp::LibraryAppStartScreen();
	}
	else
	{
		LOG_ERROR("Not found!\n");
		cout << "\nError 404: Not found!\n";
		system("pause");
		LibraryApp::LibraryAppStartScreen();
	}
}
// Changes the book
void LibraryApp::EditBook()
{
	system("cls");
	int bookID = 0;
	string change;
	string instead;

	cout << "To go back, enter -1\n";
	cout << "Enter the book ID(1-" << BOOK_SIZE << "): ";
	cin >> bookID;

	if (bookID == -1)
		LibraryApp::LibraryAppStartScreen();
	else
	{
		LOG_WARN("Repeat please!\n");
		system("pause");
		LibraryApp::EditBook();
	}

	if (bookID <= BOOK_SIZE && bookID >= 1)
	{
		bool isChangeWordCorrect;

		cout << "\nChange: \n"
			<< "* Title\n"
			<< "* Name\n"
			<< "* Publisher\n"
			<< "* Genre\n";

		cout << "\nWhat do we need to change?\n"
			<< "Answer: ";
		cin >> change;

		(change == "Title"			|| change == "title"		||
			change == "Name"		|| change == "name"			||
			change == "Publisher"	|| change == "publisher"	||
			change == "Genre"		|| change == "genre")		? isChangeWordCorrect = true
																: isChangeWordCorrect = false;

		if (isChangeWordCorrect)
		{
			cout << "\nWhat should we replace it with?\n";

			if (change == "Title" || change == "title")
				cout << book[bookID - 1].title << " to: ",
				cin >> instead,
				book[bookID - 1].title = instead;
			else if (change == "Name" || change == "name")
				cout << book[bookID - 1].authorName << " to: ",
				cin >> instead,
				book[bookID - 1].authorName = instead;
			else if (change == "Publisher" || change == "publisher")
				cout << book[bookID - 1].publisher << " to: ",
				cin >> instead,
				book[bookID - 1].publisher = instead;
			else if (change == "Genre" || change == "genre")
				cout << book[bookID - 1].genre << " to: ",
				cin >> instead,
				book[bookID - 1].genre = instead;
		}
		else
			LOG_WARN("Repeat please!\n");
			system("pause"),
			LibraryApp::EditBook();

		cout << "\nAll changes are saved!\n";
		system("pause");
		LibraryApp::LibraryAppStartScreen();
	}
	else if (bookID == 0)
		LibraryApp::LibraryAppStartScreen();
	else
	{
		LOG_ERROR("Not found!\n");
		system("pause");
		LibraryApp::LibraryAppStartScreen();
	}
}
// Shows all data as a list
void LibraryApp::ShowAllData()
{
	system("cls");
	cout << "[==============================]\n";

	for (int i = 0; i < BOOK_SIZE; i++)
	{
		cout << "Book #" << i << endl;
		cout << "* Title: "			<< book[i].title		<< endl;
		cout << "* Author name: "	<< book[i].authorName	<< endl;
		cout << "* Publisher: "		<< book[i].publisher	<< endl;
		cout << "* Genre: "			<< book[i].genre		<< endl;
		cout << "[==============================]\n";
	}
	cout << endl;
	system("pause");
	LibraryApp::LibraryAppStartScreen();
}

void LibraryApp::fBookSearch()
{
	bookSearch.SearchBookBy(book, BOOK_SIZE);
}

void LibraryApp::fBookSorting()
{
	bookSorting.SortBooksBy(book, BOOK_SIZE);
}

void LibraryApp::BookSearch::SearchBookBy(LibraryApp::Book book[], int bookSize)
{
	system("cls");

	int choice;

	cout << "Search Book by: \n"
		<< "1. Author\n"
		<< "2. Title\n\n"

		<< "0. Back\n";
	cout << "Your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		LibraryApp::LibraryAppStartScreen();
		break;
	case 1:
		Author(book, bookSize);
		break;
	case 2:
		Title(book, bookSize);
		break;
	default:
		LOG_ERROR("Not found!\n");
		system("pause");
		LibraryApp::LibraryAppStartScreen();
		break;
	}
}

void LibraryApp::BookSearch::Author(LibraryApp::Book book[], int bookSize)
{
		system("cls");

		string n_AuthorName;
		int counter = 0;

		cout << "Enter title name: ";
		cin >> n_AuthorName;

		for (int i = 0; i < bookSize; i++)
			if (book[i].authorName == n_AuthorName)
				counter++;

		if (counter > 0)
		{
			system("cls");
			cout << "[==============================]\n";

			for (int i = 0; i < bookSize; i++)
				if (book[i].authorName == n_AuthorName)
					cout << "Book #" << i << endl,
					cout << "* Title: " << book[i].title << endl,
					cout << "* Author name: " << book[i].authorName << endl,
					cout << "* Publisher: " << book[i].publisher << endl,
					cout << "* Genre: " << book[i].genre << endl,
					cout << "[==============================]\n";
		}
		else
			LOG_ERROR("Not match!\n");

		system("pause");
		LibraryApp::LibraryAppStartScreen();
}

void LibraryApp::BookSearch::Title(LibraryApp::Book book[], int bookSize)
{
	system("cls");

	string n_title;
	int counter = 0;

	cout << "Enter title name: ";
	cin >> n_title;

	for (int i = 0; i < bookSize; i++)
		if (book[i].title == n_title)
			counter++;

	if (counter > 0)
	{
		system("cls");
		cout << "[==============================]\n";

		for (int i = 0; i < bookSize; i++)
			if (book[i].title == n_title)
				cout << "Book #" << i << endl,
				cout << "* Title: " << book[i].title << endl,
				cout << "* Author name: " << book[i].authorName << endl,
				cout << "* Publisher: " << book[i].publisher << endl,
				cout << "* Genre: " << book[i].genre << endl,
				cout << "[==============================]\n";
	}
	else
		LOG_ERROR("Not match!\n");

	system("pause");
	LibraryApp::LibraryAppStartScreen();
}

void LibraryApp::BookSorting::SortBooksBy(LibraryApp::Book book[], int bookSize)
{
	system("cls");

	int choice;

	cout << "Sort Book by: \n"
		<< "1. Title\n"
		<< "2. Author\n"
		<< "3. Publisher\n\n"

		<< "4. Sort by: " << str_sortBy << "\n\n"

		<< "0. Back\n";
	cout << "Your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		LibraryApp::LibraryAppStartScreen();
		break;
	case 1:
		Title(book, bookSize);
		break;
	case 2:
		Author(book, bookSize);
		break;
	case 3:
		Publisher(book, bookSize);
		break;
	case 4:
		(isIncreasing) ? isIncreasing = false : isIncreasing = true;
		(isIncreasing) ? str_sortBy = "Increasing" : str_sortBy = "Decreasing";

		cout << "isIncreasing: " << isIncreasing;

		LibraryApp::BookSorting::SortBooksBy(book, BOOK_SIZE);
		break;
	default:
		LOG_ERROR("Not found!\n");
		system("pause");
		LibraryApp::LibraryAppStartScreen();
		break;
	}
}

void LibraryApp::BookSorting::Title(LibraryApp::Book book[], int bookSize)
{
	for (int i = bookSize - 1; i > 0; i--)	
		for (int j = 0; j < i; j++)	
			if (isIncreasing)			
				if (strcmp(book[j].title.c_str(), book[j + 1].title.c_str()) > 0)
					std::swap(book[j], book[j + 1]);			
			else if (!isIncreasing)			
				if (strcmp(book[j].title.c_str(), book[j + 1].title.c_str()) < 0)
					std::swap(book[j + 1], book[j]);
			
	system("cls");

	Print();
	 
	cout << endl;
	system("pause");
	LibraryApp::LibraryAppStartScreen();
}

void LibraryApp::BookSorting::Author(LibraryApp::Book book[], int bookSize)
{
	for (int i = bookSize - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (isIncreasing)
				if (strcmp(book[j].authorName.c_str(), book[j + 1].authorName.c_str()) > 0)
					std::swap(book[j], book[j + 1]);			
			else if (!isIncreasing)			
				if (strcmp(book[j].authorName.c_str(), book[j + 1].authorName.c_str()) < 0)
					std::swap(book[j + 1], book[j]);			

	system("cls");

	Print();

	system("pause");
	LibraryApp::LibraryAppStartScreen();
}

void LibraryApp::BookSorting::Publisher(LibraryApp::Book book[], int bookSize)
{
	for (int i = bookSize - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (isIncreasing)		
				if (strcmp(book[j].publisher.c_str(), book[j + 1].publisher.c_str()) > 0)
					std::swap(book[j], book[j + 1]);		
			else if (!isIncreasing)
				if (strcmp(book[j].publisher.c_str(), book[j + 1].publisher.c_str()) < 0)
					std::swap(book[j + 1], book[j]);			

	system("cls");

	Print();

	system("pause");
	LibraryApp::LibraryAppStartScreen();
}