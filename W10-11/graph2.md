# Activity 11 Graphs

## Question
### Question 1
Dijkstra’s algorithm works by selecting the node with the smallest current distance and assuming that this distance is final.
The problem with negative weights is that a shorter path to a node can be found after the node has already been finalized.

Example:
Find the shortest path from $A$ to $B$.

$A$ to $B = 2$

$A$ to $C = 5$

$C$ to $B = -4$

We start at $A$ with the distance to $B=2$ and the distance to $C=5$.
The Dijkstra's algorithm would select $B$ first and finalizes it.
It would then process $C$ and finds a new path to $B$:

$A$ to $C$ to $B = 5 + (-4) = 1$

This path of $1$ is would be shorter than the previously found path of $2$, but Dijkstra’s algorithm does not update $B$ because it has already been finalized.
In conclusion, Dijkstra’s algorithm fails with negative weights because it assumes that once a node’s shortest distance is determined, it will not change.
