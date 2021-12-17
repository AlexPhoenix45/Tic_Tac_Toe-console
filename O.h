#include <iostream>

using namespace std;

class O
{
private:
    string playerName;
    bool goingFirst = false;
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

    void setIsGoingFirst(bool goingFirst)
    {
        this->goingFirst = goingFirst;
    }
    bool getIsGoingFirst()
    {
        return goingFirst;
    }
//-----------------------Position------------------------
    int getPosLine1_x()
    {
        return 2;
    }
    int getPosLine2_x()
    {
        return 6;
    }
    int getPosLine3_x()
    {
        return 10;
    }
    int getPosColumn1_y()
    {
        return 6;
    }
    int getPosColumn2_y()
    {
        return 18;
    }
    int getPosColumn3_y()
    {
        return 30;
    }
//----------------------Marker---------------------------
    void getMarker1()
    {
        gotoXY(getPosColumn1_y(), getPosLine1_x());
        cout << "O";
    }
    void getMarker2()
    {
        gotoXY(getPosColumn2_y(), getPosLine1_x());
        cout << "O";
    }
    void getMarker3()
    {
        gotoXY(getPosColumn3_y(), getPosLine1_x());
        cout << "O";
    }
    void getMarker4()
    {
        gotoXY(getPosColumn1_y(), getPosLine2_x());
        cout << "O";
    }
    void getMarker5()
    {
        gotoXY(getPosColumn2_y(), getPosLine2_x());
        cout << "O";
    }
    void getMarker6()
    {
        gotoXY(getPosColumn3_y(), getPosLine2_x());
        cout << "O";
    }
    void getMarker7()
    {
        gotoXY(getPosColumn1_y(), getPosLine3_x());
        cout << "O";
    }
    void getMarker8()
    {
        gotoXY(getPosColumn2_y(), getPosLine3_x());
        cout << "O";
    }
    void getMarker9()
    {
        gotoXY(getPosColumn3_y(), getPosLine3_x());
        cout << "O";
    }
};

