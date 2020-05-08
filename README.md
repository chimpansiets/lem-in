# lem-in

This project is a game about an ant farm. Its goal is to find the shortest path from the start room to the end room.

## About lem-in

At the beginning from standard output the program recieves information about number of ants had to be leaded through path, room names (can be numbers, words, characters etc.) with coordinates and links. Here is an example:

```
10          // ants number
1 250 150   // Room name (1) ants it's X-Y coordonates
2 550 150
3 550 450
##start     // Next room will be start room
4 250 450
##end       // Next room will be end room
5 850 450
6 850 150
1-2         // Relations between rooms. Room 1 and 2 are linked
1-3
1-4
2-4
2-6
2-5
3-4
3-5
3-6
5-6
```

The program cannot leak. All errors must be handled carefully. In no way can the program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).
Allowed functions for the mandatory part are malloc, free, read, write, strerror, perror and exit. Everything else is forbidden. Other functions can be used for bonus, but their use must be justified.

## Installation and usage

Simply clone repository and run following commands:

```
make

./lem-in < maps/subject-1.map
```
Here 'maps/subject-1.map' is an example of game map.

## Moving the agents from start to end

There are a lot of possible ways and algorithms to solve the task.
For saving the data of the graph I used an edge list connected to every node in the graph.
This edge list was in essence just a list of pointers that are pointing to another node in the graph.

After that I used a BFS approach to giving the nodes distance-levels from the start node, and also from the end node.

Lastly, to decide which paths to use, I used a modified version of Dinic's algorithm. Here I calculate the blocking flow in the nodes itself instead of in the vectors to decide which paths to use and where the blocking flow occurs.

## Author

Sietse Voort



