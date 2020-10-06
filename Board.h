#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
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
        bool small_win(int current_big_row,int current_big_column, char[][] sboard){
            //check row
            for(int i=current_big_row*3; i<current_big_row*3+3;i++){
                int j=current_big_column*3;
                if((sboard[i][j]=='x'||sboard[i][j]=='o')&&(sboard[i][j]==sboard[i][j+1]&&sboard[i][j+2]==sboard[i][j+1])) return true;
            }
            //check column
            for(int j=current_big_column*3; j<current_big_column*3+3;j++){
                int i=current_big_row*3;
                if((sboard[i][j]=='x'||sboard[i][j]=='o')&&(sboard[i][j]==sboard[i+1][j]&&sboard[i+2][j]==sboard[i+1][j])) return true;
            }
            //check diagonal
            int i=current_big_row*3;
            int j=current_big_column*3;
            if((sboard[i][j]=='x'||sboard[i][j]=='o')&&(sboard[i][j]==sboard[i+1][j+1]&&sboard[i+2][j+2]==sboard[i+1][j+1])) return true;
            if((sboard[i+2][j]=='x'||sboard[i+2][j]=='o')&&(sboard[i+2][j]==sboard[i+1][j+1]&&sboard[i][j+2]==sboard[i+1][j+1])) return true;
            return false;
        }

        //when a big block is won, make all the small blocks inside it become unavailable
        void close_current_big(int current_big_row,int current_big_column,char[][] cavailable){
            for(int i=current_big_column*3;i<current_big_column*3+3;i++){
                for(int j=current_big_row*3;j<current_big_row*3+3;j++){
                    cavailable[j][i]='1';
                }
            }
        }

        vector<coordinate> get_legal_move(int vlast_move_row,int vlast_move_column, char[][] vavailable){
            vector<coordinate> list_of_legal_move;
            list_of_legal_move.clear(); //initialize vector
            //determine whether there is still available moves in the block
            bool this_block_full = true;
            for(int i = (vlast_move_row%3)*3; i < (vlast_move_row%3)*3+3;i++){
                for(int j = (vlast_move_column%3)*3; j < (vlast_move_column%3)*3+3;j++){
                    if(vavailable[i][j]=='0') this_block_full = false;
                }
            }
            // if the block is full, randomly pick a space in the whole board
            if(this_block_full == true){
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        if(vavailable[i][j]=='0'){
                            coordinate temp;
                            temp.xy[0]=i;
                            temp.xy[1]=j;
                            list_of_legal_move.push_back(temp);
                        }
                    }
                }
                return list_of_legal_move;
            }
            //if there are available spaces in the block
            else{
                for(int i=(vlast_move_row%3)*3;i<(vlast_move_row%3)*3+3;i++){
                    for(int j=(vlast_move_column%3)*3;j<(vlast_move_column%3)*3+3;j++){
                        if(available[i][j]=='o'){
                            coordinate temp;
                            temp.xy[0]=i;
                            temp.xy[1]=j;
                            list_of_legal_move.push_back(temp);
                        }
                    }
                }
                return list_of_legal_move;
            }
        }

        void random_legal_move(int last_move_row,int last_move_column,char which_player, char[][] rboard, char[][] ravailable){
            int new_move_row;
            int new_move_column;
            int pick=0;
            vector<coordinate> pick_move = get_legal_move(last_move_row, last_move_column,ravailable); // assign the list of moves to the pick_move vector
            pick = rand()%(pick_move.size()); //randomly pick a move in the legal moves
            new_move_row = pick_move[pick].xy[0];    //assign the new move's coordinate to the new_move_row
            new_move_column = pick_move[pick].xy[1]; //assign the new move's coordinate to the new_move_column
            previous_move_row = new_move_row; //update last move
            previous_move_column = new_move_column; //update last move
            rboard[new_move_row][new_move_column] = which_player;
            ravailable[new_move_row][new_move_column] = '1';
            if(small_win(new_move_row/3,new_move_column/3,rboard)==true){ // if placing the move will win the small block
                    close_current_big(new_move_row/3,new_move_column/3,ravailable);//close the small block
                    if(which_player=='o'){
                        player1_score++;
                    }
                    else{
                        player2_score++;
                    }
                }
                return;
            }

        char change_current_player(char who_is_playing){
            if(who_is_playing == players[0]){
                who_is_playing = players[1];
            }
            else{
                who_is_playing = players[0];
            }
            return who_is_playing;
        }

        bool game_end(char[][] gavailable){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(gavailable[i][j]=='0') return false;
                }
            }
            return true;
        }

        int reward(char starting_player){
            if(starting_player=='o'){
                if(player1_score>player2_score){
                    return 1;
                }
                else if(player1_score<player2_score){
                    return -1;
                }
                else{
                    return -1;
                }
            }
            else{
                if(player1_score>player2_score){
                    return -1;
                }
                else if(player1_score<player2_score){
                    return 1;
                }
                else{
                    return -1;
                }
            }
        }

    protected:

    private:
};

#endif // BOARD_H
