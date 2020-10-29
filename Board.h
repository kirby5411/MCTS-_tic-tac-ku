#ifndef BOARD_H
#define BOARD_H
using namespace std;

class Board
{
    public:
        struct TDCA{
            char Arr[9][9];
        };
        struct coordinate{ //to save the coordinate of moves
            int xy[2];
        };
        bool small_win(int current_big_row,int current_big_column, TDCA sboard){
            //check row
            for(int i=current_big_row*3; i<current_big_row*3+3;i++){
                int j=current_big_column*3;
                if((sboard.Arr[i][j]=='x'||sboard.Arr[i][j]=='o')&&(sboard.Arr[i][j]==sboard.Arr[i][j+1]&&sboard.Arr[i][j+2]==sboard.Arr[i][j+1])) return true;
            }
            //check column
            for(int j=current_big_column*3; j<current_big_column*3+3;j++){
                int i=current_big_row*3;
                if((sboard.Arr[i][j]=='x'||sboard.Arr[i][j]=='o')&&(sboard.Arr[i][j]==sboard.Arr[i+1][j]&&sboard.Arr[i+2][j]==sboard.Arr[i+1][j])) return true;
            }
            //check diagonal
            int i=current_big_row*3;
            int j=current_big_column*3;
            if((sboard.Arr[i][j]=='x'||sboard.Arr[i][j]=='o')&&(sboard.Arr[i][j]==sboard.Arr[i+1][j+1]&&sboard.Arr[i+2][j+2]==sboard.Arr[i+1][j+1])) return true;
            if((sboard.Arr[i+2][j]=='x'||sboard.Arr[i+2][j]=='o')&&(sboard.Arr[i+2][j]==sboard.Arr[i+1][j+1]&&sboard.Arr[i][j+2]==sboard.Arr[i+1][j+1])) return true;
            return false;
        }

        //when a big block is won, make all the small blocks inside it become unavailable
        TDCA close_current_big(int current_big_row,int current_big_column,TDCA cavailable){
            for(int i=current_big_column*3;i<current_big_column*3+3;i++){
                for(int j=current_big_row*3;j<current_big_row*3+3;j++){
                    cavailable.Arr[j][i]='1';
                }
            }
            return cavailable;
        }

        TDCA close_current_big_board(int current_big_row,int current_big_column,TDCA cboard, char cplayer){
            for(int i=current_big_column*3;i<current_big_column*3+3;i++){
                for(int j=current_big_row*3;j<current_big_row*3+3;j++){
                    cboard.Arr[j][i]=cplayer;
                }
            }
            return cboard;
        }

        vector<coordinate> get_legal_move(int vlast_move_row,int vlast_move_column, TDCA vavailable){
            vector<coordinate> list_of_legal_move;
            list_of_legal_move.clear(); //initialize vector
            //determine whether there is still available moves in the block
            bool this_block_full = true;
            for(int i = (vlast_move_row%3)*3; i < (vlast_move_row%3)*3+3;i++){
                for(int j = (vlast_move_column%3)*3; j < (vlast_move_column%3)*3+3;j++){
                    if(vavailable.Arr[i][j]=='0'){
                        this_block_full = false;
                    }
                }
            }
            // if the block is full, randomly pick a space in the whole board
            if(this_block_full == true){
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        if(vavailable.Arr[i][j]=='0'){
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
                        if(vavailable.Arr[i][j]=='0'){
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

        int random_legal_move(int last_move_row,int last_move_column,char which_player, TDCA rboard, TDCA ravailable){
            int player1_score = 0;
            int player2_score = 0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(small_win(i,j,rboard)==true){
                        if(rboard.Arr[i*3][j*3]=='o'){
                            player1_score++;
                        }
                        else{
                            player2_score++;
                        }
                    }
                }
            }
            int new_move_row = last_move_row;
            int new_move_column = last_move_column;
            char rstarting_player = which_player;
            while(game_end(ravailable)==false){
                int pick=0;
                vector<coordinate> pick_move = get_legal_move(new_move_row, new_move_column,ravailable); // assign the list of moves to the pick_move vector
                pick = rand()%(pick_move.size()); //randomly pick a move in the legal moves
                new_move_row = pick_move[pick].xy[0];    //assign the new move's coordinate to the new_move_row
                new_move_column = pick_move[pick].xy[1]; //assign the new move's coordinate to the new_move_column
                rboard.Arr[new_move_row][new_move_column] = which_player;
                ravailable.Arr[new_move_row][new_move_column] = '1';
                if(small_win(new_move_row/3,new_move_column/3,rboard)==true){ // if placing the move will win the small block
                    ravailable = close_current_big(new_move_row/3,new_move_column/3,ravailable);//close the small block
                    rboard = close_current_big_board(new_move_row/3,new_move_column/3,rboard,which_player);
                    if(which_player=='o'){
                        player1_score++;
                    }
                    else{
                        player2_score++;
                    }
                }
                which_player = change_current_player(which_player);
            }
            return reward(rstarting_player, player1_score, player2_score);
        }


        char change_current_player(char who_is_playing){
            if(who_is_playing == 'o'){
                who_is_playing = 'x';
            }
            else{
                who_is_playing = 'o';
            }
            return who_is_playing;
        }

        bool game_end(TDCA gavailable){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(gavailable.Arr[i][j]=='0') return false;
                }
            }
            return true;
        }

        int reward(char starting_player,int rplayer1_score, int rplayer2_score){
            if(starting_player=='o'){
                if(rplayer1_score>rplayer2_score){
                    return 1;
                }
                else if(rplayer1_score<rplayer2_score){
                    return 0;
                }
                else{
                    return 0;
                }
            }
            else{
                if(rplayer1_score>rplayer2_score){
                    return 0;
                }
                else if(rplayer1_score<rplayer2_score){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }

    protected:

    private:
};

#endif // BOARD_H
