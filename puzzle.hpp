#pragma once
#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>

struct Node {
    std::vector<int> data;
    Node* parent;
    int cost;
    std::vector<Node*> childern = {};

};

class Puzzle {
public:

    Puzzle();
    ~Puzzle();


    //Different Algos
    void BFS(Node node);
    bool DFS(Node* node);
    void Dijkstra(Node node);

    //Public Utility
    void printState (Node* node);

protected:
    //move up left right down
    void move_up(Node* node, int bSpace);
    void move_down(Node* node, int bSpace);
    void move_right(Node* node, int bSpace);
    void move_left(Node* node, int bSpace);
    

    //Utility Functions
    int findBlank(Node* node);
    void expandNode(Node* node);
    bool stateInList(Node* node, std::list<Node*> list);
    bool stateInVector(Node* node, std::vector<Node*> vector);
    void path(Node* node);


private:
    std::list<Node*> visitedDFSList;

    std::vector<int> goalState = {
    1, 2, 3,
    8, 0, 4,
    7, 6, 5
    };
};

inline bool operator ==(const std::vector<int> data1, const std::vector<int> data2) {
    bool equals = true;
    for (int i = 0; i < 9; i++)
        if (data1[i] != data2[i]) { equals = false; }
    return equals;
}

