#include "Question.h"

namespace ExtinctionProtocol {
	Question::Question(string newText, string newQueImagePath,  vector<Option> newOptions, string newQuesType)
	{
		text = newText;
		queImagePath = newQueImagePath;
		options = newOptions;
		quesType = newQuesType;
	}

	string Question::getImagePath() {
		return queImagePath;
	}


	Option Question::getOptionAt(int index) {
		options.shrink_to_fit();
		if (index > -1 && index < options.size()) {
			return options[index];
		}
	}

	vector<Option> Question::getOptions() {
		return options;
	}

	string Question::getText()
	{
		return text;
	}
}