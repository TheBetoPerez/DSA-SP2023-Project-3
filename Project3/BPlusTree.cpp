#include "BPlusTree.h"

BPlusTree::BPlusTree(){}
void BPlusTree::insert(Game game){
    tree[game.id] = game;
}
void BPlusTree::traverse(){
    for(auto it : tree){
        //std:: cout << it.second.id << " " << it.second.vistorTeam << std::endl;
    }
}
void BPlusTree::gameTraverse(std::string name, std::vector<Game> &_gameVec){
    for(auto it : tree){
        if(it.second.homeTeam == name || it.second.vistorTeam == name){
            _gameVec.push_back(it.second);
        }
    }
}
unsigned int BPlusTree::search(int date){
    tree[date].printData();
    return 0;
}
void BPlusTree::writeSeason(int selection, std::vector<float> &average, int season, std::string name) {

    bool isHome = false;
    for (auto it: tree) {
        
        if (true){
            if (it.second.homeTeam == name) {
                isHome = true;
            } else {
                isHome = false;
            }
            std::cout << "CALLED\n";

        switch (selection) {
            case 0:
                if (isHome) {
                    average.push_back(it.second.homePoints);
                } else {
                    average.push_back(it.second.awayPoints);
                }
                break;
            case 1:
                if (isHome) {
                    average.push_back(it.second.home2PPCT);
                } else {
                    average.push_back(it.second.away2PPCT);
                }
                break;
            case 2:
                if (isHome) {

                    average.push_back(it.second.homeFTPCT);


                } else {

                    average.push_back(it.second.awayFTPCT);

                }
                break;
            case 3:
                if (isHome) {
                    average.push_back(it.second.home3PPCT);
                } else {
                    average.push_back(it.second.away3PPCT);
                }
                break;
            case 4:
                if (isHome) {

                    average.push_back(it.second.homeAssists);

                } else {

                    average.push_back(it.second.awayAssists);

                }
                break;
            case 5:
                if (isHome) {

                    average.push_back(it.second.homeRebounds);

                } else {

                    average.push_back(it.second.awayRebounds);

                }
                break;
            case 6:
                if (isHome) {
                    if (it.second.homeTeamWins) {

                        average.push_back(1);
                        break;

                    } else {

                        average.push_back(0);

                    }
                } else {
                    if (it.second.homeTeamWins) {

                        average.push_back(0);

                    } else {

                        average.push_back(1);

                    }
                }
                break;
            default:
                break;
        }
    }
    }

}


