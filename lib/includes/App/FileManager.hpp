#pragma once
#include <iostream>
#include <vector>

#include <App/LibraryApp.hpp>
// File Manager
// Namespace, outputs data to a file
namespace FileManager {
	void GetFileData(bool isFilled, LibraryApp::Book book[], int bookSize);
	void SaveToFile(std::string name, LibraryApp::Book book[], int bookSize);
	void readFromFile(std::string, vector<int> arr);
}
