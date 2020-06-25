# A\* search algorithm

## Concept

A*(pronounced "A-star") is a graph traversal and path search algorithm, which is often used in many fields of computer science due to its completeness, optimality, and optimal efficiency. One major practical drawback is its [O(b <sup>n</sup>)](https://www.bigocheatsheet.com/) space complexity, as it stores all generated nodes in memory. Thus, in practical travel-routing systems, it is generally outperformed by algorithms which can pre-process the graph to attain better performance, as well as memory-bounded approaches; however, A* is still the best solution in many cases.

Peter Hart, Nils Nilsson and Bertram Raphael of Stanford Research Institute (now SRI International) first published the algorithm in 1968. It can be seen as an extension of Edsger Dijkstra's 1959 algorithm. A* achieves better performance by using heuristics to guide its search.
[Ref. Wikipedia](https://en.wikipedia.org/wiki/A*\_search_algorithm)

## Goal

![Map example](Goal.png)

In the Motion/Path Planning use A\* algorithm finds a path from the initial point (start node) to the destination (end node) by checking for open neighbors of the current node, computing a heuristic for each of the neighbors, and adding those neighbors to the list of open nodes to explore next. The next node to explore is the one with the lowest total cost + heuristic (g + h). This process is repeated until the end is found, as long as there are still open nodes to explore.

## Tools

- VSCODE
- Compiler mingw-w64 (GCC)
- C/C++ Extension Microsoft
- Clang-Format Extension
- vcpkg C++ Package Manager
- My VSCODE Gist -> [Gist](https://gist.github.com/rsaz/34382ec3cf94d8e436976fe5268d7a49)

## Next Steps

- To adjust the A\* Algorithm plotting the information on a real map. I will be using the OpenStreetMap IO2D package and CMAKE.

- Implement the A\* in a real Unity 3D Engine game map

## Follow me on [Twitch](https://www.twitch.tv/id_akira)

## A Big thank you for the special viewer participation

- 08pixels
- FenickBRXD
- Lonely_Pl4yer1
- Josue1342YT
- franciscoalvesoliveira
- wolf_0x20
