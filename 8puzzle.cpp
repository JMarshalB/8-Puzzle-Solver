#include "8puzzle.h"

Node::Node(){
    
}

Node::Node(std::vector<int> data, Node* parent, int cost){
    this->data = data;
    this->parent = parent;
    this->cost = cost;
}

void Node::printData() {
    int printCount = 0;
    for (int i = 0; i < 9; i++) {
        if (printCount == 3) {
            std::cout << "\n";
            printCount = 0;
        }
        std::cout << " " << this->data.at(i) << " ";
        printCount++;
    }
    std::cout << "\n\n";
}

void Node::move_up(int blank){
    if(blank !=0 && blank != 1 && blank != 2){
        std::vector<int> childData;
        childData = this->data;
        std::swap(childData[blank], childData[blank - 3]); 
        Node* child = new Node{childData, this, this->cost + 1};
    }
}

void Node::move_down(int blank){
    if(blank !=6 &&  blank != 7 && blank != 8){
        std::vector<int> childData;
        childData = this->data;
        std::swap(childData[blank], childData[blank + 3]); 
        Node* child = new Node{childData, this, this->cost + 1};
    }
}

void Node::move_left(int blank){
    if(blank !=0 &&  blank != 3 && blank != 6){
        std::vector<int> childData;
        childData = this->data;
        std::swap(childData[blank], childData[blank - 1]); 
        Node* child = new Node{childData, this, this->cost + 1};
    }
}

void Node::move_right(int blank){
    if(blank !=2 &&  blank != 5 && blank != 8){ //as long as the blank is not on the right side 
        std::vector<int> childData;
        childData = this->data;
        std::swap(childData[blank], childData[blank + 1]); //swapping blank with number to its right
        Node* child = new Node{childData, this, this->cost + 1};
    }
}



    