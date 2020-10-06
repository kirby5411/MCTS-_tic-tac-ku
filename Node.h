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

        vector<nodes> tree_makeup;
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
                    tree_makeup[utemp].score-=ureward; // reduct reward from score
                }
                tree_makeup[utemp].value = double(score)/double(index); //calculate new value for the node
                utemp = tree_makeup[utemp].mother; //track back to the mother of the node
            }
            tree_makeup[utemp].visit_time++;
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

        void selection(){
            //help
        }
        Node();
        virtual ~Node();

    protected:

    private:
};

#endif // NODE_H
