#ifndef __8PUZZLE_H_
#define __8PUZZLE_H_

#include <vector>
#include <iostream>
#include <list>
#include <stack>

class Node {
    public:
        Node(); 
        Node(std::vector<int> data, Node* parent, int cost); //construtor 
        ~Node();  //deconstructor
        void move_up(int blank);  //node.data 
        void move_down(int blank);
        void move_left(int blank);
        void move_right(int blank);
        void printData();
    private:
        std::vector<int> data; //represents puzzle
        Node* parent; //parent pointer
        int cost; //cost of moving 
};

inline bool operator ==(const std::vector<int> data1, const std::vector<int> data2) {
    bool equals = true;
    for (int i = 0; i < 8; i++)
        if (data1[i] != data2[i]) { equals = false; }
    return equals;
}

#endif 