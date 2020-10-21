#include <bits/stdc++.h>
#include "Board.h"
#include "Node.h"
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
    bool correct_enter = false;
    //initialize first move
    /*while(correct_enter==false){
        cout<<"Enter 1 if you want to go first. Enter 2 if you don't want to."<<endl;
        int first_or_not;
        cin>>first_or_not;
        if(first_or_not==1){
            current_player = player[0];
            correct_enter=true;
        }
        else if(first_or_not==2){
            current_player = player[1];
            correct_enter=true;
        }
        else{
            cout<<"Please enter a valid choice."<<endl;
        }
    }*/
    current_player = players[0];
    if(current_player == 'o'){
        cout<<endl<<"Please enter the x coordinate of your move: ";
        cin>> previous_move_row;
        cout<<endl<<"Please enter the y coordinate of your move: ";
        cin>>previous_move_column;
        available[previous_move_row][previous_move_column] = '1';
        board[previous_move_row][previous_move_column] = current_player;
        current_player = change_current_player(current_player);
    }
    while(game_end()==false){ //keep playing until the game end
        coordinate computer_move = MCTS(previous_move_row, previous_move_column, board,available,current_player);
        previous_move_row = computer_move.xy[0];
        previous_move_column = computer_move.xy[1];
        available.Arr[previous_move_row][previous_move_column] = '1';
        board.Arr[previous_move_row][previous_move_column] = current_player;
        current_player = charge_current_player(current_player);
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
        if(game_end()==true){
            break;
        }
        bool is_legal = false;
        vector<coordinate> legal_moves = get_legal_move(previous_move_row,previous_move_column,available);
        while(is_legal==false){
            cout<<endl<<"Please enter the x coordinate of your move: ";
            cin>> previous_move_row;
            cout<<endl<<"Please enter the y coordinate of your move: ";
            cin>>previous_move_column;
            for(int i=0;i<legal_moves.size();i++){
                if(legal_moves[i].xy[0]==previous_move_row&&legal_moves[i].xy[1]==previous_move_column){
                    is_legal=true;
                    break;
                }
            }
            if(is_legal==false){
                cout<<"Please enter a legal coordinate!"<<endl;
            }
        }
        available[previous_move_row][previous_move_column] = '1';
        board[previous_move_row][previous_move_column] = current_player;
        current_player = change_current_player(current_player);
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
        cout<<"x has won!";
    }
    return 0;
}
