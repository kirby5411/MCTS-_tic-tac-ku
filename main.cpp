#include <bits/stdc++.h>

using namespace std;

char available[9][9];   //0 = available, 1 = occupied
char board[9][9];
char players[2]={'o','x'};  //players[0] is o, players[1] is x
char current_player;
int current_big_row;    //starting from 0 to 2
int current_big_column; //starting from 0 to 2
int previous_move_row;      //to determine legal move
int previous_move_column;   //to determine legal move
int player1_score; //save o score
int player2_score; //save x score
struct coordinate{ //to save the coordinate of moves
    int xy[2];
};
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
    if((board[i+2][j]=='x'||board[i+2][j]=='o')&&(board[i+2][j]==board[i+1][j+1]&&board[i][j+2]==board[i+1][j+1])) return true;
    return false;
}

//when a big block is won, make all the small blocks inside it become unavailable
void close_current_big(int current_big_row,int current_big_column){
    for(int i=current_big_column*3;i<current_big_column*3+3;i++){
        for(int j=current_big_row*3;j<current_big_row*3+3;j++){
            available[j][i]='1';
        }
    }
}

//get the coordinate of a random move(time-saving method)
struct coordinate get_random_move(int a, int b){
    int count=0; //to determine when to skip to the next column
    int x=a;
    int y=b;
    while(available[x][y]=='1'){
        if(x==8){
            x=-1;
        }
        x++;
        count++;
        if(count==9){
            if(y==8){
                y=-1;
            }
            y++;
            count=0;
        }
    }
    struct coordinate result;
    result.xy[0]=x;
    result.xy[1]=y;
    return result;
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
            new_move_row = rand() %8;    //create two random input to the function get_random_move
            new_move_column = rand() %8;
            struct coordinate new_move = get_random_move(new_move_row, new_move_column);
            new_move_row = new_move.xy[0];    //assign the new move's coordinate to the new_move_row
            new_move_column = new_move.xy[1]; //assign the new move's coordinate to the new_move_column
            previous_move_row = new_move_row; //update last move
            previous_move_column = new_move_column; //update last move
            board[new_move_row][new_move_column] = which_player;
            available[new_move_row][new_move_column] = '1';
            if(small_win(new_move_row/3,new_move_column/3)==true){ // if placing the move will win the small block
                close_current_big(new_move_row/3,new_move_column/3);//close the small block
                if(which_player=='o'){
                    player1_score++;
                }
                else{
                    player2_score++;
                }
            }
            return;
        }
    }
    //if there are available spaces in the block
    while(1){
        new_move_row = rand() %3 + (last_move_row%3)*3;
        new_move_column = rand() %3 + (last_move_column%3)*3;
        if(available[new_move_row][new_move_column] == '0'){ //take too much time, need fixing
            previous_move_row = new_move_row;
            previous_move_column = new_move_column;
            board[new_move_row][new_move_column] = which_player;
            available[new_move_row][new_move_column] = '1';
            if(small_win(new_move_row/3,new_move_column/3)==true){// if placing the move will win the small block
                close_current_big(new_move_row/3,new_move_column/3);//close the small block
                if(which_player=='o'){
                    player1_score++;
                }
                else{
                    player2_score++;
                }
            }
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
        change_current_player();
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
