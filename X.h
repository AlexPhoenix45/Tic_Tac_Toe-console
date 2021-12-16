#include <iostream>

using namespace std;

class X
{
private:
    string playerName;
public:
    X() {}
    X(string playerName) : playerName(playerName) {}

    void setPlayerName(string playerName)
    {
        this->playerName = playerName;
    }
    string getPlayerName()
    {
        return playerName;
    }
};
