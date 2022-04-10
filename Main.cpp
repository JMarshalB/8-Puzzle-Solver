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
    
    Node root = Node{ initialState, nullptr, 0 };
    Node goal = Node{ goalState, nullptr, 0 };

    std::cout << "--------------\nInitial Puzzle\n--------------\n";
    obj.printState(&root);

    std::cout << "--------------\nGoal Puzzle\n--------------\n";
    obj.printState(&goal);
	
	obj.BFS(&root);

    //std::cout << "DONE!" << std::endl;



	return 0;
}