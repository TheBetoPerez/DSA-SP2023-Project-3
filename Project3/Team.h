#ifndef  TEAM_H
#define TEAM_H
#include <string>
#include "BTree.h"
#include <vector>
#include "BPlusTree.h"

class Team {

public:

	
	std::string name;

	BTree gamesPlayedB;
	BPlusTree gamesPlayedBP;


	std::vector<Game> gameVecB;
	std::vector<Game> gameVecBP;

	std::vector<float> averageB;
	std::vector<float> averageAllSeasonsB;

	std::vector<float> averageBP;
	std::vector<float> averageAllSeasonsBP;


	Team();
	Team(std::string _name);

	void init(BTree& _aggregate);
	void init(BPlusTree& _aggregate);

	void initTreeB();
	void initTreeBP();
	
	float writeSeasonB(int selection, int season, std::string name);
	float writeSeasonBP(int selection, int season, std::string name);


	void printSeasonStatB(int selection, int season);
	void printSeasonStatBP(int selection, int season);


	void writeAllSeasonsB(int selection);
	void writeAllSeasonsBP(int selection);


	void printAllSeasonsB(int selection);
	void printAllSeasonsBP(int selection);

};





#endif // ! TEAM_H
