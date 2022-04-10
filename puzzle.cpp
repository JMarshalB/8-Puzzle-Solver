#include "puzzle.hpp"

Puzzle::Puzzle() {

}

Puzzle::~Puzzle(){

}

void Puzzle::BFS(Node* node) {
	std::vector<Node> vector;
	vector.push_back(*node);
		
	bool goal = false;
	int i = 0;
	while(i != vector.size()) { //Iterate vector
		printState(&(vector.at(i))); 
		if (vector.at(i).data == goalState) {
			printState(&vector.at(i));
			printState(vector.at(i).parent); ///ERRORRRRRRRR does not print parent
			std::cout << "Cost Using BFS: " << vector.at(i).cost << std::endl;
			goal = true;
			path(&vector.at(i));

			break;
		}
		else {
			expandNode(&(vector.at(i)), &vector); //Adds childern of current node to the end of vector
			i++;
		}
	}
}


//Creates all possible children given parent node
void Puzzle::expandNode(Node* node, std::vector<Node> *vector) {
	int blankSpacePos;
	blankSpacePos = findBlank(node);
	Node temp = *node;
	Node child;

	if (blankSpacePos != 0 && blankSpacePos != 1 && blankSpacePos != 2) {
		child = move_up(temp, blankSpacePos);
		if (!(stateInList(&child, *vector))) {
			vector->push_back(child);
		}
	}

	printState(&temp);
	if (blankSpacePos != 6 && blankSpacePos != 7 && blankSpacePos != 8) {
		child = move_down(temp, blankSpacePos);
		if (!(stateInList(&child, *vector))) {
			vector->push_back(child);
		}
	}

	if (blankSpacePos != 0 && blankSpacePos != 3 && blankSpacePos != 6) {
		child = move_left(temp, blankSpacePos);
		if (!(stateInList(&child, *vector))) {
			vector->push_back(child);
		}
	}

	if (blankSpacePos != 2 && blankSpacePos != 5 && blankSpacePos != 8) {
		child = move_right(temp, blankSpacePos);
		if (!(stateInList(&child, *vector))) {
			vector->push_back(child);
		}
	}
}

//Creates child from moving zero up
Node Puzzle::move_up(Node node, int bSpace) {
	Node child;
	child.data = node.data;
	child.parent = &node;

	//TEST
	printState(&node);
	printState(&child);
	printState(child.parent); //child is setting parent to self??
	//END OF TEST

	child.cost = node.cost + child.data.at(bSpace - 3);
	std::swap(child.data.at(bSpace), child.data.at(bSpace - 3));
	node.childern.push_back(child);
	return child;
}

//Creates child from moving zero down
Node Puzzle::move_down(Node node, int bSpace) {
	Node child;
	child.data = node.data;
	child.parent = &node;
	child.cost = node.cost + child.data.at(bSpace + 3);
	std::swap(child.data.at(bSpace), child.data.at(bSpace + 3));
	node.childern.push_back(child);
	return child;
}

//Creates child from moving zero right
Node Puzzle::move_right(Node node, int bSpace) {
	Node child;
	child.data = node.data;
	child.parent = &node;
	child.cost = node.cost + child.data.at(bSpace + 1);
	std::swap(child.data.at(bSpace), child.data.at(bSpace + 1));
	node.childern.push_back(child);
	return child;
}

//Creates child from moving zero left
Node Puzzle::move_left(Node node, int bSpace) {
	Node child;
	child.data = node.data;
	child.parent = &node;
	child.cost = node.cost + child.data.at(bSpace - 1);
	std::swap(child.data.at(bSpace), child.data.at(bSpace - 1));
	node.childern.push_back(child);
	return child;
}

//Prints the current puzzle within a node
void Puzzle::printState (Node* node) {
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
	return (int) distance;
}

bool Puzzle::stateInList(Node* node, std::vector<Node> vector) {
	bool inList = false;
	for (auto i : vector)
		if (node->data == i.data) { inList = true; }
	
	return inList;

}

void Puzzle::path(Node* node) {
	std::cout << "--------------\nPrinting Steps\n--------------\n";
	std::stack<Node*> stack;
	Node* currentNode = node;
	if (node != NULL) {
		stack.push(currentNode);
		printState(currentNode);
		while (currentNode->parent != NULL) {
			printState(currentNode->parent);
			stack.push(currentNode->parent);
			currentNode = currentNode->parent;
		}
	}

	while (!stack.empty()) {
		printState(stack.top());
		stack.pop();
	}
}
