#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>

class Game {


	public:

	unsigned int id; //The ID is as follows: YYYYMMDD##. The ## from the Game ID in the csv, but only around 5-12 games happen on the same Date.
					//Therefore, we only need the last two digits of the game ID to organize games that happen on the same date.

	std::string date;
	std::string status;
	std::string homeTeam;
	std::string vistorTeam;
	unsigned short int season; //The season represented as a year. Games taking place January-June belong to the season of the previous year
	

	unsigned short int homePoints;
	float home2PPCT;
	float homeFTPCT;
	float home3PPCT;
	unsigned short int homeAssists;
	unsigned short int homeRebounds;

	unsigned short int awayPoints;
	float away2PPCT;
	float awayFTPCT;
	float away3PPCT;
	unsigned short int awayAssists;
	unsigned short int awayRebounds;

	bool homeTeamWins;


	//Default Constructor
	Game();
	
	//Constructor
	
	Game(unsigned int _id, std::string _status, std::string _homeTeam, std::string _visitorTeam, unsigned short int _season,
		unsigned short int _homePoints, float _home2PPCT, float _homeFTPCT, float _home3PPCT, unsigned short int _homeAssists, unsigned short int _homeRebounds,
		unsigned short int _awayPoints, float _away2PPCT, float _awayFTPCT, float _away3PPCT, unsigned short int _awayAssists, unsigned short int _awayRebounds,
		bool _homeTeamWins);

	void printData();


	//Copy Constructor
	Game(const Game &g) {

		this->id = g.id;
		this->date = g.date;
		this->status = g.status;
		this->homeTeam = g.homeTeam;
		this->vistorTeam = g.vistorTeam;
		this->season = g.season;
		
		this->homePoints = g.homePoints;
		this->home2PPCT = g.home2PPCT;
		this->homeFTPCT = g.homeFTPCT;
		this->home3PPCT = g.home3PPCT;
		this->homeAssists = g.homeAssists;
		this->homeRebounds = g.homeRebounds;

		this->awayPoints = g.awayPoints;
		this->away2PPCT = g.away2PPCT;
		this->awayFTPCT = g.awayFTPCT;
		this->away3PPCT = g.away3PPCT;
		this->awayAssists = g.awayAssists;
		this->awayRebounds = g.awayRebounds;

		this->homeTeamWins = g.homeTeamWins;

		
	}

	//Assignment operator
	Game& operator=(const Game &g) {

		this->id = g.id;
		this->date = g.date;
		this->status = g.status;
		this->homeTeam = g.homeTeam;
		this->vistorTeam = g.vistorTeam;
		this->season = g.season;

		this->homePoints = g.homePoints;
		this->home2PPCT = g.home2PPCT;
		this->homeFTPCT = g.homeFTPCT;
		this->home3PPCT = g.home3PPCT;
		this->homeAssists = g.homeAssists;
		this->homeRebounds = g.homeRebounds;

		this->awayPoints = g.awayPoints;
		this->away2PPCT = g.away2PPCT;
		this->awayFTPCT = g.awayFTPCT;
		this->away3PPCT = g.away3PPCT;
		this->awayAssists = g.awayAssists;
		this->awayRebounds = g.awayRebounds;

		this->homeTeamWins = g.homeTeamWins;

		return *this;

	}

};



#endif