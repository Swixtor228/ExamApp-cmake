#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include <App/FileManager.hpp>
#include <App/LibraryApp.hpp>
#include <App/Log.hpp>

void FileManager::GetFileData(bool isFilled, LibraryApp::Book book[], int bookSize)
{
	if (isFilled)
	{
		system("cls");
		string name;

		cout << "File name: ";
		cin >> name;

		FileManager::SaveToFile(name, book, bookSize);
	}
	else
		LibraryApp::checkIsFilled(isFilled, LibraryApp::LibraryAppStartScreen);
}

void FileManager::SaveToFile(std::string name, LibraryApp::Book book[], int bookSize)
{
	ofstream output("../../logs/input/" + name + ".txt", ios::out);
	if (output.is_open())
	{
		output << "[==============================]\n";
		for (int i = 0; i < bookSize; i++)
		{
			output << "Book #" << i << endl;
			output << "* Title: " << book[i].title << endl;
			output << "* Author name: " << book[i].authorName << endl;
			output << "* Publisher: " << book[i].publisher << endl;
			output << "* Genre: " << book[i].genre << endl;
			output << "[==============================]\n";
		}
		output.close();
		LOG_INFO("File {}.txt was saved successfully!\n", name);
		system("pause");
		LibraryApp::LibraryAppStartScreen();
	}
}

void FileManager::readFromFile(string name, vector<int> arr)
{
	char buff[50];
	ifstream input("../logs/test.txt" /*+ name + ".txt"*/);

	if (input.is_open())
	{
		input.getline(buff, 50);
		arr.push_back((int)buff);
	}

	input.close();
	LOG_INFO("Readed successfully!\n");
	system("pause");
}