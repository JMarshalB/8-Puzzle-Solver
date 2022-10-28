# 8-Puzzle-Solver

This program finds the cheapest solution to the 8-puzzle. 

Given the initial state Ex:

1   2   3                               
0   8   4                               
7   6   5            

It will find solve for the goal state Ex:

1   2   3                      
8   0   4                     
7   6   5  


Testing three different algorithms: BFS, DFS, and Dijkstr

For the BFS and DFS algorithms, the cost of moving a tile is 1 and ordering of a move is: left, up, 
right, and down. For example: Moving the 8 tile from the middle to the left incurs a cost of 1.

1   2   3                         
0   8   4                        
7   6   5    

1   2   3                      
8   0   4                     
7   6   5  

For the Dijkstra algorithm, suppose that the cost of a move in the 8-puzzle is equal to the number 
of the moved tile plus the number of displaced tiles. That is, the cost of moving tile 1 is $1 + the 
number of displaced tiles of 1, the cost of moving tile 2 is $2 + the number of displaced tiles of 2, 
and so on. 

The goal state given in Figure 
below: 

1   2   3                      
8   0   4                           
7   6   5     

---------------------------------------------------------------------------------------------------------------
**To run this program**

In your command line enter the following: g++ Main.cpp puzzle.cpp puzzle.hpp

If you wish to edit the goal state or initial state edit their respective vectors in Main.cpp

---------------------------------------------------------------------------------------------------------------

**Sample Output**

--------------
Initial Puzzle
--------------
 1  0  3 
 8  2  4 
 7  6  5 

--------------
Goal Puzzle
--------------
 1  2  3 
 8  0  4 
 7  6  5 

--------------
Printing Steps
--------------
 1  0  3 
 8  2  4 
 7  6  5 

 1  2  3 
 8  0  4 
 7  6  5 

Cost using Dijkstra: 2
--------------
Printing Steps
--------------
 1  0  3 
 8  2  4 
 7  6  5

 1  2  3
 8  0  4
 7  6  5

Cost Using BFS: 1
--------------
Printing Steps
--------------
 1  0  3
 8  2  4
 7  6  5

 0  1  3
 8  2  4
 7  6  5

 8  1  3
 0  2  4
 7  6  5

 8  1  3
 7  2  4
 0  6  5

 8  1  3
 7  2  4
 6  0  5

 8  1  3
 7  0  4
 6  2  5

 8  0  3
 7  1  4
 6  2  5

 0  8  3
 7  1  4
 6  2  5

 7  8  3
 0  1  4
 6  2  5

 7  8  3
 6  1  4
 0  2  5

 7  8  3
 6  1  4
 2  0  5

 7  8  3
 6  0  4
 2  1  5

 7  0  3
 6  8  4
 2  1  5

 0  7  3
 6  8  4
 2  1  5

 6  7  3
 0  8  4
 2  1  5

 6  7  3
 2  8  4
 0  1  5

 6  7  3
 2  8  4
 1  0  5

 6  7  3
 2  0  4
 8  0  5

 2  6  3
 1  0  4
 8  7  5

 2  0  3
 1  6  4
 8  7  5

 0  2  3
 1  6  4
 8  7  5

 1  2  3
 0  6  4
 8  7  5

 1  2  3
 8  6  4
 0  7  5

 1  2  3
 8  6  4
 7  0  5

 1  2  3
 8  0  4
 7  6  5

Cost Using DFS: 29


