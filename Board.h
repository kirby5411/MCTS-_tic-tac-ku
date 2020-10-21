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
        static TDCA available;   //0 = available, 1 = occupied
        static TDCA board;
        static char players[2];  //players[0] is o, players[1] is x
        static char current_player;
        static int current_big_row;    //starting from 0 to 2
        static int current_big_column; //starting from 0 to 2
        static int previous_move_row;      //to determine legal move
        static int previous_move_column;   //to determine legal move
        static int player1_score; //save o score
        static int player2_score; //save x score
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
        void close_current_big(int current_big_row,int current_big_column,TDCA cavailable){
            for(int i=current_big_column*3;i<current_big_column*3+3;i++){
                for(int j=current_big_row*3;j<current_big_row*3+3;j++){
                    cavailable.Arr[j][i]='1';
                }
            }
        }

        vector<coordinate> get_legal_move(int vlast_move_row,int vlast_move_column, TDCA vavailable){
            vector<coordinate> list_of_legal_move;
            list_of_legal_move.clear(); //initialize vector
            //determine whether there is still available moves in the block
            bool this_block_full = true;
            for(int i = (vlast_move_row%3)*3; i < (vlast_move_row%3)*3+3;i++){
                for(int j = (vlast_move_column%3)*3; j < (vlast_move_column%3)*3+3;j++){
                    if(vavailable.Arr[i][j]=='0') this_block_full = false;
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
                        if(vavailable.Arr[i][j]=='o'){
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

        void random_legal_move(int last_move_row,int last_move_column,char which_player, TDCA rboard, TDCA ravailable){
            int new_move_row;
            int new_move_column;
            int pick=0;
            vector<coordinate> pick_move = get_legal_move(last_move_row, last_move_column,ravailable); // assign the list of moves to the pick_move vector
            pick = rand()%(pick_move.size()); //randomly pick a move in the legal moves
            new_move_row = pick_move[pick].xy[0];    //assign the new move's coordinate to the new_move_row
            new_move_column = pick_move[pick].xy[1]; //assign the new move's coordinate to the new_move_column
            previous_move_row = new_move_row; //update last move
            previous_move_column = new_move_column; //update last move
            rboard.Arr[new_move_row][new_move_column] = which_player;
            ravailable.Arr[new_move_row][new_move_column] = '1';
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

        bool game_end(TDCA gavailable){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(gavailable.Arr[i][j]=='0') return false;
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
