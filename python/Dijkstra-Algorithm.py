from heapq import *
from collections import defaultdict

def dijkstra(edges, strat_node, end_node):
    g = defaultdict(list) 
    for start, end, weight in edges: 
        g[start].append((weight, end)) 
    q, visited = [(0, strat_node,())], set()
    while q:        
        (cost,v1,path) = heappop(q)
        if v1 not in visited:
            visited.add(v1)
            path = (v1, path)            
            if v1 == end_node:
                return (cost, path)
            for c, v2 in g.get(v1, ()):
                if v2 not in visited:
                    heappush(q, (cost+c, v2, path))
        print (q)   
    return float("inf")

if __name__ == "__main__":
    
    edges = [
        ("A", "B", 7),
        ("A", "D", 5),
        ("B", "C", 8),
        ("B", "D", 9),
        ("B", "E", 7),
        ("C", "E", 5),
        ("D", "E", 7),
        ("D", "F", 6),
        ("E", "F", 8),
        ("E", "G", 9),
        ("F", "G", 11)
    ]
    
    print ("=== Dijkstra ===")
    print ("A >> G:")
    print (dijkstra(edges, "A", "G"))
