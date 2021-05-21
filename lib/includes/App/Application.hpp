#pragma once

#include <iostream>
using namespace std;

#include <App/MassiveEditor.hpp>
#include <App/LibraryApp.hpp>
// Primary Namespace
// Task: combining the entire program into one whole
// And launch
namespace Application {
	using namespace MassiveEditor; 
	using namespace LibraryApp;

	void StartScreen();
}