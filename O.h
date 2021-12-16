#include <iostream>

using namespace std;

class O
{
private:
    string playerName;
public:
    O() {}
    O(string playerName) : playerName(playerName) {}

    void setPlayerName(string playerName)
    {
        this->playerName = playerName;
    }
    string getPlayerName()
    {
        return playerName;
    }
};

