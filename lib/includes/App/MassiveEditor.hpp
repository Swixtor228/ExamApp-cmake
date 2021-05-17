#pragma once
#include <vector>

namespace MassiveEditor {
	void MassiveEditorStartScreen();
	void MassiveEditorMenu(vector<int>&);
	void Print(vector<int>);
	void ElemPaste(vector<int>&);
	void ElemDelete(vector<int>&);
	void PasteSomeElem(vector<int>&);
	void DelSomeElem(vector<int>&);
}