#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Option.h"

using namespace std;
using namespace System::Drawing;

namespace ExtinctionProtocol {
	public class Question
	{
	private:
		string text;
		string queImagePath;
		vector<Option> options;

	public:
		Question() { text = ""; queImagePath = ""; options = {}; }
		Question(string newText, string newQueImagePath, vector<Option> newOptions, string newQuesType);
		string quesType;
		string getText();
		string getImagePath(); 
		Option getOptionAt(int index);
		vector<Option> getOptions(); // Returns options in a vector
	};
}