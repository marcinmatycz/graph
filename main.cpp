#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "GraphParser.h"
#include "Vertex.h"

using namespace std;

// Searching algorithm function.
void checkRoutes(Vertex *house, int route_marked_red);

int main()
{
    // Read and parse file.
    ifstream graph_file;
    graph_file.open("graph.txt");

    GraphParser graph_parser;

    if (graph_file.is_open())
    {
        while (!graph_file.eof())
        {
            string line;
            getline(graph_file, line);
            
            if (line.empty())
            {
                continue;
            }

            graph_parser.lineParse(line);
        }
    }
    graph_file.close();

    // First call of recursive DFS algorithm on a root (your house) with no previous houses being red.
    checkRoutes(graph_parser.getRoot(), 0);

    system("pause");
    return 0;
}

// Searching algorithm function.
void checkRoutes(Vertex *house, int route_marked_red)
{   
    // Information about red house is passed to next iterations on next branches.
    // This information stacks so you could now how many red houses was on a route to specific red house.
    if(house->isRed())
    {
        route_marked_red++;
    }

    vector<Vertex*> *branches = house->getBranches();
    
    // Recursive DFS
    for(int i=0; i<branches->size(); i++)
    {
        checkRoutes((*branches)[i], route_marked_red);
    }

    // Decrease the variable when backtracking (taking other routes).
    if(house->isRed())
    {
        route_marked_red--;
        cout << house->getId() << " - "  << route_marked_red << " ulubionych kolegow po drodze" << endl;
    }
    
}