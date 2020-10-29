#ifndef NODE_H
#define NODE_H
#include "Board.h"
using namespace std;
class Node
{
    public:
        Board b;
        struct nodes{
            int mother;
            vector<int> sons;
            Board::coordinate action;
            int index;
            int score;
            int visit_time;
            double final_value;
            char who_now; //current player
        };
        vector<nodes> expand(int elast_move_row,int elast_move_column, Board::TDCA eavailable, int which_index, vector<nodes> etree_makeup){
            vector<Board::coordinate> children = b.get_legal_move(elast_move_row, elast_move_column, eavailable);
            int temp_size = etree_makeup.size();
            for(int i=0;i<(int)children.size();i++){
                nodes etemp; //new a node
                etemp.mother = which_index; //set up the mothers of the nodes
                etemp.index = temp_size+i; //set up the index
                etemp.action.xy[0] = children[i].xy[0];
                etemp.action.xy[1] = children[i].xy[1];
                etemp.sons.clear();
                etemp.score = 0;
                etemp.visit_time = 0;
                etemp.final_value = 0;
                etree_makeup[which_index].sons.push_back(etemp.index);
                if(etree_makeup[which_index].who_now=='o'){
                    etemp.who_now='x';
                }
                else{
                    etemp.who_now='o';
                }
                etree_makeup.push_back(etemp); //push the node into the node vector
            }
            return etree_makeup;
        }

        vector<nodes> update(int ureward, int start_node_index,vector<nodes> utree_makeup){
            int utemp = start_node_index;
            while(utree_makeup[utemp].index!=0){ // if the node is not the root
                utree_makeup[utemp].visit_time = utree_makeup[utemp].visit_time+1; // add one visit time
                if(utree_makeup[utemp].who_now==utree_makeup[start_node_index].who_now){ // whether the node has the same player as the stimulated node
                    utree_makeup[utemp].score = utree_makeup[utemp].score+ureward; // add reward to score
                }
                else{
                    if(ureward==0){
                        utree_makeup[utemp].score = utree_makeup[utemp].score+1; // add a point to the winning side
                    }
                    else{ //leave the score as it is for the losing side
                    }
                }
                utree_makeup[utemp].final_value = double(utree_makeup[utemp].score)/double(utree_makeup[utemp].visit_time); //calculate new value for the node
                utemp = utree_makeup[utemp].mother; //track back to the mother of the node
            }
            utree_makeup[utemp].visit_time = utree_makeup[utemp].visit_time + 1; //for root node
            if(utree_makeup[utemp].who_now==utree_makeup[start_node_index].who_now){ // whether the node has the same player as the stimulated node
                utree_makeup[utemp].score = utree_makeup[utemp].score + ureward; // add reward to score
            }
            else{
                if(ureward==0){
                    utree_makeup[utemp].score = utree_makeup[utemp].score+1; // add a point to the winning side
                }
                else{ //leave the score as it is for the losing side
                }
            }
            utree_makeup[utemp].final_value = double(utree_makeup[utemp].score)/double(utree_makeup[utemp].visit_time);
            return utree_makeup;
        }

        int stimulate(int slast_move_row,int slast_move_column, char swhich_player, Board::TDCA savailable, Board::TDCA sboard){
            savailable.Arr[slast_move_row][slast_move_column] = '1';
            sboard.Arr[slast_move_row][slast_move_column] = swhich_player;
            return b.random_legal_move(slast_move_row,slast_move_column,swhich_player,sboard,savailable);
        }
        nodes selection(nodes start_select,vector<nodes> stree_makeup){
            int visit_count = 0;
            double true_value=-10000;
            int index = -1;
            //cout<<"true value is "<<strue_value<<endl;
            for(int i=0;i<(int)start_select.sons.size();i++){
                visit_count += stree_makeup[start_select.sons[i]].visit_time; //add all the visit time of the sons of the root node
            }
            for(int i=0;i<(int)start_select.sons.size();i++){
                if(stree_makeup[start_select.sons[i]].visit_time == 0){
                    return stree_makeup[start_select.sons[i]];
                }
                else if(true_value < (stree_makeup[start_select.sons[i]].score/stree_makeup[start_select.sons[i]].visit_time)+(sqrt(2*log(visit_count))/(stree_makeup[start_select.sons[i]].visit_time))){
                    true_value = (stree_makeup[start_select.sons[i]].score/stree_makeup[start_select.sons[i]].visit_time)+(sqrt(2*log(visit_count))/(stree_makeup[start_select.sons[i]].visit_time));
                    index = i;
                }
                /*else if(strue_value < stree_makeup[start_select.sons[i]].final_value){
                    strue_value = stree_makeup[start_select.sons[i]].final_value;
                    sindex = i;
                }*/
            }
            //for(int i=0;i<(int)start_select.sons.size();i++){
            //    cout<<"The "<<start_select.sons[i]<<" component of the tree has a visited time of "<<stree_makeup[start_select.sons[i]].visit_time<<endl;
            //    cout<<"The "<<start_select.sons[i]<<" component of the tree has a value of "<<stree_makeup[start_select.sons[i]].score<<endl;
            //}
            //cout<<"true value is "<<strue_value<<endl;
            //cout<<"selected the "<<start_select.sons[sindex]<<" component of the tree"<<endl;
            return stree_makeup[start_select.sons[index]];
        }

        Board::coordinate MCTS(int mlast_move_row, int mlast_move_column, Board::TDCA main_board, Board::TDCA main_available, char pawn){
            vector<nodes> tree_makeup;
            Board::TDCA temp_board;
            Board::TDCA temp_available;
            nodes root; //the new root is initialized properly
            root.index=0;
            root.mother=-1;
            root.who_now = pawn;
            root.final_value = 0;
            root.visit_time = 0;
            root.score = 0;
            root.action.xy[0]=-1;
            root.action.xy[1]=-1;
            tree_makeup.push_back(root);
            int running_times = 8000; //adjust this base on your computer
            while(running_times>0){
                int temp_tree_size = 0;
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        temp_available.Arr[i][j] = main_available.Arr[i][j];
                        temp_board.Arr[i][j] = main_board.Arr[i][j];
                    }
                }
                if(tree_makeup.size()==1){
                    temp_tree_size = (int)tree_makeup.size();
                    tree_makeup = expand(mlast_move_row, mlast_move_column, temp_available, tree_makeup[0].index, tree_makeup);  //set up basic tow depth tree
                }
                nodes leave = tree_makeup[0];
                while(leave.sons.size()!=0){ //keep selecting until reach the leave
                    leave = selection(leave, tree_makeup);
                }
                if(leave.visit_time==0){//if leave hasn't been visited
                    tree_makeup = update(stimulate(leave.action.xy[0],leave.action.xy[1],leave.who_now,temp_available,temp_board),leave.index, tree_makeup);//do stimulation
                }
                else{ //if leave was visited
                    temp_tree_size = (int)tree_makeup.size();
                    tree_makeup = expand(mlast_move_row,mlast_move_column, temp_available, leave.index, tree_makeup); //expand the leave
                    for(int i=temp_tree_size; i<(int)tree_makeup.size();i++){
                        leave.sons.push_back(i);
                    }
                    leave = selection(leave, tree_makeup); //select an expanded leave
                    tree_makeup = update(stimulate(leave.action.xy[0],leave.action.xy[1],leave.who_now,temp_available,temp_board),leave.index, tree_makeup);//do stimulation
                }
                running_times--;
            }
            double max_value=-100;
            int index_of_max_value_node;
            int i=1;
            while(tree_makeup[i].mother == 0){
                if(tree_makeup[i].final_value>max_value){
                    max_value = tree_makeup[i].final_value;
                    index_of_max_value_node = i;
                }
                cout<<"The visit time of the "<<i<<" component of the tree is "<<tree_makeup[i].visit_time<<endl;
                cout<<"The reward of the "<<i<<" component of the tree is "<<tree_makeup[i].final_value<<endl;
                i++;
            }
            cout<<"selected the "<<index_of_max_value_node<<" component of the tree"<<endl;
            return tree_makeup[index_of_max_value_node].action;
        }


    protected:

    private:
};

#endif // NODE_H
