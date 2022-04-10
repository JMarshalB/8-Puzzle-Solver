#pragma once
#include <vector>
#include <iostream>
#include <list>
#include <stack>

struct Node {
    std::vector<int> data;
    Node* parent;
    int cost;
    std::vector<Node> childern = {};
};

class Puzzle {
public:

    Puzzle();
    ~Puzzle();


    //Different Algos
    void BFS(Node* node);
    bool DFS(Node* node);
    //NEED Dijkstra Algo

    //Public Utility
    void printState (Node* node);

protected:
    //move up left right down
    Node move_up(Node node, int bSpace);
    Node move_down(Node node, int bSpace);
    Node move_right(Node node, int bSpace);
    Node move_left(Node node, int bSpace);
    

    //Utility Functions
    int findBlank(Node* node);
    void expandNode(Node* node, std::vector<Node> *vector);
    bool stateInList(Node* node, std::vector<Node> list);
    void path(Node* node);


private:
    std::vector<int>::iterator it;
    std::list<Node> dfsOpenList;
    std::list<Node> dfsClosedList;



    std::vector<int> goalState = {
    1, 2, 3,
    8, 0, 4,
    7, 6, 5
    };
};

inline bool operator ==(const std::vector<int> data1, const std::vector<int> data2) {
    bool equals = true;
    for (int i = 0; i < 8; i++)
        if (data1[i] != data2[i]) { equals = false; }
    return equals;
}