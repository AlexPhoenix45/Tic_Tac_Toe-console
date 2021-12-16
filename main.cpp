#include <iostream>
#include <string>
#include "console.h"
#include <conio.h>
#include "X.h"
#include "O.h"

const short consoleWidth = 120;
const short consoleHeight = 30;

using namespace std;

X playerX;
O playerO;

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
    cout << "Choose your marker (x or o): ";
    while ((int)marker != 111 || (int)marker != 120)
    {
        cin >> marker;
        if ((int)marker == 111)
        {
            playerO.setPlayerName(p1Name);
            cout << "Player " << playerO.getPlayerName() << " is going with " << (char)111 << endl;
            break;
        }
        else if ((int)marker == 120)
        {
            playerX.setPlayerName(p1Name);
            cout << "Player " << playerX.getPlayerName() << " is going with " << (char)120 << endl;
            break;
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
        playerO.setPlayerName(p1Name);
        cout << "Player " << playerO.getPlayerName() << " is going with " << (char)111 << endl;
    }

    clrscr();
}


int main()
{
    while (true)
    {
    //Hien thi
    if (GameMenu() == false)
        break;

    ChoosePlayer(playerO, playerX);
    //Dieu khien



    //Xu ly


    //Ket thuc
    Sleep(5000);
    }


    return 0;
}
