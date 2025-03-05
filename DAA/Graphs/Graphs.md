## Graphs:
G = {V,E}

## Spanning tree:
Part of a graph where the number of nodes will be the same as the orgiginal graph but the edges will be n-1 where n is the numebr of nodes

**For a complete graph the no of spanning tree = n ^ (n-2)**

# Spanning tree algorithms:

- Prim's Algorithm: (minimum cost spanning tree problem) ->
    - Find minimum path length from the curr node to the next in every iteration
    - Check for cycle after every iteration
    - Finally the e will equal n - 1 thats when we have the minimum spanning tree
    
- Kruskal's Algorithm: