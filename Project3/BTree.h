#ifndef BTREE_H
#define BTREE_H
#include "Game.h"
#include <algorithm>
#include <vector>


class Node {

private:

	Game* keys;
	int t;
	Node** c;
	int n;
	bool leaf;


public:
	Node(int temp, bool _leaf);
	void insertNonFull(Game g);
	void splitChild(int i, Node* y);
	void traverse();
	void gameTraverse(std::string name, std::vector<Game> &_GameVec);
	void PrintTraverse();
	Node* search(int date);

	void writeInstance(int selection, std::vector<float> &_average, int season, std::string name);
	void switchStat(bool _isHome, std::vector<float>& _average, Game &g, int _season, int selection, std::string name);


	friend class BTree;

};


class BTree {

	Node* root;
	int t;

public:

	BTree();
	BTree(int temp);

	void traverse();
	void gameTraverse(std::string name, std::vector<Game> &_gameVec);
	void printTraverse();
	Node* search(int date);

	void writeSeason(int selection, std::vector<float> &_average, int season, std::string _name);


//Node* search(int k);

	void insert(Game g);
	//friend class Node;

	friend class Team;

};


#endif