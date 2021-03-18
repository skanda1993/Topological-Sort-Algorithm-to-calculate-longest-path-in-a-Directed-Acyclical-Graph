A brief overview->

Algorithm used for solving the problem is by Topological sorting the adjacency list. A directed acyclical graph is considered for topsort.
Existing solution takes input only acyclical graphs and finds the longest possible path from a given start node to every other nodes. Unfortunately, this cannot be used to find cyclical graph problem. 

How it works:

File handlers: They read data kept in my_data.txt (hardcoded) and parse them to a vector of segments. Utility functions can be used to export the segments vector to create directed, weighted graphs. The data in the file must obey the strict data guidelines. File handlers (as the name suggests) does not handle any error in the text file.

Format for data in "my_data.txt":
<Segment ID> <X coordinate> <Y coordinate> <list of connections>
Segment ID starts from 0 and sshould iterate without discontinuity
X and Y coordinates could be in double/float representation
list of connections should be integers and no limit on connections
No cyclical connections allowed

Graph: An un-ordered map of vertices is built. Each segment ID is linked to all the edges it is in contact with associated weights.
 
Topological sort and search: Topological sort is made to obtain topsort ordering of the nodes in the graph. Ordered vector is used to find the shortest path from given segment to all the segments in the graph. Weights of the graphs are negated to obtaing longest path rather than changing given graph G to G` with negative weights. 
