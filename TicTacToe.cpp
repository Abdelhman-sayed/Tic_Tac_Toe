/*FACULTY OF COMPUTERS AND ARTIFICIAL INTELLIGENCE, CAIRO UNIVERSITY
Author : Abdelrhman sayed ali
Program Name: Tick Tac Toe Game.c plus plus*/
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <map>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <array>
using namespace std;

int counterPX = 0;
int counterPO = 0;
string PlayerX;
string PlayerO;

//bool end = false;
/*
This variable flag(X,O) to avoid enter the same condition more than one
not count 1 in counters in same condition again
*/
int flag1_x = 0, flag2_x = 0, flag3_x = 0, flag4_x = 0, flag5_x = 0, flag6_x = 0, flag7_x = 0, flag8_x = 0;
int flag1_o = 0, flag2_o = 0, flag3_o = 0, flag4_o = 0, flag5_o = 0, flag6_o = 0, flag7_o = 0, flag8_o = 0;

void drawBoard(int& counterPX, int& counterPo, char board[3][3]);
void inputPlayerX(char board[3][3]);
int checkPlayerX(char board[3][3]);
void inputPlayerO(char board[3][3]);
int checkPlayerO(char board[3][3]);
int checkWinner(int& counterPX, int& counterPo, char board[3][3]);
void fun(int& counterPX, int& counterPo, char board[3][3]);

int main()
{

    system("cls");
    cout << "\n\n                                    <<-------WELCOME USER IN THIS GAME------->>\n" << endl;
    cout << "\n\n                                           *****Tick Tac Toe Game*****\n" << endl;
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    cout << "\t Player1 [X]\n\t Player2 [O]\n\n";
    fun(counterPX, counterPO, board);
}

void drawBoard(int& counterPX, int& counterPO, char board[3][3])
{
    cout << "\t Score Of Player1 [X] is : " << counterPX
        << "\n\t Score Of Player2 [O] is : " << counterPO << "\n\n";
    cout << "\t\t----------------\n";
    cout << "\t\t|    |    |    |\n";
    cout << "\t\t|  " << board[0][0] << " |  " << board[0][1] << " |  " << board[0][2] << " |\n";
    cout << "\t\t ____|____|____|\n";
    cout << "\t\t|    |    |    |\n";
    cout << "\t\t|  " << board[1][0] << " |  " << board[1][1] << " |  " << board[1][2] << " |\n";
    cout << "\t\t ____|____|____\n";
    cout << "\t\t|    |    |    |\n";
    cout << "\t\t|  " << board[2][0] << " |  " << board[2][1] << " |  " << board[2][2] << " |\n";
    cout << "\t\t|    |    |    |\n";
    cout << "\t\t----------------\n";
}


void inputPlayerX(char board[3][3])
{
    cout << "\n>>>Enter player [X] the position you want to play in it : \n";
    cin >> PlayerX;
    regex filter("[1-9]?");

    if (regex_match(PlayerX, filter))
    {
        int Player1 = stoi(PlayerX);
        if (board[(Player1 / 3)][Player1 % 3 - 1] != 'X' && board[(Player1 / 3)][Player1 % 3 - 1] != 'O')
        {
            
            board[(Player1 / 3)][Player1 % 3 - 1] = 'X';
        }
        else
        {
            cout << "\n**** Try again please player number one! ****\n";
            inputPlayerX(board);
        }
    }
    else
    {
        cout << "\n**** Try again please player number one! ****\n";
        inputPlayerX(board);
    }
}

int checkPlayerX(char board[3][3])
{

    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' && (flag1_x == 0))
    {
        counterPX += 1;
        flag1_x = 1;
    }

    else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' && (flag2_x == 0))
    {
        counterPX += 1;
        flag2_x = 1;
    }

    else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' && (flag3_x == 0))
    {
        counterPX += 1;
        flag3_x = 1;
    }

    else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' && (flag4_x == 0))
    {
        counterPX += 1;
        flag4_x = 1;
    }
    
    else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' && (flag5_x == 0))
    {
        counterPX += 1;
        flag5_x = 1;
    }
    else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' && (flag6_x == 0))
    {
        counterPX += 1;
        flag6_x = 1;
    }

    else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' && (flag7_x == 0))
    {
        counterPX += 1;
        flag7_x = 1;
    }
    else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X' && (flag8_x == 0))
    {
        counterPX += 1;
        flag8_x = 1;
    }
    else
    {
        counterPX += 0;
    }

    return counterPX;

}

void inputPlayerO(char board[3][3])
{
    if ((board[0][0] == 'X' || board[0][0] == 'O') && (board[0][1] == 'X' || board[0][1] == 'O') &&
        (board[0][2] == 'X' || board[0][2] == 'O') && (board[1][0] == 'X' || board[1][0] == 'O') &&
        (board[1][1] == 'X' || board[1][1] == 'O') && (board[1][2] == 'X' || board[1][2] == 'O') &&
        (board[0][1] == 'X' || board[0][1] == 'O') && (board[0][1] == 'X' || board[0][1] == 'O')
        && (board[2][0] == 'X' || board[2][0] == 'O') && (board[2][1] == 'X' || board[2][1] == 'O')
        && (board[2][2] == 'X' || board[2][2] == 'O'))
    {
        //flag = true;
       checkWinner(counterPX, counterPO, board);
    }
    else
    {
        cout << "\n>>>Enter player [O] the position you want to play in it : \n";
        cin >> PlayerO;

        int Player2 = stoi(PlayerO);
        regex filter("[1-9]?");
        if(regex_match(PlayerO, filter)) 
        { 
             if (board[(Player2 / 3)][Player2 % 3 - 1] != 'X' && board[(Player2 / 3)][Player2 % 3 - 1] != 'O')
            {
                
                board[(Player2 / 3)][Player2 % 3 - 1] = 'O';
                checkPlayerO(board);
            }
            else
            {
                cout << "\n**** Try again please player number one! ****\n";
                inputPlayerO(board);
            }
        }
        else
        {
            cout << "\n**** Try again please player number one! ****\n";
            inputPlayerO(board);
        }
        fun(counterPX, counterPO, board);
    }
    
}



int checkPlayerO(char board[3][3])
{

    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' && (flag1_o == 0))
    {
       
        counterPO += 1;
        flag1_o = 1;
    }
    else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' && (flag2_o == 0))
    {
        counterPO += 1;
        flag2_o = 1;
    }
    else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' && (flag3_o == 0))
    {
        counterPO += 1;
        flag3_o = 1;
    }

    else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' && (flag4_o == 0))
    {
        counterPO += 1;
        flag4_o = 1;
    }
    else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' && (flag5_o == 0))
    {
        counterPO += 1;
        flag5_o = 1;
    }
    else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' && (flag6_o == 0))
    {
        counterPO += 1;
        flag6_o = 1;
    }

    else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' && (flag7_o == 0))
    {
        counterPO += 1;
        flag7_o = 1;
    }
    else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O' && (flag8_o == 0))
    {
        counterPO += 1;
        flag8_o = 1;
    }
    else
    {
        counterPO += 0;
    }

    return counterPO;

}

int checkWinner(int& counterPX, int& counterPO, char board[3][3])
{
    
    if ((counterPO < counterPX))
    {
        cout << "\n\n           *** Score Of Player1 [X] is : " << counterPX << " ***";
        cout << "\n\n           *** Score Of Player2 [O] is : " << counterPO << " *** \n";
        cout << "\n      ***** PLAYER NUMBER ONE --->>> PLAYER[X] ONE IS WINNER *****\n\n" << endl;
        return 0;
    }
    else if ((counterPO > counterPX))
    {
        cout << "\n\n           *** Score Of Player1 [X] is : " << counterPX << " ***";
        cout << "\n\n           *** Score Of Player2 [O] is : " << counterPO << " *** \n";
        cout << "\n      *****PLAYER NUMBER TWO --->>> PLAYER[O]  TWO IS WINNER*****\n\n" << endl;
        return 0;
    }
    else if ((counterPO == counterPX))
    {
        cout << "\n\n           *** Score Of Player1 [X] is : " << counterPX << " ***";
        cout << "\n\n           *** Score Of Player2 [O] is : " << counterPO << " *** \n";
        cout << "\n              *****//The players are Draw//*****\n\n";
        return 0;
        

    }
}

void fun(int& counterPX, int& counterPO, char board[3][3])
{

    drawBoard(counterPX, counterPO, board);
    inputPlayerX(board);
    checkPlayerX(board);
    drawBoard(counterPX, counterPO, board);
    inputPlayerO(board);
}
