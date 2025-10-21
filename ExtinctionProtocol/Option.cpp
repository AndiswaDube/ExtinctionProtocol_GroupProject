#include "Option.h"

using namespace std;

namespace ExtinctionProtocol {
	Option::Option(string newText, string newImageFullPath, bool newIsCorrect)
	{
		text = newText;
		imageFullPath = newImageFullPath;
		isCorrect = newIsCorrect;
	}

	string Option::getImagePath()
	{
		return imageFullPath;
	}

	string Option::getText()
	{
		return text;
	}

	bool Option::isCorrectAns() {
		return isCorrect;
	}
}