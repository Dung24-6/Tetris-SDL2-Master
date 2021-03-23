#include <iostream>
#include "Score.h"

std::fstream Score::scoreFile;
std::vector<std::string> Score::scoreVect;

void Score::scoreRead() {
	scoreFile.open("res/score/score.txt", std::ios::in);

	if (scoreFile.peek() == std::ifstream::traits_type::eof()) {
		scoreFile.close();
		scoreFile.open("res/score/score.txt", std::ios::out);
		
		std::string originalScore = "1\tJohn\t1000\t04:00\n2\tPaul\t750\t03:00\n3\tRingo\t500\t02:00\n4\tGeorge\t250\t01:00\n5\tPepper\t100\t00:30";

		scoreFile << originalScore;

		std::cout << "Score file was empty" << std::endl << "New file created" << std::endl;

		scoreFile.close();
		scoreFile.open("res/score/score.txt", std::ios::in);
	}

	std::string line;

	if (!scoreFile.is_open()) {
		std::cout << "Error opening score file - res/score/score.txt" << std::endl;
		return;
	}
	else {
		//Empties score vector
		if (!scoreVect.empty()) {
			scoreVect.clear();
		}

		//Loads data in to score vector from file
		int i = 0;
		while (!scoreFile.eof()) {
			if ((i + 1) % 4 == 0) {
				getline(scoreFile, line, '\n');
				scoreVect.push_back(line);
			}
			else {
				getline(scoreFile, line, '\t');
				scoreVect.push_back(line);
			}
			i++;
		}
	}

	scoreFile.close();
}

void Score::scoreUpdate(int pos, std::string name, int score, std::string time) {
	int startPos = 17;

	while (startPos - 4 > pos) {
		for (int i = 0; i < 3 ; i++)
		scoreVect[startPos + i] = scoreVect[startPos - 4 + i];
		startPos -= 4;
	}

	scoreVect[pos + 1] = name;
	scoreVect[pos + 2] = std::to_string(score);
	scoreVect[pos + 3] = time;

	scoreFile.open("res/score/score.txt", std::ios::out);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (j != 3) {
				scoreFile << scoreVect[i * 4 + j] << '\t';
			}
			else {

				scoreFile << scoreVect[i * 4 + j] << '\n';
			}
		}
	}

	scoreFile.close();
}

void Score::scoreErase() {
	scoreVect.clear();
}
