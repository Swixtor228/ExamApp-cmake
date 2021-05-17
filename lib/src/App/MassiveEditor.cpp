#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

#include <App/MassiveEditor.hpp>
#include <App/FileManager.hpp>
#include <App/Application.hpp>
#include <App/Log.hpp>
  
void MassiveEditor::MassiveEditorStartScreen()
{
    system("cls");
    
    int size = 3;
    vector <int> arr(size);
   
    string fileName;

    /*cout << "Enter file name: ";
    cin >> fileName;*/
    
    FileManager::readFromFile(fileName, arr);
    MassiveEditorMenu(arr);
}

void MassiveEditor::MassiveEditorMenu(vector<int>& arr)
{
    system("cls");

    int choice = 0;

    cout << "1. Add element\n"
        << "2. Delete element\n"
        << "3. Add some elements\n"
        << "4. Remove some elements\n\n"
        << "0. Back\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        ElemPaste(arr);
        break;
    case 2:
        ElemDelete(arr);
        break;
    case 3:
        PasteSomeElem(arr);
        break;
    case 4:
        DelSomeElem(arr);
        break;
    case 0:
        Application::StartScreen();
        break;
    default:
        system("cls");
        LOG_ERROR("Not Found!");
        system("pause");
        MassiveEditorMenu(arr);
        break;
    }
}
    
void MassiveEditor::Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void MassiveEditor::ElemPaste(vector<int>& arr)
{
    system("cls");
    int pos, num;
    cout << "Enter position: ";
    cin >> pos;

    if (pos < arr.size()) {
        cout << "Enter number: ";
        cin >> num;
        auto iter = arr.cbegin();
        arr.insert(iter + pos - 1, num);
        Print(arr);
        cout << endl;
    }
    else {
        system("cls");
        LOG_ERROR("Position > array <--\n\n");
    }

    system("pause");
    MassiveEditorMenu(arr);
}

void MassiveEditor::ElemDelete(vector<int>& arr)
{
    system("cls");
    int pos;

    cout << "Enter position of elements (delete): ";
    cin >> pos;

    if (pos < arr.size()) {
        auto iter = arr.cbegin();
        arr.erase(iter + pos - 1);
        Print(arr);
    }
    else {
        system("cls");
        LOG_ERROR("Position > array <--\n\n");
    }

    system("pause");
    MassiveEditorMenu(arr);
}

void MassiveEditor::PasteSomeElem(vector<int>& arr)
{
    system("cls");
    srand(time(NULL));

    int point, quantity, start = 0;

    cout << "Enter position (main arr): ";
    cin >> point;

    if (point < arr.size()) {
        cout << "Enter quantity of elements (add): ";
        cin >> quantity;

        vector<int> arrInput(20);

        for (size_t i = 0; i < arrInput.size(); i++)
            arrInput[i] = rand() % 20;

        Print(arrInput);

        cout << "Enter start position: ";
        cin >> start;

        auto iter = arr.cbegin();
        arr.insert(iter + point - 1, arrInput.begin() + start - 1, arrInput.begin() + quantity);
        Print(arr);
    }
    else {
        system("cls");
        LOG_ERROR("Position > array <--\n\n");
    }
    system("pause");
    MassiveEditorMenu(arr);
}

void MassiveEditor::DelSomeElem(vector<int>& arr)
{
    system("cls");
    int point, quantity, size = arr.size();

    cout << "Enter position (main arr): ";
    cin >> point;

    if (point < arr.size()) {
        cout << "Enter quantity of elements (delete): ";
        cin >> quantity;

        int end = size - point - quantity;
        auto iter = arr.begin();

        arr.erase(arr.begin() + point - 1, arr.end() - end - 1);
        Print(arr);
    }
    else {
        system("cls");
        LOG_ERROR("Position > array <--\n\n");
    }
    system("pause");
    MassiveEditorMenu(arr);
}