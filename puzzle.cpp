#include "puzzle.hpp"

Puzzle::Puzzle() {

}

Puzzle::~Puzzle(){

}

void Puzzle::BFS(Node* node) {
	std::list<Node*> openList;
	std::list<Node*> closedList;
	openList.push_back(node);
	Node* currentNode;
		
	bool goal = false;

	while (!openList.empty() && !goal) {
		//Get current node in queue
		currentNode = openList.front();
		openList.pop_front(); //Then pop it
		closedList.push_back(currentNode); //Finally add to closed list

		//Create all moves possible with that node
		//printState(node);
		expandNode(currentNode);

		//Iterate through childern to check if it equals the goal state
		//and then add them to openList as you iterate.
		for (auto child : currentNode->childern) {
			child->cost = child->parent->cost + 1;
			if (child->data == goalState) { 
				goal = true;
				path(child);
				std::cout << "Cost Using BFS: " << child->cost << std::endl;
				break;
			}
			else {
				if (!(stateInList(child, openList)) && !(stateInList(child, closedList))) {
					openList.push_back(child);
				}
			}
								
		}

	}
	
}

bool Puzzle::DFS(Node* node) {

	//If goal state is found
	if (node->data == goalState) {
		path(node);
		std::cout << "Cost Using DFS: " << node->cost << std::endl;
		return true;
	}

	//If node is already in list
	if (stateInList(node, visitedDFSList)) { return false; }

	visitedDFSList.push_front(node);
	expandNode(node);

	for (auto child : node->childern) {
		if (node->parent != nullptr)
			if (child->data == node->parent->data) { continue; }

		child->cost = child->parent->cost + 1;

		if (DFS(child)) { visitedDFSList.clear(); return true; }
	}

	return false;
	
}

void Puzzle::Dijkstra(Node* node) {
	std::list<Node*> openList;
	std::list<Node*> closedList;
	openList.push_back(node);
	Node* currentNode;
	int blankSpace;

	bool goal = false;
	while (!goal && !openList.empty()) {
		currentNode = openList.front();
	
		openList.pop_front();
		closedList.push_back(currentNode);

		blankSpace = findBlank(currentNode);
		move_up(currentNode, blankSpace);
		if (blankSpace != 0 && blankSpace != 1 && blankSpace != 2)
			currentNode->childern.back()->cost = currentNode->cost + currentNode->data.at(blankSpace - 3);

		move_down(currentNode, blankSpace);
		if (blankSpace != 6 && blankSpace != 7 && blankSpace != 8)
			currentNode->childern.back()->cost = currentNode->cost + currentNode->data.at(blankSpace + 3);

		move_left(currentNode, blankSpace);
		if (blankSpace != 0 && blankSpace != 3 && blankSpace != 6)
			currentNode->childern.back()->cost = currentNode->cost + currentNode->data.at(blankSpace - 1);

		move_right(currentNode, blankSpace);
		if (blankSpace != 2 && blankSpace != 5 && blankSpace != 8)
			currentNode->childern.back()->cost = currentNode->cost + currentNode->data.at(blankSpace + 1);

		for (auto child : currentNode->childern) {
			if (child->data == goalState) {
				goal = true;
				path(child);
				std::cout << child->cost << std::endl;
				break;
			}
			if (child->data == currentNode->data) { continue; }

			if (!stateInList(child, openList) && !stateInList(child, openList)) {
					openList.push_back(child);
			}

		}

	}
}

//Creates all possible children given parent node
void Puzzle::expandNode(Node* node) {
	int blankSpacePos;
	blankSpacePos = findBlank(node);

	move_left(node, blankSpacePos);
	move_up(node, blankSpacePos);
	move_down(node, blankSpacePos);
	move_right(node, blankSpacePos);
}

//Creates child from moving zero up
void Puzzle::move_up(Node* node, int bSpace) {
	if (bSpace != 0 && bSpace != 1 && bSpace != 2) {
		Node* child = new Node{ node->data, node, 0 };
		std::swap(child->data.at(bSpace), child->data.at(bSpace - 3));
		node->childern.push_back(child);
	}
}

//Creates child from moving zero down
void Puzzle::move_down(Node* node, int bSpace) {
	if (bSpace != 6 && bSpace != 7 && bSpace != 8) {
		Node* child = new Node{ node->data, node, 0 };
		std::swap(child->data.at(bSpace), child->data.at(bSpace + 3));
		node->childern.push_back(child);
	}
}

//Creates child from moving zero right
void Puzzle::move_right(Node* node, int bSpace) {
	if (bSpace != 2 && bSpace != 5 && bSpace != 8) {
		Node* child = new Node{ node->data, node, 0 };
		std::swap(child->data.at(bSpace), child->data.at(bSpace + 1));
		node->childern.push_back(child);
	}
}

//Creates child from moving zero left
void Puzzle::move_left(Node* node, int bSpace) {
	if (bSpace != 0 && bSpace != 3 && bSpace != 6) {
		Node* child = new Node{ node->data, node, 0 };
		std::swap(child->data.at(bSpace), child->data.at(bSpace - 1));
		node->childern.push_back(child);
	}
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

bool Puzzle::stateInList(Node* node, std::list<Node*> list) {
	bool inList = false;
	for (auto i : list)
		if (node->data == i->data) { inList = true; }
	
	return inList;

}

void Puzzle::path(Node* node) {
	std::cout << "--------------\nPrinting Steps\n--------------\n";
	std::stack<Node*> stack;
	Node* currentNode = node;
	if (node != NULL) {
		stack.push(currentNode);
		while (currentNode->parent != NULL) {
			stack.push(currentNode->parent);
			currentNode = currentNode->parent;
		}
	}

	while (!stack.empty()) {
		printState(stack.top());
		stack.pop();
	}
}
