#pragma once
#include <vector>
#include <iostream>

struct Node {
    std::vector<int> data;
    Node* parent;
    int cost;
};

class Puzzle {
public:

    Puzzle();
    ~Puzzle();


    //Different Algos
    void BFS();

protected:
    //move up left right down
    void move_up(Node* node);
    void move_down(Node* node);
    void move_right(Node* node);
    void move_left(Node* node);

    //Utility Functions
    void printFunc(Node* node);
    int findBlank(Node* node);




private:
    Node* root = new Node();
    Node* goal = new Node();


    std::vector<int>::iterator it;
    std::vector<int> initialState = {
        1, 3, 4,
        8, 0, 2,
        7, 6, 5
    };
    std::vector<int> goalState = {
        1, 2, 3,
        8, 0, 4,
        7, 6, 5
    };
};
