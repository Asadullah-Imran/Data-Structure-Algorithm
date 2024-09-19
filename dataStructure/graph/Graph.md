
# graph

## Graph representation 
- adjacency matrix
- adjacency list


## adjacency matrix
- matrix of size V x V where entry M[i][j] represents the edge between vertex i
 0 1 2 3
0[0 1 1 1]
1[1 0 0 1]
2[1 0 0 0]
3[1 1 0 0]

row describe the connection of  specific node . like for first row [0 1 1 1] has connection of 0.

## adjacency List

0 -> 1 -> 2 -> 3
1 -> 0 -> 3
2 -> 0
3 -> 1 -> 0

adjacency matrix take extra space for redundency nodes. 


