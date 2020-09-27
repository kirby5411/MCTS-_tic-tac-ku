#include <bits/stdc++.h>

using namespace std;

char available[9][9];   //0 = available, 1 = occupied
char board[9][9];
char players[2]={'z','x'};  //players[0] is z, players[1] is x
char current_player;
int current_big_row;    //starting from 0 to 2
int current_big_column; //starting from 0 to 2
int previous_move_row;      //to determine legal move
int previous_move_column;   //to determine legal move

bool small_win(int current_big_row,int current_big_column){
    //check row
    for(int i=current_big_row*3; i<current_big_row*3+3;i++){
        int j=current_big_column*3;
        if((board[i][j]=='x'||board[i][j]=='o')&&(board[i][j]==board[i][j+1]&&board[i][j+2]==board[i][j+1])) return true;
    }
    //check column
    for(int j=current_big_column*3; j<current_big_column*3+3;j++){
        int i=current_big_row*3;
        if((board[i][j]=='x'||board[i][j]=='o')&&(board[i][j]==board[i+1][j]&&board[i+2][j]==board[i+1][j])) return true;
    }
    //check diagonal
    int i=current_big_row*3;
    int j=current_big_column*3;
    if((board[i][j]=='x'||board[i][j]=='o')&&(board[i][j]==board[i+1][j+1]&&board[i+2][j+2]==board[i+1][j+1])) return true;
    if((board[i][j]=='x'||board[i][j]=='o')&&(board[i+2][j]==board[i+1][j+1]&&board[i][j+2]==board[i+1][j+1])) return true;
    else return false;
}

//when a big block is won, make all the small blocks inside it become unavaliable
void close_current_big(int current_big_row,int current_big_column){
    for(int i=current_big_column*3;i<current_big_column*3+3;i++){
        for(int j=current_big_row*3;j<current_big_row*3+3;j++){
            available[i][j]='1';
        }
    }
}

void random_legal_move(int last_move_row,int last_move_column,char which_player){
    int new_move_row;
    int new_move_column;
    //determine whether there is still available moves in the block
    bool this_block_full = true;
    for(int i = (last_move_row%3)*3; i < (last_move_row%3)*3+3;i++){
        for(int j = (last_move_column%3)*3; j < (last_move_column%3)*3+3;j++){
            if(available[i][j]=='0') this_block_full = false;
        }
    }
    // if the block is full, randomly pick a space in the whole board
    if(this_block_full == true){
        while(1){
            new_move_row = rand() %8;
            new_move_column = rand() %8;
            //if the random move is available
            if(available[new_move_row][new_move_column] == '0'){ //take too much time, need fixing
                if(small_win(new_move_row/3,new_move_column/3)==true){ // if placing the move will win the small block
                    close_current_big(new_move_row/3,new_move_column/3);//close the small block
                }
                previous_move_row = new_move_row; //update last move
                previous_move_column = new_move_column; //update last move
                board[new_move_row][new_move_column] = which_player;
                available[new_move_row][new_move_column] = '1';
                return;
            }
        }
    }
    //if there are available spaces in the block
    while(1){
        new_move_row = rand() %3 + (last_move_row%3)*3;
        new_move_column = rand() %3 + (last_move_column%3)*3;
        if(available[new_move_row][new_move_column] == '0'){ //take too much time, need fixing
            if(small_win(new_move_row/3,new_move_column/3)==true){// if placing the move will win the small block
                close_current_big(new_move_row/3,new_move_column/3);//close the small block
            }
            previous_move_row = new_move_row;
            previous_move_column = new_move_column;
            board[new_move_row][new_move_column] = which_player;
            available[new_move_row][new_move_column] = '1';
            return;
        }
    }
}

void change_current_player(){
    if(current_player == players[0]){
        current_player = players[1];
    }
    else{
        current_player = players[0];
    }
}

bool game_end(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(available[i][j]=='0') return false;
        }
    }
    return true;
}

int main()
{
  int count=10;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          available[i][j]='0'; //initialize the available spots
          board[i][j]='0'; //initialize the board
        }
    }
    //initialize first move
    current_player = players[0];
    previous_move_row = rand() & 8;
    previous_move_column = rand() % 8;
    available[previous_move_row][previous_move_column] = '1';
    board[previous_move_row][previous_move_column] = current_player;
    change_current_player();
    while(game_end() == false){ //keep playing randomly until the game end
        random_legal_move(previous_move_row,previous_move_column,current_player);
        for(int i=0;i<9;i++){
          for(int j=0;j<9;j++){
            cout<<board[i][j]; // monitor the moves
          }
          cout<<endl;
        }
        cout<<"----------------------"<<endl;
        change_current_player();
        count--;
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<available[i][j]; //check the result
        }
        cout<<endl;
    }
    cout<<1;
    return 0;
}
