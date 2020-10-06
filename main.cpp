#include <bits/stdc++.h>
#include "Board.h"
using namespace std;



int main()
{
    srand((unsigned) time(0)); // set the time as the seed of random number
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          available[i][j]='0'; //initialize the available spots
          board[i][j]=' '; //initialize the board
        }
    }
    //initialize first move
    current_player = players[0];
    previous_move_row = rand() & 8;
    previous_move_column = rand() % 8;
    available[previous_move_row][previous_move_column] = '1';
    board[previous_move_row][previous_move_column] = current_player;
    change_current_player();
    while(game_end()==false){ //keep playing randomly until the game end
        random_legal_move(previous_move_row,previous_move_column,current_player);
        for(int i=0;i<9;i++){
          cout<<"|";
          for(int j=0;j<9;j++){
            cout<<board[i][j]; // monitor the moves
            cout<<"|";
          }
          cout<<endl;
          cout<<"-------------------";
          cout<<endl;
        }
        cout<<"****************************"<<endl;
        current_player = change_current_player(current_player);
    }
    cout<<"o won "<<player1_score<<" blocks"<<endl;
    cout<<"x won "<<player2_score<<" blocks"<<endl;
    if(player1_score>player2_score){
        cout<<"o has won!";
    }
    else if(player1_score<player2_score){
        cout<<"x has won!";
    }
    else{
        cout<<"It's a tie!";
    }
    return 0;
}
