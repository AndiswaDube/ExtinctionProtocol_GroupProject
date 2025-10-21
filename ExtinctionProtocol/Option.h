#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace ExtinctionProtocol {
	public class Option
	{
	private:
		string text;
		string imageFullPath;
		bool isCorrect;

	public:
		Option() { text = ""; imageFullPath = ""; isCorrect = false; }
		Option(string newText, string newImageFullPath, bool newIsCorrect);
		string getImagePath();
		string getText();
		bool isCorrectAns();
	};
}