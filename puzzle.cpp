#include "puzzle.hpp"

Puzzle::Puzzle() {
	root->data = initialState;
	root->parent = nullptr;
	root->cost = 0;

	goal->data = goalState;
}

Puzzle::~Puzzle(){
	delete root;
	delete goal;

}

//NOT FINISHED YET
void Puzzle::BFS() {
	std::cout << "--------------\nInitial Puzzle\n--------------\n";
	printFunc(root);

	std::cout << "--------------\nGoal Puzzle\n--------------\n";
	printFunc(goal);
	
	int blankSpacePos;
	std::vector<int> blankSpace;
	bool goalState = false;

	while (!goalState) {
		blankSpacePos = findBlank(root);
	}

}

//move up left right down
void Puzzle::move_up(Node* node) {
	


}

void Puzzle::move_down(Node* node) {



}

void Puzzle::move_right(Node* node) {



}

void Puzzle::move_left(Node* node) {



}

//Prints the current puzzle within a node
void Puzzle::printFunc(Node* node) {
	int printCount = 0;
	for (it = node->data.begin(); it != node->data.end(); it++) {
		if (printCount == 3) {
			std::cout << "\n";
			printCount = 0;
		}
		std::cout << " " << *it << " ";
		printCount++;
	}
	std::cout << "\n";
		
}

//Finds the "blank" position so it can be swapped

int Puzzle::findBlank(Node* node) {
	int distance;
	it = std::find(node->data.begin(), node->data.end(), 0);
	distance = std::distance(node->data.begin(), it);
	std::cout << distance;
	return distance;
	

}