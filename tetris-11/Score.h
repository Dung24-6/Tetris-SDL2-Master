#pragma once
#include <fstream>
#include <string>
#include <vector>

class Score
{
public:
	static void scoreRead();
	static void scoreUpdate(int pos, std::string name, int score, std::string time);
	static void scoreErase();
public:
	static std::vector<std::string> scoreVect;
private:
	static std::fstream scoreFile;
};

