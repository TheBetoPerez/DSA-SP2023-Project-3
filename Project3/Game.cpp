#include "Game.h"

Game::Game() {
	//std::cout << "Default Constructor called\n";
	
	

	id = 0;
	status = "";
	homeTeam = "";
	vistorTeam = "";
	season = 1999;

	homePoints = 0;
	home2PPCT = 0.0f;
	homeFTPCT = 0.0f;
	home3PPCT = 0.0f;
	homeAssists = 0;
	homeRebounds = 0;

	awayPoints = 0;
	away2PPCT = 0.0f;
	awayFTPCT = 0.0f;
	away3PPCT = 0.0f;
	awayAssists = 0;
	awayRebounds = 0;

	homeTeamWins = true;
	
}


Game::Game(unsigned int _id, std::string _status, std::string _homeTeam, std::string _visitorTeam, unsigned short int _season,
	unsigned short int _homePoints, float _home2PPCT, float _homeFTPCT, float _home3PPCT, unsigned short int _homeAssists, unsigned short int _homeRebounds,
	unsigned short int _awayPoints, float _away2PPCT, float _awayFTPCT, float _away3PPCT, unsigned short int _awayAssists, unsigned short int _awayRebounds,
	bool _homeTeamWins) {

	id = _id;
	status = _status;
	homeTeam = _homeTeam;
	vistorTeam = _visitorTeam;
	season = _season;

	std::string temp = std::to_string(id);

	date = temp.substr(0, 4);
	date = date + "-" + temp.substr(4, 2);
	date = date + "-" + temp.substr(6, 2);

	homePoints = _homePoints;
	home2PPCT = _home2PPCT;
	homeFTPCT = _homeFTPCT;
	home3PPCT = _home3PPCT;
	homeAssists = _homeAssists;
	homeRebounds = _homeRebounds;

	awayPoints = _awayPoints;
	away2PPCT = _away2PPCT;
	awayFTPCT = _awayFTPCT;
	away3PPCT = _away3PPCT;
	awayAssists = _awayAssists;
	awayRebounds = _awayRebounds;

	
	homeTeamWins = _homeTeamWins;

}

//Simply print the data. Mostly debug, but used in the B-Tree search to print all games played on 1 date
void Game::printData() {

	std::cout << "Game ID: " << id << "\n";

	std::cout << "Played on (YYYY-MM-DD): " << date << "\n";

	std::cout << "Home Team: " << homeTeam << "\n";
	std::cout << "Visitor Team: " << vistorTeam << "\n";
	std::cout << "Season: " << season << "\n\n";

	if (homeTeamWins) {

		std::cout << "Winner: " << homeTeam;

	}
	else {

		std::cout << "Winner: " << vistorTeam;

	}
	std::cout << "\n\n";

	std::cout << homeTeam << ":\n";
	std::cout << "Points scored: " << homePoints << "\n";
	std::cout << "2-point %: " << home2PPCT << "\n";
	std::cout << "Free throw %: " << homeFTPCT << "\n";
	std::cout << "3-point %: " << home3PPCT << "\n";
	std::cout << "Assists: " <<  homeAssists <<  "\n";
	std::cout << "Rebounds: " << homeRebounds << "\n\n";

	std::cout << vistorTeam << ":\n";
	std::cout << "Points scored: " << awayPoints << "\n";
	std::cout << "2-point %: " << away2PPCT << "\n";
	std::cout << "Free throw %: " << awayFTPCT << "\n";
	std::cout << "3-point %: " << away3PPCT << "\n";
	std::cout << "Assists: " << awayAssists << "\n";
	std::cout << "Rebounds:  " << awayRebounds << "\n\n";

	

	std::cout << "\n\n\n===========================\n\n";


}