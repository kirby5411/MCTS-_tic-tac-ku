#include <bits/stdc++.h>
#include "Board.h"
#include "Node.h"
using namespace std;


char players[2];  //players[0] is o, players[1] is x
char current_player;
int current_big_row;    //starting from 0 to 2
int current_big_column; //starting from 0 to 2
int previous_move_row;      //to determine legal move
int previous_move_column;   //to determine legal move
int p1_score;
int p2_score;

int main()
{
    Board b;
    Node n;
    Board::TDCA available;   //0 = available, 1 = occupied
    Board::TDCA board;
    players[0]={'o'};
    players[1]={'x'};
    srand((unsigned) time(0)); // set the time as the seed of random number
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          available.Arr[i][j]='0'; //initialize the available spots
          board.Arr[i][j]=' '; //initialize the board
        }
    }
    string pcommand;
    int pcoordinate=0;
    //bool correct_enter = false;
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

    while(b.game_end(available) == false){ //keep playing until the game end
        getline (cin,pcommand);
        if(pcommand == "player"){
            cin>>pcoordinate;
            cerr<<"success";
            previous_move_row = pcoordinate/10;
            previous_move_column = pcoordinate % 10;
            available.Arr[previous_move_row][previous_move_column] = '1';
            board.Arr[previous_move_row][previous_move_column] = current_player;
            current_player = b.change_current_player(current_player);
        }
        else if(pcommand == "genmove"){
            cerr<<"success gen";
            Board::coordinate computer_move = n.MCTS(previous_move_row, previous_move_column, board,available,current_player);
            previous_move_row = computer_move.xy[0];
            previous_move_column = computer_move.xy[1];
            available.Arr[previous_move_row][previous_move_column] = '1';
            board.Arr[previous_move_row][previous_move_column] = current_player;
            current_player = b.change_current_player(current_player);
            cout<<computer_move.xy[0]*10+computer_move.xy[1]<<endl;
        }
        //if(b.game_end(available)==true){
        //    break;
        //}
        if(b.small_win(previous_move_row/3,previous_move_column/3,board)==true){
            /*if(current_player=='o'){
                p1_score++;

            }
            else{
                p2_score++;
            }*/
            available = b.close_current_big(previous_move_row/3,previous_move_column/3,available);
            board = b.close_current_big_board(previous_move_row/3,previous_move_column/3,board,current_player);
        }
        /*current_player = b.change_current_player(current_player);
        cout<<"Computer is thinking..."<<endl;
        Board::coordinate computer_move = n.MCTS(previous_move_row, previous_move_column, board,available,current_player);
        cout<<"computer move is: ("<<computer_move.xy[0]<<","<<computer_move.xy[1]<<")"<<endl;
        previous_move_row = computer_move.xy[0];
        previous_move_column = computer_move.xy[1];
        available.Arr[previous_move_row][previous_move_column] = '1';
        board.Arr[previous_move_row][previous_move_column] = current_player;
        for(int i=0;i<9;i++){
          cout<<"|";
          for(int j=0;j<9;j++){
            cout<<board.Arr[i][j]; // monitor the moves
            cout<<"|";
          }
          cout<<endl;
          cout<<"-------------------";
          cout<<endl;
        }
        cout<<"****************************"<<endl;
        //if(b.game_end(available)==true){
            //break;
        //}
        if(b.small_win(previous_move_row/3,previous_move_column/3,board)==true){
            if(current_player=='o'){
                p1_score++;

            }
            else{
                p2_score++;
            }
            available = b.close_current_big(previous_move_row/3,previous_move_column/3,available);
            board = b.close_current_big_board(previous_move_row/3,previous_move_column/3,board,current_player);
        }
        current_player = b.change_current_player(current_player);
        bool is_legal = false;
        vector<Board::coordinate> legal_moves = b.get_legal_move(previous_move_row,previous_move_column,available);
        while(is_legal==false){
            cout<<endl<<"Please enter the x coordinate of your move: ";
            cin>> previous_move_row;
            cout<<endl<<"Please enter the y coordinate of your move: ";
            cin>> previous_move_column;
            for(int i=0;i<(int)legal_moves.size();i++){
                if(legal_moves[i].xy[0]==previous_move_row&&legal_moves[i].xy[1]==previous_move_column){
                    is_legal=true;
                    break;
                }
            }
            if(is_legal==false){
                cout<<"Please enter a legal coordinate!"<<endl;
            }
        }
        available.Arr[previous_move_row][previous_move_column] = '1';
        board.Arr[previous_move_row][previous_move_column] = current_player;
        /*for(int i=0;i<9;i++){
          cout<<"|";
          for(int j=0;j<9;j++){
            cout<<board.Arr[i][j]; // monitor the moves
            cout<<"|";
          }
          cout<<endl;
          cout<<"-------------------";
          cout<<endl;
        }
        cout<<"****************************"<<endl;
        if(b.small_win(previous_move_row/3,previous_move_column/3,board)==true){
            if(current_player=='o'){
                p1_score++;

            }
            else{
                p2_score++;
            }
            available = b.close_current_big(previous_move_row/3,previous_move_column/3,available);
            board = b.close_current_big_board(previous_move_row/3,previous_move_column/3,board,current_player);
        }
        current_player = b.change_current_player(current_player);
    }*/
    //cout<<"o won "<<p1_score<<" blocks"<<endl;
    //cout<<"x won "<<p2_score<<" blocks"<<endl;
    /*if(p1_score>p2_score){
        cout<<"o has won!";
    }
    else if(p1_score<p2_score){
        cout<<"x has won!";
    }
    else{
        cout<<"x has won!";
    }*/
    }
    return 0;
}
