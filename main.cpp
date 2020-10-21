#include <bits/stdc++.h>
#include "Board.h"
#include "Node.h"
using namespace std;



int main()
{
  Board b;
  Node n;
    b.players[0]={'o'};
    b.players[1]={'x'};
    srand((unsigned) time(0)); // set the time as the seed of random number
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          b.available.Arr[i][j]='0'; //initialize the available spots
          b.board.Arr[i][j]=' '; //initialize the board
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
    b.current_player = b.players[0];
    if(b.current_player == 'o'){
        cout<<endl<<"Please enter the x coordinate of your move: ";
        cin>> b.previous_move_row;
        cout<<endl<<"Please enter the y coordinate of your move: ";
        cin>> b.previous_move_column;
        b.available.Arr[b.previous_move_row][b.previous_move_column] = '1';
        b.board.Arr[b.previous_move_row][b.previous_move_column] = b.current_player;
        b.current_player = b.change_current_player(b.current_player);
    }
    while(b.game_end(b.available)==false){ //keep playing until the game end
        Board::coordinate computer_move = n.MCTS(b.previous_move_row, b.previous_move_column, b.board,b.available,b.current_player);
        b.previous_move_row = computer_move.xy[0];
        b.previous_move_column = computer_move.xy[1];
        b.available.Arr[b.previous_move_row][b.previous_move_column] = '1';
        b.board.Arr[b.previous_move_row][b.previous_move_column] = b.current_player;
        b.current_player = b.change_current_player(b.current_player);
        for(int i=0;i<9;i++){
          cout<<"|";
          for(int j=0;j<9;j++){
            cout<<b.board.Arr[i][j]; // monitor the moves
            cout<<"|";
          }
          cout<<endl;
          cout<<"-------------------";
          cout<<endl;
        }
        cout<<"****************************"<<endl;
        if(b.game_end(b.available)==true){
            break;
        }
        bool is_legal = false;
        vector<Board::coordinate> legal_moves = b.get_legal_move(b.previous_move_row,b.previous_move_column,b.available);
        while(is_legal==false){
            cout<<endl<<"Please enter the x coordinate of your move: ";
            cin>> b.previous_move_row;
            cout<<endl<<"Please enter the y coordinate of your move: ";
            cin>> b.previous_move_column;
            for(int i=0;i<legal_moves.size();i++){
                if(legal_moves[i].xy[0]==b.previous_move_row&&legal_moves[i].xy[1]==b.previous_move_column){
                    is_legal=true;
                    break;
                }
            }
            if(is_legal==false){
                cout<<"Please enter a legal coordinate!"<<endl;
            }
        }
        b.available.Arr[b.previous_move_row][b.previous_move_column] = '1';
        b.board.Arr[b.previous_move_row][b.previous_move_column] = b.current_player;
        b.current_player = b.change_current_player(b.current_player);
        for(int i=0;i<9;i++){
          cout<<"|";
          for(int j=0;j<9;j++){
            cout<<b.board.Arr[i][j]; // monitor the moves
            cout<<"|";
          }
          cout<<endl;
          cout<<"-------------------";
          cout<<endl;
        }
        cout<<"****************************"<<endl;
    }
    cout<<"o won "<<b.player1_score<<" blocks"<<endl;
    cout<<"x won "<<b.player2_score<<" blocks"<<endl;
    if(b.player1_score>b.player2_score){
        cout<<"o has won!";
    }
    else if(b.player1_score<b.player2_score){
        cout<<"x has won!";
    }
    else{
        cout<<"x has won!";
    }
    return 0;
}
