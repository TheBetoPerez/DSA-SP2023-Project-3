#include "Team.h"


Team::Team() {

	name = "Nameless";
	
}


Team::Team(std::string _name) {

	name = _name;

}


void Team::init(BTree& _aggregate) {

	_aggregate.gameTraverse(name, gameVecB);
	initTreeB();

}

void Team::init(BPlusTree& _aggregate) {


	_aggregate.gameTraverse(name, gameVecBP);
	initTreeBP();
}

void Team::initTreeB() {

	for (unsigned int i = 0; i < gameVecB.size(); i++) {

		gamesPlayedB.insert(gameVecB[i]);

	}
	//std::cout << gameVec.size();

	gameVecB.clear();

}

void Team::initTreeBP() {

	for (unsigned int i = 0; i < gameVecBP.size(); i++) {

		gamesPlayedBP.insert(gameVecBP[i]);

	}
	//std::cout << gameVec.size();

	gameVecBP.clear();

}

float Team::writeSeasonB(int selection, int season, std::string name) {


	gamesPlayedB.writeSeason(selection, averageB, season, name);
	float sum = 0.0f;
	float total = 0.0f;

	for (int i = 0; i < averageB.size(); i++) {

		sum = sum + averageB[i];

	}

	total = sum / averageB.size();
	averageB.clear();
	return total;

}

float Team::writeSeasonBP(int selection, int season, std::string name) {

	
	gamesPlayedBP.writeSeason(selection, averageBP, season, name);

	float sum = 0.0f;
	float total = 0.0f;

	gamesPlayedB.writeSeason(selection, averageB, season, name);
	averageBP = averageB;

	for (int i = 0; i < averageB.size(); i++) {

		sum = sum + averageB[i];

	}
	

	total = sum / averageB.size();



	averageBP.clear();
	return total;

}


void Team::printSeasonStatB(int selection, int season) {

	std::cout << name << ":\n";

	switch (selection){
	case 0://Points
		std::cout << "Average points scored";
		break;

	case 1://2-Point success rate
		std::cout << "Average 2-Point success rate";
		break;

	case 2:
		std::cout << "Average free throw success rate";
		break;

	case 3:
		std::cout << "Average 3-Point success rate";
		break;

	case 4:
		std::cout << "Average number of assists";
		break;

	case 5:
		std::cout << "Average number of rebounds";
		break;

	case 6:
		std::cout << "Win percentage";
		break;


	default:
		break;
	}


	std::cout << " in the " << season << " season: ";

	if (selection == 6 || (selection < 4 && selection > 0)) {

		std::cout << writeSeasonB(selection, season, name) * 100.0f << "%\n";

	}
	else {

		std::cout << writeSeasonB(selection, season, name) << "\n";

	}

	//std::cout << average.size() << "\n";
}

void Team::printSeasonStatBP(int selection, int season) {

	std::cout << name << ":\n";

	switch (selection) {
	case 0://Points
		std::cout << "Average points scored";
		break;

	case 1://2-Point success rate
		std::cout << "Average 2-Point success rate";
		break;

	case 2:
		std::cout << "Average free throw success rate";
		break;

	case 3:
		std::cout << "Average 3-Point success rate";
		break;

	case 4:
		std::cout << "Average number of assists";
		break;

	case 5:
		std::cout << "Average number of rebounds";
		break;

	case 6:
		std::cout << "Win percentage";
		break;


	default:
		break;
	}


	std::cout << " in the " << season << " season: ";

	if (selection == 6 || (selection < 4 && selection > 0)) {

		std::cout << writeSeasonBP(selection, season, name) * 100.0f << "%\n";

	}
	else {

		std::cout << writeSeasonBP(selection, season, name) << "\n";

	}

	//std::cout << average.size() << "\n";
}







void Team::writeAllSeasonsB(int selections) {

	int  s = 2003;

	for (int i = 0; i < 20; i++) {


		averageAllSeasonsB.push_back(writeSeasonB(selections, s, name));
		s++;

	}

}

void Team::writeAllSeasonsBP(int selections) {

	int  s = 2003;
	

	for (int i = 0; i < 20; i++) {


		averageAllSeasonsBP.push_back(writeSeasonBP(selections, s, name));
		s++;

	}

}




void Team::printAllSeasonsB(int selection) {


	std::cout << name << ":\n";

	writeAllSeasonsB(selection);

	std::string placeHolder;

	switch (selection) {
	case 0:
		placeHolder = "Average points scored";
		break;
	case 1:
		placeHolder = "Average 2-Point success rate";
		break;
	case 2:
		placeHolder = "Average free throw success rate";
			break;
	case 3:
		placeHolder = "Average 3-point success rate";
		break;
	case 4:
		placeHolder = "Average number of assists";
		break;
	case 5:
		placeHolder = "Average number of rebounds";
			break;
	case 6:
		placeHolder = "Win rate";
		break;
		
	default:
		break;

	}

	std::cout << "========  " << placeHolder << " across all seasons" <<  "  ========\n";

	int s = 2003;
	int c = 0;

	for (int i = 0; i < averageAllSeasonsB.size(); i++) {
		
		c++;

		if (selection == 6 || (selection < 4 && selection > 0)) {


			std::cout << s << ": " << averageAllSeasonsB[i] * 100.0f << "%    ";

			if (c % 4 == 0) {

				std::cout << "\n";

			}

		}
		else {


			std::cout << s << ": " << averageAllSeasonsB[i] << "    ";

			if (c % 4 == 0) {

				std::cout << "\n";

			}
		}

		s++;
	}

	std::cout << "\n";
}


void Team::printAllSeasonsBP(int selection) {


	std::cout << name << ":\n";

	writeAllSeasonsBP(selection);

	std::string placeHolder;

	switch (selection) {
	case 0:
		placeHolder = "Average points scored";
		break;
	case 1:
		placeHolder = "Average 2-Point success rate";
		break;
	case 2:
		placeHolder = "Average free throw success rate";
		break;
	case 3:
		placeHolder = "Average 3-point success rate";
		break;
	case 4:
		placeHolder = "Average number of assists";
		break;
	case 5:
		placeHolder = "Average number of rebounds";
		break;
	case 6:
		placeHolder = "Win rate";
		break;

	default:
		break;

	}

	std::cout << "========  " << placeHolder << " across all seasons" << "  ========\n";

	int s = 2003;
	int c = 0;

	for (int i = 0; i < averageAllSeasonsB.size(); i++) {

		c++;

		if (selection == 6 || (selection < 4 && selection > 0)) {


			std::cout << s << ": " << averageAllSeasonsB[i] * 100.0f << "%    ";

			if (c % 4 == 0) {

				std::cout << "\n";

			}

		}
		else {

			std::cout << s << ": " << averageAllSeasonsB[i] << "    ";

			if (c % 4 == 0) {

				std::cout << "\n";

			}
		}

		s++;
	}

	std::cout << "\n";
}


