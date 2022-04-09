#include "puzzle.hpp"

int main() {
    Puzzle obj;

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
    
    Node* root = new Node{ initialState, nullptr, 0 };
    Node* goal = new Node{ goalState, nullptr, 0 };

    std::cout << "--------------\nInitial Puzzle\n--------------\n";
    obj.printFunc(root);

    std::cout << "--------------\nGoal Puzzle\n--------------\n";
    obj.printFunc(goal);


	
	obj.BFS(root);


	return 0;
}