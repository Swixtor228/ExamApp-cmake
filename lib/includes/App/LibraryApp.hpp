#pragma once

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

	class BookSearch {
	private:
		void Author(LibraryApp::Book book[], int bookSize);
		void Title(LibraryApp::Book book[], int bookSize);
	public:
		void SearchBookBy(LibraryApp::Book book[], int bookSize);
	};

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