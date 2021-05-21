#pragma once
// The main namespace for the LibraryApp application
// Includes: structure, functions, class.
namespace LibraryApp {
	struct Book {
		string title;
		string authorName;
		string publisher;
		string genre;
	};

	void checkIsFilled(bool isFilled, void func());

	void LibraryAppStartScreen();
	void FillData();
	void ShowData();
	void EditBook();
	void ShowAllData();
	void fBookSearch();
	void fBookSorting();
	// The BookSearch class used to combine search functions (for convenience)
	class BookSearch {
	private:
		void Author(LibraryApp::Book book[], int bookSize);
		void Title(LibraryApp::Book book[], int bookSize);
	public:
		void SearchBookBy(LibraryApp::Book book[], int bookSize);
	};
	// The BookSearch class, used to combine sorting functions (for convenience)
	class BookSorting {
	private:
		bool isIncreasing = true;
		string str_sortBy = "Increasing";

		void Title(LibraryApp::Book book[], int bookSize);
		void Author(LibraryApp::Book book[], int bookSize);
		void Publisher(LibraryApp::Book book[], int bookSize);
	public:
		void SortBooksBy(LibraryApp::Book book[], int bookSize);
	};
}