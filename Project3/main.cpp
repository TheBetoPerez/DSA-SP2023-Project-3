#define NOMINMAX
#include <iostream>
#include <fstream>
#include <sstream>
#include "Game.h"
#include <vector>
#include "BTree.h"
#include "Team.h"
#include "gnuplot-iostream.h"

//Eriberto Perez, Brooke Vinson. Project 3: All NBA games played from 2003-2022, stored and accessed using B-Tree and B+Tree.
//Credit to dstahlke on GitHub for providing gnuplot-iostream.h file.


//RUN DOWN: Get a single line from the file. All of 1 game's data is in one line.
//Insert it into the B-Tree. Or map/B+ tree (What we are comparing)

//This tree is how we store and write data. MatPlot++ uses vectors to graph data, so we will
//extract games from the B-Tree/(Other) to write into vectors. Basically iterate through both structures
//and write what we want.

//CLASSES:
//Game - All the data in one line. An ID is determined not by by the file, but by date played an order appeared in file
//Explained later in main

//BTree - BTree using games. Sorted by ID

//Team - Every team has a name, and a BTree/Whatever that stores every game they've ever played.



//TODO: Nothing. All done :)


//Function used later
std::string getName(int teamId);
void writeTeamData(int selection1, int selection2, int selection3, std::vector<float> &t, std::vector<Team> &teams);
std::string getStatTitle(int selection3);
std::string getTeamColor(int selection2);


int main() {
	
	Gnuplot gp("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"");
	//Main selections
	int mSel1;
	int mSel2;
	int mSel3;
	std::vector<Team> allTeams;
	Team PHI("76ers");
	Team MIL("Bucks");
	Team CHI("Bulls");
	Team CLE("Cavaliers");
	Team BOS("Celtics");
	Team LAC("Clippers");
	Team MEM("Grizzlies");
	Team ATL("Hawks");
	Team MIA("Heat");
	Team CHA("Hornets");
	Team UTA("Jazz");
	Team SAC("Kings");
	Team NYK("Knicks");
	Team LAL("Lakers");
	Team ORL("Magic");
	Team DAL("Mavericks");
	Team NYN("Nets");
	Team DEN("Nuggets");
	Team IND("Pacers");
	Team NOR("Pelicans");
	Team DET("Pistons");
	Team TOR("Raptors");
	Team HOU("Rockets");
	Team SAS("Spurs");
	Team PHX("Suns");
	Team OKC("Thunder");
	Team MIN("Timberwolves");
	Team POR("Trail Blazers");
	Team GSW("Warriors");
	Team WAS("Wizards");
	
	Team LEAGUE("LEAGUE");

	//All of these are put into a game object
	unsigned int tempId;
	std::string tempStatus;
	std::string tempHome;
	std::string tempAway;
	unsigned short int tempSeason;

	unsigned short int tempHomePoints;
	float tempHome2PPCT;
	float tempHomeFTPCT;
	float tempHome3PPCT;
	unsigned short int tempHomeAssists;
	unsigned short int tempHomeRebounds;

	unsigned short int tempAwayPoints;
	float tempAway2PPCT;
	float tempAwayFTPCT;
	float tempAway3PPCT;
	unsigned short int tempAwayAssists;
	unsigned short int tempAwayRebounds;

	bool tempHomeTeamWins;



	//Stuff to iterate through the file.
	std::string fileName = "games.csv";

	std::fstream file(fileName, std::ios::in);

	std::vector<Game*> debugVec;

	std::string firstLine;
	std::string line;

	std::string temporary;


	//If opening the file works(it should)
	if (file.is_open()) {

		std::getline(file, firstLine);
		
		
		int i = 0;

		//debug
		int it = 0;

		//used to separate multiple games on the current date.
		std::string currentDate;


		while (std::getline(file, line)) {//For every line do this

			//ID ID ID
			if (it >= 19175 && it < 19281) {
				//These games are missing data in the CSV for some reason. Ignore them. Very trivial amount


				it++;
				continue;

			}

			//Get the date data and put it into these strings.
			std::string year = line.substr(0, 4);
			std::string month = line.substr(5, 2);
			std::string day = line.substr(8, 2);

			//Set the date to the strings attached.
			std::string date = year + month + day;

			if (currentDate == date) {

				i++;

			}
			else {
				
				i = 0;
				currentDate = date;

			}

			std::string uniqueI = std::to_string(i);
			size_t n = 2;

			int precision = n - std::min(n, uniqueI.size());


			//THIS IS THE FINAL ID. IT IS YYYYMMDD##. It can be 01 up to 12. THat's how many games are played in a day
			std::string finalI = std::string(precision, '0').append(uniqueI);


			std::string id = date + finalI;
			tempId = (unsigned int)std::stoi(id);

			//std::cout << tempId << "\n";

			line.erase(0, line.find(',') + 1);
			line.erase(0, line.find(',') + 1);

			//STATUS STATUS STATUS
			tempStatus = line.substr(0, line.find(','));
			line.erase(0, line.find(',') + 1);

			//HOMETEAM HOMETEAM HOMETEAM
			temporary = line.substr(0, line.find(','));

			int tempHomeInt = std::stoi(temporary);

			tempHomeInt = tempHomeInt % 100;
			tempHome = getName(tempHomeInt);

			line.erase(0, line.find(',') + 1);

			//AWAYTEAM AWAYTEAM AWAYTEAM
			temporary = line.substr(0, line.find(','));
			int tempVisInt = std::stoi(temporary);

			tempVisInt = tempVisInt % 100;

			tempAway = getName(tempVisInt);

			line.erase(0, line.find(',') + 1);

			//SEASON SEASON SEASON
			temporary = line.substr(0, line.find(','));
			tempSeason = std::stoi(temporary);

			line.erase(0, line.find(',') + 1);
			line.erase(0, line.find(',') + 1);


			//HOMEPOINTS HOMEPOINTS HOMEPOINTS
			temporary = line.substr(0, line.find(','));
			tempHomePoints = (unsigned short)std::stoi(temporary);

			line.erase(0, line.find(',') + 1);

			//HOMEFG HOMEFG HOMEFG
			temporary = line.substr(0, line.find(','));
			tempHome2PPCT = std::stof(temporary);

			line.erase(0, line.find(',') + 1);

			//HOMEFT HOMEFT HOMEFT
			temporary = line.substr(0, line.find(','));
			tempHomeFTPCT = std::stof(temporary);

			line.erase(0, line.find(',') + 1);

			//HOME3P HOME3P HOME3P
			temporary = line.substr(0, line.find(','));
			tempHome3PPCT = std::stof(temporary);

			line.erase(0, line.find(',') + 1);

			//HOMEASSIST HOMEASSIST HOMEASSIST
			temporary = line.substr(0, line.find(','));
			tempHomeAssists = (unsigned short)std::stoi(temporary);

			line.erase(0, line.find(',') + 1);

			//HOMEREB HOMEREB HOMEREB
			temporary = line.substr(0, line.find(','));
			tempHomeRebounds = (unsigned short)std::stoi(temporary);

			line.erase(0, line.find(',') + 1);
			line.erase(0, line.find(',') + 1);


			//AWAYPTS AWAYPTS AWAYPTS
			temporary = line.substr(0, line.find(','));
			tempAwayPoints = (unsigned short)std::stoi(temporary);

			line.erase(0, line.find(',') + 1);
			
			

			//AWAYFG AWAYFG AWAYFG
			temporary = line.substr(0, line.find(','));
			tempAway2PPCT = std::stof(temporary);

			line.erase(0, line.find(',') + 1);



			//AWAYFT AWAYFT AWAYFT
			temporary = line.substr(0, line.find(','));
			tempAwayFTPCT = std::stof(temporary);

			line.erase(0, line.find(',') + 1);




			//AWAY3P AWAY3P AWAY3P
			temporary = line.substr(0, line.find(','));
			tempAway3PPCT = std::stof(temporary);

			line.erase(0, line.find(',') + 1);


			//AWAYASSIST AWAYASSIST AWAYASSIT
			temporary = line.substr(0, line.find(','));
			tempAwayAssists = (unsigned short)std::stoi(temporary);

			line.erase(0, line.find(',') + 1);



			//AWAYREB AWAYREB AWAYREB
			temporary = line.substr(0, line.find(','));
			tempAwayRebounds = (unsigned short)std::stoi(temporary);

			line.erase(0, line.find(',') + 1);


			temporary = line.substr(0, 1);

			if (temporary == "1") {

				tempHomeTeamWins = true;

			}
			else {

				tempHomeTeamWins = false;

			}

			Game g(tempId, tempStatus, tempHome, tempAway, tempSeason,
				tempHomePoints, tempHome2PPCT, tempHomeFTPCT, tempHome3PPCT, tempHomeAssists, tempHomeRebounds,
				tempAwayPoints, tempAway2PPCT, tempAwayFTPCT, tempAway3PPCT, tempAwayAssists, tempAwayRebounds,
				tempHomeTeamWins);


			LEAGUE.gamesPlayedB.insert(g);
			//debugVec.push_back(g);

			//std::cout << tempHomeTeamWins << "\n";
			//std::cout << tempHome << " vs. " << tempAway << "\n";


			it++;

		}
		
	}
	else {


		std::cout << "Failed to open file\n";

	}

	std::vector<float>leagueWR;

	for (int i = 0; i < 20; i++) {

		leagueWR.push_back(0.5f);

	}


	PHI.init(LEAGUE.gamesPlayedB);
	PHI.init(LEAGUE.gamesPlayedBP);

	MIL.init(LEAGUE.gamesPlayedB);
	MIL.init(LEAGUE.gamesPlayedBP);

	CHI.init(LEAGUE.gamesPlayedB);
	CHI.init(LEAGUE.gamesPlayedBP);

	CLE.init(LEAGUE.gamesPlayedB);
	CLE.init(LEAGUE.gamesPlayedBP);

	BOS.init(LEAGUE.gamesPlayedB);
	BOS.init(LEAGUE.gamesPlayedBP);

	LAC.init(LEAGUE.gamesPlayedB);
	LAC.init(LEAGUE.gamesPlayedBP);

	MEM.init(LEAGUE.gamesPlayedB);
	MEM.init(LEAGUE.gamesPlayedBP);

	ATL.init(LEAGUE.gamesPlayedB);
	ATL.init(LEAGUE.gamesPlayedBP);

	MIA.init(LEAGUE.gamesPlayedB);
	MIA.init(LEAGUE.gamesPlayedBP);

	CHA.init(LEAGUE.gamesPlayedB);
	CHA.init(LEAGUE.gamesPlayedBP);

	UTA.init(LEAGUE.gamesPlayedB);
	UTA.init(LEAGUE.gamesPlayedBP);

	SAC.init(LEAGUE.gamesPlayedB);
	SAC.init(LEAGUE.gamesPlayedBP);

	NYK.init(LEAGUE.gamesPlayedB);
	NYK.init(LEAGUE.gamesPlayedBP);

	LAL.init(LEAGUE.gamesPlayedB);
	LAL.init(LEAGUE.gamesPlayedBP);

	ORL.init(LEAGUE.gamesPlayedB);
	ORL.init(LEAGUE.gamesPlayedBP);

	DAL.init(LEAGUE.gamesPlayedB);
	DAL.init(LEAGUE.gamesPlayedBP);

	NYN.init(LEAGUE.gamesPlayedB);
	NYN.init(LEAGUE.gamesPlayedBP);

	DEN.init(LEAGUE.gamesPlayedB);
	DEN.init(LEAGUE.gamesPlayedBP);

	IND.init(LEAGUE.gamesPlayedB);
	IND.init(LEAGUE.gamesPlayedBP);

	NOR.init(LEAGUE.gamesPlayedB);
	NOR.init(LEAGUE.gamesPlayedBP);

	DET.init(LEAGUE.gamesPlayedB);
	DET.init(LEAGUE.gamesPlayedBP);

	TOR.init(LEAGUE.gamesPlayedB);
	TOR.init(LEAGUE.gamesPlayedBP);

	HOU.init(LEAGUE.gamesPlayedB);
	HOU.init(LEAGUE.gamesPlayedBP);

	SAS.init(LEAGUE.gamesPlayedB);
	SAS.init(LEAGUE.gamesPlayedBP);

	PHX.init(LEAGUE.gamesPlayedB);
	PHX.init(LEAGUE.gamesPlayedBP);

	OKC.init(LEAGUE.gamesPlayedB);
	OKC.init(LEAGUE.gamesPlayedBP);

	MIN.init(LEAGUE.gamesPlayedB);
	MIN.init(LEAGUE.gamesPlayedBP);

	POR.init(LEAGUE.gamesPlayedB);
	PHI.init(LEAGUE.gamesPlayedBP);

	POR.init(LEAGUE.gamesPlayedB);
	PHI.init(LEAGUE.gamesPlayedBP);

	GSW.init(LEAGUE.gamesPlayedB);
	GSW.init(LEAGUE.gamesPlayedBP);

	WAS.init(LEAGUE.gamesPlayedB);
	WAS.init(LEAGUE.gamesPlayedBP);



	allTeams.push_back(PHI);
	allTeams.push_back(MIL);
	allTeams.push_back(CHI);
	allTeams.push_back(CLE);
	allTeams.push_back(BOS);
	allTeams.push_back(LAC);
	allTeams.push_back(MEM);
	allTeams.push_back(ATL);
	allTeams.push_back(MIA);
	allTeams.push_back(CHA);
	allTeams.push_back(UTA);
	allTeams.push_back(SAC);
	allTeams.push_back(NYK);
	allTeams.push_back(LAL);
	allTeams.push_back(ORL);
	allTeams.push_back(DAL);
	allTeams.push_back(NYN);
	allTeams.push_back(DEN);
	allTeams.push_back(IND);
	allTeams.push_back(NOR);
	allTeams.push_back(DET);
	allTeams.push_back(TOR);
	allTeams.push_back(HOU);
	allTeams.push_back(SAS);
	allTeams.push_back(PHX);
	allTeams.push_back(OKC);
	allTeams.push_back(MIN);
	allTeams.push_back(POR);
	allTeams.push_back(GSW);
	allTeams.push_back(WAS);



	std::vector<float> tVec;
	std::vector<float> l;

	//Here starts the GNU
	gp << "set style histogram clustered\n";
	gp << "set style data histogram\n";
	gp << "set xtics (\"2003\" 0, \"2004\" 1, \"2005\" 2, \"2006\" 3, \"2007\" 4, \"2008\" 5, \"2009\" 6, \"2010\" 7, \"2011\" 8, \"2012\" 9, \"2013\" 10, \"2014\" 11, \"2015\" 12, \"2016\" 13, \"2017\" 14, \"2018\" 15, \"2019\" 16, \"2020\" 17, \"2021\" 18, \"2022\" 19)\n";
	
	std::cout << "Welcome. Select the structure you want to use:\n 0. B-Tree    1. B+Tree\n";
	std::cin >> mSel1;
	std::cout << "\n";

	std::cout << "===== NBA Timeline Grapher =====\n\n";
	std::cout << "Welcome. Please select a team to analayze by inputting their number:\n";
	std::cout << "0: 76ers    1: Bucks    2: Bulls    3: Cavaliers    4: Celtics    5: Clippers\n";
	std::cout << "6: Grizzlies    7: Hawks    8: Heat    9: Hornets    10: Jazz    11: Kings\n";
	std::cout << "12: Knicks    13: Lakers    14: Magic    15: Mavericks    16: Nets    17: Nuggets\n";
	std::cout << "18: Pacers    19: Pelicans    20: Pistons    21: Raptors    22: Rockets    23: Spurs\n";
	std::cout << "24: Suns    25: Thunder    26: Timberwolves    27: Trail Blazers    28: Warriors    29: Wizards\n";

	std::cin >> mSel2;
	std::cout << "\n";

	std::cout << "Analyze a statistic by inputting its respective number:\n";
	std::cout << "0: Points scored    1: 2-Point %    2: Free throw %    3: 3-Point %\n";
	std::cout << "4: Rebounds    5: Assists    6: Win %\n";

	std::cin >> mSel3;
	std::cout << "\n";

	//Based on our inputs, go through the algorithm to see what we need to plot
	LEAGUE.writeAllSeasonsB(mSel3);
	l = LEAGUE.averageAllSeasonsB;



	writeTeamData(mSel1, mSel2, mSel3, tVec, allTeams);
	//Percentages range from 0-1, but other stats are from 0-150 or higher.
	if (mSel3 == 2) {

		gp << "set yrange[0.5: 0.9]\n";

	}
	else if (mSel3 == 1 || mSel3 == 3) {

		gp << "set yrange[0.0: 0.7]\n";

	}
	else if (mSel3 == 4 || mSel3 == 5) {

		gp << "set yrange[0: 50]\n";

	}
	else if(mSel3 == 0) {

		gp << "set yrange[0: 150]\n";

	}
	else {

		gp << "set yrange[0: 1]\n";

	}
	gp << "set style fill solid\n";


	gp << "set title " << getStatTitle(mSel3) << "\n";


	gp << "plot '-' lt rgb " << getTeamColor(mSel2) << " t " <<  "\"" << allTeams[mSel2].name << "\", "
		<< "'-' lt rgb \"#888888\" t 'League Average'\n";


	gp.send(tVec);

	if (mSel3 != 6) {

		gp.send(l);

	}
	else {

		gp.send(leagueWR);
	}
	

//	GSW.printAllSeasons(0);
	//LEAGUE.printAllSeasons(0);
	std::cout << "\nPress 0 to end the program\n";

	int d = 1;

	while (d != 0) {

		std::cin >> d;

	}
		
	return 0;
}


//The ID from the CSV is too big and only needs the last two digits. (30 teams).
std::string getName(int teamId) {

	switch (teamId) {

	case 37:
		return "Hawks";
	
	case 38:
		return "Celtics";

	case 39:
		return "Cavaliers";

	case 40:
		return "Pelicans";

	case 41:
		return "Bulls";

	case 42:
		return "Mavericks";

	case 43:
		return "Nuggets";
		
	case 44:
		return "Warriors";

	case 45:
		return "Rockets";

	case 46:
		return "Clippers";

	case 47:
		return "Lakers";

	case 48:
		return "Heat";

	case 49:
		return "Bucks";

	case 50:
		return "Timberwolves";

	case 51:
		return "Nets";

	case 52:
		return "Knicks";

	case 53:
		return "Magic";

	case 54:
		return "Pacers";

	case 55:
		return "76ers";

	case 56:
		return "Suns";

	case 57:
		return "Trail Blazers";

	case 58:
		return "Kings";

	case 59:
		return "Spurs";

	case 60:
		return "Thunder";

	case 61:
		return "Raptors";

	case 62:
		return "Jazz";

	case 63:
		return "Grizzlies";

	case 64:
		return "Wizards";

	case 65:
		return "Pistons";

	case 66:
		return "Hornets";

	default:
		return "TeamDoesNotExist";

	}
}

void writeTeamData(int selection1, int selection2, int selection3, std::vector<float>& t, std::vector<Team> &teams) {


	if (selection1 == 0) {


		teams[selection2].writeAllSeasonsB(selection3);
		t = teams[selection2].averageAllSeasonsB;

	}
	else {
		teams[selection2].writeAllSeasonsBP(selection3);
		t = teams[selection2].averageAllSeasonsBP;


	}
}

std::string getStatTitle(int selection3) {
	switch (selection3) {

	case 0:
		return "\"Average points scored across all seasons\"";
	case 1:
		return "\"Average 2-Point success rate across all seasons\"";
	case 2:
		return "\"Average free throw success rate across all seasons\"";
	case 3:
		return "\"Average 3-Point success rate across all seasons\"";
	case 4:
		return "\"Average number of rebounds across all seasons\"";
	case 5:
		return "\"Average number of assists across all seasons\"";
	case 6:
		return "\"Win rate across all seasons\"";
	default:
		return "\"\"";
	}


}

std::string getTeamColor(int selection2) {

	switch (selection2) {

	case 0://76ers
		return "\"#F00000\"";
	case 1://Bucks
		return "\"#00A000\"";
	case 2://Bulls
		return "\"#F00000\"";
	case 3://Cavs
		return "\"#F00000\"";
	case 4://Celtics
		return "\"#00A000\"";
	case 5://Clippers
		return "\"#0000A0\"";
	case 6://Grizzlies
		return "\"#001090\"";
	case 7://Hawks
		return "\"#FF0000\"";
	case 8://Heat
		return "\"#800000\"";
	case 9://Hornets
		return "\"#0020B0\"";
	case 10://Jazz
		return "\"#EEEE00\"";
	case 11://Kings
		return "\"#AA00AA\"";
	case 12://Knicks
		return "\"#DD7F00\"";
	case 13://Lakers
		return "\"#AAAA00\"";
	case 14://Magic
		return "\"#0077FF\"";
	case 15://Mavs
		return "\"#0022DD\"";
	case 16://Nets
		return "\"#000000\"";
	case 17://Nuggets
		return "\"#DDDD00\"";
	case 18://Pacers
		return "\"#000A44\"";
	case 19://PElicans
		return "\"#000A44\"";
	case 20://Pistons
		return "\"#EE000A\"";
	case 21://Raptors
		return "\"#EE00AA\"";
	case 22://Rockets
		return "\"#EE0000\"";
	case 23://Spurs
		return "\"#AAAAAA\"";
	case 24://Suns
		return "\"#DD00BB\"";
	case 25://Thunder
		return "\"#FF8000\"";
	case 26:
		return "\"#003077\"";
	case 27:
		return "\"#FF000A\"";
	case 28:
		return "\"#EECC00\"";
	case 29:
		return "#\"FF0000\"";
	default:
		return "#\"000000\"";

	}
}