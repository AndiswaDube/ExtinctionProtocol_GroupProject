#pragma once
#include <iostream>
#include "Question.h"
#include <vector>

using namespace std;

namespace ExtinctionProtocol {
	public class Level
	{
	private:
		string storyLine;
		vector<Question> questions;

	public:
		Level() { storyLine = "Extinction Protocol"; questions = {}; }
		Level(string newStoryLine, vector<Question> newQuestions);
		string getStoryLine();
		bool hasNextQuestion(); // Checks if more questions exists
		Question getQuestionAt(int index);
		Question getNextQuestion(); // Gets the next question
		int getNumOfQuestions(); // Get the total number of questions

		template <typename T = ExtinctionProtocol::Question>
		T getQuestionAt(int index) {
			questions.shrink_to_fit();
			if (index > -1 && index < questions.size()) {
				return static_cast<T>(questions[index]);
			}
			throw std::out_of_range("Index out of range in getQuestionAt()");
		}
	};
}