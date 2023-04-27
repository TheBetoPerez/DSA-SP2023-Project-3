#include "Game.h"
#include <map>
#include <vector>
#ifndef PROJ3DSA_BPLUSTREE_H
#define PROJ3DSA_BPLUSTREE_H
class BPlusTree{
    std::map<unsigned int, Game> tree;
public:
    BPlusTree();
    void insert(Game game);
    void traverse();
    void gameTraverse(std::string name, std::vector<Game> &_gameVec);
    unsigned int search(int date);
    void writeSeason(int selection, std::vector<float> &_average, int season, std::string _name);
};
#endif //PROJ3DSA_BPLUSTREE_H
