#include <iostream>
#include "console.h"
#include <conio.h>
#include "X.h"
#include "O.h"
#include <cstdio>
#include <vector>
#include <string>

const short consoleWidth = 120;
const short consoleHeight = 30;

using namespace std;

X playerX;
O playerO;
vector<int> isOccupied(1);

bool GameMenu()
{
    gotoXY(consoleWidth/2-(11/2), 2);
    cout << "Tic-Tac-Toe";

    int i = 0;

    gotoXY(consoleWidth/2-(7/2), 5);
    cout << "1. PLAY";
    gotoXY(consoleWidth/2-(7/2), 7);
    cout << "2. EXIT";

    while (i != 49 || i != 50)
        if (_kbhit())
        {
            i = _getch();
            if (i == 49)
            {
                clrscr();
                return true;
            }
            else if (i == 50)
            {
                clrscr();
                return false;
            }
        }
    return true;
}

void ChoosePlayer(O &playerO, X &playerX)
{
    string p1Name;
    string p2Name;
    char marker = 0;
    gotoXY(0, 0);
    cout << "Enter Player 1 Name [30]: ";
    cin >> p1Name;
    cout << "Choose your marker (Press x or o): ";
    while ((int)marker != 111 || (int)marker != 120)
    {
        if (_kbhit())
        {
            marker = _getch();
            if ((int)marker == 111)
            {
                playerO.setPlayerName(p1Name);
                cout << "o\n" << "Player " << playerO.getPlayerName() << " is going with " << (char)111 << endl;
                playerO.setIsGoingFirst(true);
                break;
            }
            else if ((int)marker == 120)
            {
                playerX.setPlayerName(p1Name);
                cout << "x\n" << "Player " << playerX.getPlayerName() << " is going with " << (char)120 << endl;
                playerX.setIsGoingFirst(true);
                break;
            }
        }
    }
    cout << "Enter Player 2 Name [30]: ";
    cin >> p2Name;
    if ((int)marker == 111)
    {
        playerX.setPlayerName(p2Name);
        cout << "Player " << playerX.getPlayerName() << " is going with " << (char)120 << endl;
    }
    else if ((int)marker == 120)
    {
        playerO.setPlayerName(p2Name);
        cout << "Player " << playerO.getPlayerName() << " is going with " << (char)111 << endl;
    }

    Sleep(500);                                                 //Phan nay se chi lam game cho 2 nguoi choi
    cout << "Get ready for the macth in ";
    for (int i = 3; i > 0; i--)
    {
        cout << i << ".. ";
        Sleep(1000);
    }
    clrscr();
}

void Square(O &playerO)
{
//------------Ke bang----------------
    drawLine(0, 36, 0, 151);
    drawLine(0, 36, 4, 151);
    drawLine(0, 36, 8, 151);
    drawLine(0, 36, 12, 151);
    drawColumn(0, 12, 0, 166);
    drawColumn(0, 12, 12, 166);
    drawColumn(0, 12, 24, 166);
    drawColumn(0, 12, 36, 166);
//-----------Ve so o moi o--------------
    if (playerO.getGameIsPlay() == false)
    {
        gotoXY(6, 2); cout << 1;
        gotoXY(18, 2); cout << 2;
        gotoXY(30, 2); cout << 3;
        gotoXY(6, 6); cout << 4;
        gotoXY(18, 6); cout << 5;
        gotoXY(30, 6); cout << 6;
        gotoXY(6, 10); cout << 7;
        gotoXY(18, 10); cout << 8;
        gotoXY(30, 10); cout << 9;
        playerO.setGameIsPlay(true);
    }
}

void placeMarker(short Position, O playerO, X playerX, bool O)
{
    if (O == true)
    {
        switch(Position)
        {
        case 49:
            playerO.getMarker1();
            break;
        case 50:
            playerO.getMarker2();
            break;
        case 51:
            playerO.getMarker3();
            break;
        case 52:
            playerO.getMarker4();
            break;
        case 53:
            playerO.getMarker5();
            break;
        case 54:
            playerO.getMarker6();
            break;
        case 55:
            playerO.getMarker7();
            break;
        case 56:
            playerO.getMarker8();
            break;
        case 57:
            playerO.getMarker9();
            break;
        default:
            break;
        }
    }
    else if (O == false)
    {
        switch(Position)
        {
        case 49:
            playerX.getMarker1();
            break;
        case 50:
            playerX.getMarker2();
            break;
        case 51:
            playerX.getMarker3();
            break;
        case 52:
            playerX.getMarker4();
            break;
        case 53:
            playerX.getMarker5();
            break;
        case 54:
            playerX.getMarker6();
            break;
        case 55:
            playerX.getMarker7();
            break;
        case 56:
            playerX.getMarker8();
            break;
        case 57:
            playerX.getMarker9();
            break;
        default:
            break;
        }
    }
}

short firstMovement(O &playerO, X &playerX, vector<int> &isOccupied)
{
    char c = '-';
    if (playerO.getIsGoingFirst() == true)
    {
        gotoXY(0, 13);
        cout << endl <<  playerO.getPlayerName() << "'s turn, enter number from 1 - 9:                                                       ";
        c = _getch();
        bool check = false;
        while (check == false)
        {
            check = true;
            for (int i = 0; i < isOccupied.size(); i++)
            {
                if (c == isOccupied[i])
                {
                    gotoXY(0, 14);
                    cout << "You choose " << c << " but that position is occupied, please choose another number:                          ";
                    c = _getch();
                    check = false;
                    break;
                }
            }
        }
        while ((c != '1' && c != '2' && c!= '3' && c!= '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9'))
        {
            if (c != '1' || c != '2' || c!= '3' || c!= '4' || c != '5' || c != '6' || c != '7' || c != '8' || c != '9')
            {
                gotoXY(0, 14);
                cout << "Number " << c << " is not correct, please choose number between 1 - 9:                                              ";
                c = _getch();
            }
            check = false;
            while (check == false)
            {
                check = true;
                for (int i = 0; i < isOccupied.size(); i++)
                {
                    if (c == isOccupied[i])
                    {
                        gotoXY(0, 14);
                        cout << "You choose " << c << " but that position is occupied, please choose another number:                          ";
                        c = _getch();
                        check = false;
                        break;
                    }
                }
            }

        }
        gotoXY(0, 14);
        cout << "                                                                                                                           ";
        gotoXY(0, 14);
        cout << "Player " << playerO.getPlayerName() << " placed marker in Position " << c << "                                             ";
        isOccupied.push_back(c);
        playerO.addPlaceHasGone(c);
        Sleep(2000);
    }

    if (playerX.getIsGoingFirst() == true)
    {
        gotoXY(0, 13);
        cout << endl << playerX.getPlayerName() << "'s turn, enter number from 1 - 9:                                                      ";
        c = _getch();
        bool check = false;
        while (check == false)
        {
            check = true;
            for (int i = 0; i < isOccupied.size(); i++)
            {
                if (c == isOccupied[i])
                {
                    gotoXY(0, 14);
                    cout << "You choose " << c << " but that position is occupied, please choose another number:                          ";
                    c = _getch();
                    check = false;
                    break;
                }
            }
        }
        while ((c != '1' && c != '2' && c!= '3' && c!= '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9'))
        {
            if (c != '1' || c != '2' || c!= '3' || c!= '4' || c != '5' || c != '6' || c != '7' || c != '8' || c != '9')
            {
                gotoXY(0, 14);
                cout << "Number " << c << " is not correct, please choose number between 1 - 9:                                              ";
                c = _getch();
            }
            check = false;
            while (check == false)
            {
                check = true;
                for (int i = 0; i < isOccupied.size(); i++)
                {
                    if (c == isOccupied[i])
                    {
                        gotoXY(0, 14);
                        cout << "You choose " << c << " but that position is occupied, please choose another number:                          ";
                        c = _getch();
                        check = false;
                        break;
                    }
                }
            }

        }
        gotoXY(0, 14);
        cout << "                                                                                                                                 ";
        gotoXY(0, 14);
        cout << "Player " << playerX.getPlayerName() << " placed marker in Position " << c << "                                                 ";
        isOccupied.push_back(c);
        playerX.addPlaceHasGone(c);
        Sleep(2000);
    }
    return c;
}

short nextMovement(O &playerO, X &playerX, vector<int> &isOccupied)
{
    gotoXY(0, 13);
    cout << "                                                                                                                                               ";
    char c = '-';
    if (playerO.getIsGoingFirst() == false)
    {
        gotoXY(0, 13);
        cout << endl << playerO.getPlayerName() << "'s turn, enter number from 1 - 9:                                                        ";
        c = _getch();
        bool check = false;
        while (check == false)
        {
            check = true;
            for (int i = 0; i < isOccupied.size(); i++)
            {
                if (c == isOccupied[i])
                {
                    gotoXY(0, 14);
                    cout << "You choose " << c << " but that position is occupied, please choose another number:                          ";
                    c = _getch();
                    check = false;
                    break;
                }
            }
        }
        while ((c != '1' && c != '2' && c!= '3' && c!= '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9'))
        {
            if (c != '1' || c != '2' || c!= '3' || c!= '4' || c != '5' || c != '6' || c != '7' || c != '8' || c != '9')
            {
                gotoXY(0, 14);
                cout << "Number " << c << " is not correct, please choose number between 1 - 9:                                              ";
                c = _getch();
            }
            check = false;
            while (check == false)
            {
                check = true;
                for (int i = 0; i < isOccupied.size(); i++)
                {
                    if (c == isOccupied[i])
                    {
                        gotoXY(0, 14);
                        cout << "You choose " << c << " but that position is occupied, please choose another number:                          ";
                        c = _getch();
                        check = false;
                        break;
                    }
                }
            }

        }
        gotoXY(0, 14);
        cout << "                                                                                                                         ";
        gotoXY(0, 14);
        cout << "Player " << playerO.getPlayerName() << " placed marker in Position " << c << "                                           ";
        isOccupied.push_back(c);
        playerO.addPlaceHasGone(c);
        Sleep(2000);
    }

    if (playerX.getIsGoingFirst() == false)
    {
        gotoXY(0, 13);
        cout << endl << playerX.getPlayerName() << "'s turn, enter number from 1 - 9:                                                      ";
        c = _getch();
        bool check = false;
        while (check == false)
        {
            check = true;
            for (int i = 0; i < isOccupied.size(); i++)
            {
                if (c == isOccupied[i])
                {
                    gotoXY(0, 14);
                    cout << "You choose " << c << " but that position is occupied, please choose another number:                          ";
                    c = _getch();
                    check = false;
                    break;
                }
            }
        }
        while ((c != '1' && c != '2' && c!= '3' && c!= '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9'))
        {
            if (c != '1' || c != '2' || c!= '3' || c!= '4' || c != '5' || c != '6' || c != '7' || c != '8' || c != '9')
            {
                gotoXY(0, 14);
                cout << "Number " << c << " is not correct, please choose number between 1 - 9:                                              ";
                c = _getch();
            }
            check = false;
            while (check == false)
            {
                check = true;
                for (int i = 0; i < isOccupied.size(); i++)
                {
                    if (c == isOccupied[i])
                    {
                        gotoXY(0, 14);
                        cout << "You choose " << c << " but that position is occupied, please choose another number:                      ";
                        c = _getch();
                        check = false;
                        break;
                    }
                }
            }

        }
        gotoXY(0, 14);
        cout << "                                                                                                   ";
        gotoXY(0, 14);
        cout << "Player " << playerX.getPlayerName() << " placed marker in Position " << c << "                      ";
        isOccupied.push_back(c);
        playerX.addPlaceHasGone(c);
        Sleep(2000);
    }
    return c;
}

bool ifOGoFirst (O playerO)
{
    if (playerO.getIsGoingFirst() == true)
        return true;
    else
        return false;
}

void clearMarker(O playerO, X playerX)
{
    for (int i = 1; i <= 9; i++)
    {
        placeMarker(i, playerO, playerX, true);
    }
}

bool ifWin(O playerO, X playerX)
{
    if (playerO.ifWin() == true)
    {
        gotoXY(0 ,14);
        cout << "Player " << playerO.getPlayerName() << " has won!!!                                                    ";
        return true;
    }
    else if (playerX.ifWin() == true)
    {
        gotoXY(0, 14);
        cout << "Player " << playerX.getPlayerName() << " has won!!!                                                    ";
        return true;
    }
    else return false;
}

bool ifDraw(O playerO, X playerX)
{
	if (isOccupied.size() == 10)
	{
		gotoXY(0, 14);
		cout << "Draw!!																									";
		return true;
	}
	else return false;
}


int main()
{
    if (GameMenu() == false)            //Thoat Game neu nguoi choi chon EXIT
        return 0;

    ChoosePlayer(playerO, playerX);     //Nhap ten va chon quan

    while (true)
    {
        //Hien thi

        Square(playerO);

        //Dieu khien
        placeMarker(firstMovement(playerO, playerX, isOccupied), playerO, playerX, ifOGoFirst(playerO));

        if (ifWin(playerO, playerX) == true)
            break;

		if (ifDraw(playerO, playerX) == true)
			break;

        placeMarker(nextMovement(playerO, playerX, isOccupied), playerO, playerX, !ifOGoFirst(playerO));

        if (ifWin(playerO, playerX) == true)
            break;

		if (ifDraw(playerO, playerX) == true)
			break;

        //Xu ly


        //Ket thuc


        Sleep(1000);
    }


    return 0;
}
