#include "BTree.h"


//Constructor
BTree::BTree(int temp) {

	root = NULL;
	t = temp;

}

//Default constructor
BTree::BTree() {

	root = NULL;
	t = 4;

}

//Basic traversal
void BTree::traverse() {

	if (root != NULL) {

		root->traverse();

	}

}


//Node constructor
Node::Node(int temp, bool _leaf) {

	t = temp;
	leaf = _leaf;

	keys = new Game[2 * t - 1];
	c = new Node * [2 * t];
	n = 0;

}

//Node traversal using recursion
void Node::traverse() {

	int i;
	for (i = 0; i < n; i++) {

		if (leaf == false) {

			c[i]->traverse();

		}
		
	//	std::cout << " " << keys[i].season;



	}

	if (leaf == false) {

		c[i]->traverse();

	}
	//std::cout << "\n";

}

//Traverse, but print the data
void Node::PrintTraverse() {

	int i;
	for (i = 0; i < n; i++) {

		if (leaf == false) {

			c[i]->PrintTraverse();

		}

		keys[i].printData();



	}

	if (leaf == false) {

		c[i]->PrintTraverse();

	}
	//keys[i].printData();
	std::cout << "\n";


	

}



//Traverse, but write the wanted data into the _GameVec vector
void Node::gameTraverse(std::string name, std::vector<Game> &_GameVec) {

	int i;

	for (i = 0; i < n; i++) {

		if (leaf == false) {
			c[i]->gameTraverse(name, _GameVec);
		}

		if (name == keys[i].homeTeam || name == keys[i].vistorTeam) {

			_GameVec.push_back(keys[i]);

		}

		if (name == "LEAGUE") {

			_GameVec.push_back(keys[i]);

		}



	}

	if (leaf == false) {

		c[i]->gameTraverse(name, _GameVec);

	}

//	if (name == keys->homeTeam || name == keys->vistorTeam) {
	
	//	_GameVec.push_back(*keys);

	//}
	

}

//What kind of data do we want to write?
void Node::switchStat(bool _isHome, std::vector<float>& _average, Game &g, int _season, int selection, std::string name) {


	if (name == "LEAGUE") {

		switch (selection) {
		case 0:
			_average.push_back(g.homePoints);
			_average.push_back(g.awayPoints);
			break;
		case 1:
			_average.push_back(g.home2PPCT);
			_average.push_back(g.away2PPCT);
			break;
		case 2:
			_average.push_back(g.homeFTPCT);
			_average.push_back(g.awayFTPCT);
			break;
		case 3:
			_average.push_back(g.home3PPCT);
			_average.push_back(g.away3PPCT);
			break;
		case 4:
			_average.push_back(g.homeAssists);
			_average.push_back(g.awayAssists);
			break;
		case 5:
			_average.push_back(g.homeRebounds);
			_average.push_back(g.awayRebounds);
			break;
		case 6:
			_average.push_back(0);
			break;

		}
		return;

	}


	

	switch (selection) {

	case 0://Points scored
	//	std::cout << "CASE 0 TRIGGERED\n";
		if (_isHome) {
			

			_average.push_back(g.homePoints);
			break;
			
		}
		else {

			_average.push_back(g.awayPoints);
			break;

			
		}
		break;

	case 1://2-Point success rate
	//	std::cout << "CASE 1 TRIGGERED\n";
		if (_isHome) {

			_average.push_back(g.home2PPCT);

		}
		else {

			_average.push_back(g.away2PPCT);

		}
		break;

	case 2://Free throw success rate
	//	std::cout << "CASE 2 TRIGGERED\n";
		if (_isHome) {

			_average.push_back(g.homeFTPCT);


		}
		else {

			_average.push_back(g.awayFTPCT);

		}
		break;

	case 3://3-Point success rate 
	//	std::cout << "CASE 3 TRIGGERED\n";
		if (_isHome) {

			_average.push_back(g.home3PPCT);

		}
		else {

			_average.push_back(g.away3PPCT);


		}
		break;

	case 4://Assists
		//std::cout << "CASE 4 TRIGGERED\n";

		if (_isHome) {

			_average.push_back(g.homeAssists);

		}
		else {

			_average.push_back(g.awayAssists);

		}
		break;

	case 5:
	//	std::cout << "CASE 5 TRIGGERED\n";
		if (_isHome) {

			_average.push_back(g.homeRebounds);

		}
		else {

			_average.push_back(g.awayRebounds);

		}
		break;

	case 6:
	//	std::cout << "CASE 6 TRIGGERED\n";
		if (_isHome) {

			if (g.homeTeamWins) {

				_average.push_back(1);
				break;

			}
			else {

			//	std::cout << "Warriors LOST\n";

				_average.push_back(0);

			}

		}
		else {

			if (g.homeTeamWins) {

			//	std::cout << "Warriors LOST\n";

				_average.push_back(0);

			}
			else {

				_average.push_back(1);

			}


		}
		break;

	default:
		break;

	}

}


//We are at a node. If it matches what we are looking, for then we push it into the vec
void Node::writeInstance(int selection, std::vector<float>& _average, int _season, std::string name) {

	int i;

	for (i = 0; i < n; i++) {

		if (leaf == false) {

			c[i]->writeInstance(selection, _average, _season, name);

		}


		if (keys[i].season == _season) {

			bool isHome = (name == keys[i].homeTeam);
			//std::cout << "HIT ";
			switchStat(isHome, _average, keys[i], _season, selection, name);


		}
		else {


		}

	}

	if (leaf == false) {

	c[i]->writeInstance(selection, _average, _season, name);

	}


	//if (keys->season == _season) {

		
		//bool isHome = (name == keys[i].homeTeam);
		//switchStat(isHome, _average, keys[i], _season, selection);

	//}


}



void BTree::gameTraverse(std::string name, std::vector<Game> &_GameVec) {

	

	if (root != NULL) {
		//std::cout << "HITHERE";

		
		root->gameTraverse(name, _GameVec);
		
		
	}

}

void BTree::printTraverse() {
	//Print through recursion. debug
	if (root != NULL) {

		root->PrintTraverse();

	}

}



void BTree::insert(Game g) {
	//If it's the first insertion, make the root a new node
	if (root == NULL) {

		root = new Node(t, true);
		root->keys[0] = g;
		root->n = 1;

	}
	else {
		//Otherwise we add and might need to split the child node
		if (root->n == 2 * t - 1) {

			Node* s = new Node(t, false);

			s->c[0] = root;

			s->splitChild(0, root);

			int i = 0;

			if (s->keys[0].id < g.id) {

				i++;

			}

			s->c[i]->insertNonFull(g);

			root = s;
		}
		else {

			root->insertNonFull(g);

		}

	}

}

void Node::insertNonFull(Game g) {
	//If what we're inserting into is not full
	int i = n - 1;
	
	if (leaf == true) {
		//If it's a leaf
		while (i >= 0 && keys[i].id > g.id) {

			keys[i + 1] = keys[i];
			i--;

		}

		keys[i + 1] = g;
		n++;


	}
	else {
		//Otherwise
		while (i >= 0 && keys[i].id > g.id) {

			i--;

		}


		if (c[i + 1]->n == 2 * t - 1) {

			splitChild(i + 1, c[i + 1]);

			if (keys[i + 1].id < g.id) {

				i++;

			}


		}

		c[i + 1]->insertNonFull(g);
	}

}

void Node::splitChild(int i, Node* y) {

	//Create a new temporary node
	Node* z = new Node(y->t, y->leaf);
	z->n = t - 1;
	
	for (int j = 0; j < t - 1; j++) {

		z->keys[j] = y->keys[j + t];

	}

	//If y was not a leaf, then reorganize some keys
	if (y->leaf == false) {

		for (int j = 0; j < t; j++) {

			z->c[j] = y->c[j + t];

		}

	}

	y->n = t - 1;

	//Moving one over
	for (int j = n; j >= i + 1; j--) {

		c[j + 1] = c[j];

	}

	c[i + 1] = z;

	for (int j = n - 1; j >= i; j--) {

		keys[j + 1] = keys[j];

	}
	//More shifting.
	keys[i] = y->keys[t - 1];
	n++;

}

Node* BTree::search(int date) {
	//Adjust it to find
	date = date * 100;

	if (root == NULL) {

		return NULL;

	}
	else {

		return root->search(date);

	}

}


Node* Node::search(int date) {

	int i = 0;
	//Remember date is ID * 100 + X offset
	while (i < n && date > (int)keys[i].id) {

		i++;

	}

	if (keys[i].id == date) {

		keys[i].printData();
		
		//We found a hit, so print the data and check if
		//The following game was also played on that date
		return this->search(date + 1);


	}

	if (leaf) {
		
		return NULL;
	}

	return c[i]->search(date);


}


void BTree::writeSeason(int selection, std::vector<float>& _average, int season, std::string _name) {

	if (root != NULL) {

		root->writeInstance(selection, _average, season, _name);

	}

}