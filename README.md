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

**Sample Input**

Sample file 1:

1   3   4                      
8   0   2                           
7   6   5

Solutions: The shortest path cost = 11 

Sample file 2:

1   3   4                      
8   0   6                           
7   5   2

Solution: The shortest path cost = 30

