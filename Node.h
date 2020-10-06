#ifndef NODE_H
#define NODE_H
#include "Board,h"

class Node
{
    public:
        struct nodes{
            int mother;
            vector<int> sons;
            coordinate action;
            int index;
            int score;
            int visit_time;
            double final_value;
            char who_now; //current player
        };

        void expand(int elast_move_row,int elast_move_column, char[][] eavailable, nodes which_node){
            vector<coordinate> children = get_legal_move(elast_move_row, elast_move_column, eavailable);
            int temp_size = tree_makeup.size();
            for(int i=0;i<children.size();i++){
                which_node.sons.push_back(temp_size+i); //save the index of the sons of the node
                nodes etemp; //new a node
                etemp.mother = which_node.index; //set up the mothers of the nodes
                etemp.index = tree_makeup.size()+i; //set up the index
                etemp.action = children[i];
                if(which_node.who_now=='o'){
                    etemp.who_now=='x';
                }
                else{
                    etemp.who_now=='o';
                }
                tree_makeup.push_back(etemp); //push the node into the node vector
            }
        }

        void update(int ureward, int start_node_index){
            int utemp = start_node_index;
            while(tree_makeup[utemp].index!=0){ // if the node is not the root
                tree_makeup[utemp].visit_time++; // add one visit time
                if(tree_makeup[utemp].who_now==tree_makeup[start_node_index].who_now){ // whether the node has the same player as the stimulated node
                    tree_makeup[utemp].score+=ureward; // add reward to score
                }
                else{
                    tree_makeup[utemp].score-=ureward; // subtract reward from score
                }
                tree_makeup[utemp].value = double(score)/double(index); //calculate new value for the node
                utemp = tree_makeup[utemp].mother; //track back to the mother of the node
            }
            tree_makeup[utemp].visit_time++; //for root node
            if(tree_makeup[utemp].who_now==tree_makeup[start_node_index].who_now){ // whether the node has the same player as the stimulated node
                tree_makeup[utemp].score+=ureward; // add reward to score
            }
            else{
                tree_makeup[utemp].score-=ureward; // reduct reward from score
            }
            tree_makeup[utemp].value = double(score)/double(index);
            return;
        }

        int stimulate(int slast_move_row,int slast_move_column, char, swhich_player, char[][] savailable, char[][] sboard){
            char player = swhich_player;
            while(game_end(savailable)==false){
                random_legal_move(slast_move_row, slast_move_column, player, savailable, sboard); //keep playing randomly
                player = change_current_player(player); //switch turn
            }
            return reward(swhich_player);
        }

        nodes selection(nodes start_select){
            int visit_count = 0;
            int true_value=-10000;
            int index = -1;
            for(int i=0;i<start_select.sons.size();i++){
                visit_count += start_select.sons[i].visit_time;
            }
            for(int i=0;i<start_select.sons.size();i++){
                if(start_select.sons[i].visit_time = 0){
                    return start_select.sons[i];
                }
                else if(true_value < -start_select.sons[i].score/start_select.sons[i].visit_time+sqrt(2*log(visit_count))/(start_select.sons[i].visit_time)){
                    true_value = -start_select.sons[i].score/start_select.sons[i].visit_time+sqrt(2*log(visit_count))/(start_select.sons[i].visit_time);
                    index = i;
                }
            }
            return start_select.sons[index];
        }

        coordinate MCTS(int mlast_move_row, int mlast_move_column, char[][] main_board, char[][] main_available, char pawn){
            char temp_board[9][9];
            char temp_available[9][9];
            vector<nodes> tree_makeup;
            nodes root;
            root.index=0;
            root.mother=-1;
            root.who_now = pawn;
            tree_makeup.push_back(root);
            int running_times = 800;
            while(running_times>0){
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        temp_available[i][j] = main_available[i][j];
                        temp_board[i][j] = main_board[i][j];
                    }
                }
                if(tree_makeup.size()==1){
                    expand(mlast_move_row,mlast_move_column, temp_available, tree_makeup[0]); //set up basic tow depth tree
                }
                node leave = tree_makeup[0];
                while(leave.sons.size()!=0){ //keep selecting until reach the leave
                    leave = selection(leave);
                }
                if(leave.visit_time==0){ //if leave hasn't been visited
                    update(stimulate(leave.action.xy[0],leave.action.xy[1],leave.who_now,temp_available,temp_board),leave.index); //do stimulation
                }
                else{ //if leave was visited
                    expand(mlast_move_row,mlast_move_column, temp_available, tree_makeup[0]); //expand the leave
                    leave = selection(leave); //select an expanded leave
                    update(stimulate(leave.action.xy[0],leave.action.xy[1],leave.who_now,temp_available,temp_board),leave.index); //do stimulation
                }
                running_times--;
            }
            int i=0;
            double max_value=-100;
            int index_of_max_value_node;
            while(tree_makeup[i].mother==0){
                if(tree_makeup[i].value>max_value){
                    max_value = tree_makeup[i].value;
                    index_of_max_value_node = i;
                    i++;
                }
            }
            return tree_makeup[index_of_max_value_node].coordinate;
        }


    protected:

    private:
};

#endif // NODE_H
