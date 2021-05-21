#include <App/Application.hpp>
// Main file, starts the shared namespace function
// The application is divided into 3 parts
// 1. An application that works with an array (MassiveEditor)
// 2. Application for working with a one-dimensional array of structures (LibraryApp)
// 3. A common Application structure that includes the namespaces of 2 other applications
// There are also used classes in a small number to reduce the number of lines
// CMake is also used for self-learning and improving hard skills.
// I was helped with this project (with namespace, classes, CMake, and a third-party spdlog library)
int main()
{
	Application::StartScreen();
}