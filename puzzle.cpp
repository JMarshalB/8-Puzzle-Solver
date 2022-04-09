#include "puzzle.hpp"

Puzzle::Puzzle() {

}

Puzzle::~Puzzle(){

}

//NOT FINISHED YET
void Puzzle::BFS(Node* node) {
	std::list<Node*> openList;
	std::list<Node*> closedist;
	openList.push_back(node);
		
	bool goalState = false;

	
}

//Creates all possible children given parent node
void Puzzle::expandNode(Node* node) {
	int blankSpacePos;
	blankSpacePos = findBlank(node);

	move_up(node, blankSpacePos);
	move_down(node, blankSpacePos);
	move_left(node, blankSpacePos);
	move_right(node, blankSpacePos);

}

//Creates child from moving zero up
void Puzzle::move_up(Node* node, int bSpace) {
	if (bSpace != 0 && bSpace != 1 && bSpace != 2) {
		Node* child = node;
		std::swap(child->data.at(bSpace), node->data.at(bSpace - 3));
		child->parent = node;
	}



}

//Creates child from moving zero down
void Puzzle::move_down(Node* node, int bSpace) {
	if (bSpace != 6 && bSpace != 7 && bSpace != 8) {
		Node* child = node;
		std::swap(child->data.at(bSpace), node->data.at(bSpace + 3));
		child->parent = node;
	}


}

//Creates child from moving zero right
void Puzzle::move_right(Node* node, int bSpace) {
	if (bSpace != 2 && bSpace != 5 && bSpace != 8) {
		Node* child = node;
		std::swap(child->data.at(bSpace), node->data.at(bSpace + 1));
		child->parent = node;
	}


}

//Creates child from moving zero left
void Puzzle::move_left(Node* node, int bSpace) {
	if (bSpace != 0 && bSpace != 3 && bSpace != 6) {
		Node* child = node;
		std::swap(child->data.at(bSpace), node->data.at(bSpace - 1));
		child->parent = node;
	}


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
	std::cout << "\n\n";
		
}

//Finds the "blank" position so it can be swapped
int Puzzle::findBlank(Node* node) {
	int distance;
	it = std::find(node->data.begin(), node->data.end(), 0);
	distance = std::distance(node->data.begin(), it);
	return distance;
	

}