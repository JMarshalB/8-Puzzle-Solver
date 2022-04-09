#pragma once
#include <vector>
#include <iostream>
#include <list>

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
    void BFS(Node* node);
    //Need DFS
    //NEED Dijkstra Algo

    //Public Utility
    void printFunc(Node* node);

protected:
    //move up left right down
    void move_up(Node* node, int bSpace);
    void move_down(Node* node, int bSpace);
    void move_right(Node* node, int bSpace);
    void move_left(Node* node, int bSpace);
    

    //Utility Functions
    int findBlank(Node* node);
    void expandNode(Node* node);




private:
    std::vector<int>::iterator it;

    std::vector<int> goalState = {
    1, 2, 3,
    8, 0, 4,
    7, 6, 5
    };
};
