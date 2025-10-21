#include "Level.h"
#include "global.h"

namespace ExtinctionProtocol {
	Level::Level(string newStoryLine, vector<Question> newQuestions)
	{
		storyLine = newStoryLine;
		questions = newQuestions;
	}

	string Level::getStoryLine() {
		return storyLine;
	}

	bool Level::hasNextQuestion() {
		questions.shrink_to_fit();
		if (currQuestion + 1 < questions.size()) {
			return true;
		}

		return false;
	}

	Question Level::getQuestionAt(int index) {
		if (index >= 0 && index < questions.size()) {
			return questions[index];
		}
		else {
			return Question(); // assuming you have a default constructor
		}
	}

	Question Level::getNextQuestion() {
		if (hasNextQuestion()) {
			currQuestion++;
			return questions[currQuestion];
		}
		else {
			currQuestion = 0;
			loadNextLevel();
			return Question(); // return something even after loadNextLevel
		}
	}
	int Level::getNumOfQuestions()
	{
		questions.shrink_to_fit();
		return questions.size();
	}
}