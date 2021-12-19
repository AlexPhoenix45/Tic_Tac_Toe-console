#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class X
{
private:
    string playerName;
    bool goingFirst = false;
    vector<short> placeHasGone;
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

    void setIsGoingFirst(bool goingFirst)
    {
        this->goingFirst = goingFirst;
    }
    bool getIsGoingFirst()
    {
        return goingFirst;
    }

    void addPlaceHasGone(short i)
    {
        placeHasGone.push_back(i);
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
        cout << "X";
    }
    void getMarker2()
    {
        gotoXY(getPosColumn2_y(), getPosLine1_x());
        cout << "X";
    }
    void getMarker3()
    {
        gotoXY(getPosColumn3_y(), getPosLine1_x());
        cout << "X";
    }
    void getMarker4()
    {
        gotoXY(getPosColumn1_y(), getPosLine2_x());
        cout << "X";
    }
    void getMarker5()
    {
        gotoXY(getPosColumn2_y(), getPosLine2_x());
        cout << "X";
    }
    void getMarker6()
    {
        gotoXY(getPosColumn3_y(), getPosLine2_x());
        cout << "X";
    }
    void getMarker7()
    {
        gotoXY(getPosColumn1_y(), getPosLine3_x());
        cout << "X";
    }
    void getMarker8()
    {
        gotoXY(getPosColumn2_y(), getPosLine3_x());
        cout << "X";
    }
    void getMarker9()
    {
        gotoXY(getPosColumn3_y(), getPosLine3_x());
        cout << "X";
    }
//---------------------------Winning-----------------------------
	bool ifWin()
	{
		if (true)
		{
			//3 hang ngang
			if (count(placeHasGone.begin(), placeHasGone.end(), 49))
			{
				if (count(placeHasGone.begin(), placeHasGone.end(), 50))
					if (count(placeHasGone.begin(), placeHasGone.end(), 51))
						return true;
			}

			else if (count(placeHasGone.begin(), placeHasGone.end(), 52))
			{
				if (count(placeHasGone.begin(), placeHasGone.end(), 53))
					if (count(placeHasGone.begin(), placeHasGone.end(), 54))
						return true;
			}
			else if (count(placeHasGone.begin(), placeHasGone.end(), 55))
			{
				if (count(placeHasGone.begin(), placeHasGone.end(), 56))
					if (count(placeHasGone.begin(), placeHasGone.end(), 57))
						return true;
			}
			//3 hang doc
			if (count(placeHasGone.begin(), placeHasGone.end(), 49))
			{
				if (count(placeHasGone.begin(), placeHasGone.end(), 52))
					if (count(placeHasGone.begin(), placeHasGone.end(), 55))
						return true;
			}
			else if (count(placeHasGone.begin(), placeHasGone.end(), 50))
			{
				if (count(placeHasGone.begin(), placeHasGone.end(), 53))
					if (count(placeHasGone.begin(), placeHasGone.end(), 56))
						return true;
			}
			else if (count(placeHasGone.begin(), placeHasGone.end(), 51))
			{
				if (count(placeHasGone.begin(), placeHasGone.end(), 54))
					if (count(placeHasGone.begin(), placeHasGone.end(), 57))
						return true;
			}

			//2 duong cheo
			if (count(placeHasGone.begin(), placeHasGone.end(), 49))
			{
				if (count(placeHasGone.begin(), placeHasGone.end(), 53))
					if (count(placeHasGone.begin(), placeHasGone.end(), 57))
						return true;
			}
			else if (count(placeHasGone.begin(), placeHasGone.end(), 51))
			{
				if (count(placeHasGone.begin(), placeHasGone.end(), 53))
					if (count(placeHasGone.begin(), placeHasGone.end(), 55))
						return true;
			}
		}
		else return false;
	}
};
