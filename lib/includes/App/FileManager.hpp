#pragma once
#include <iostream>
#include <vector>

#include <App/LibraryApp.hpp>

namespace FileManager {
	void GetFileData(bool isFilled, LibraryApp::Book book[], int bookSize);
	void SaveToFile(std::string name, LibraryApp::Book book[], int bookSize);
	void readFromFile(std::string, vector<int> arr);
}
