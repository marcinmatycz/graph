#pragma once

#include <vector>
#include <string>
#include <map>
#include "Vertex.h"

using namespace std;

/**
 * Implementation of simple graph parser. 
 * It constructs a tree using Vertex class.
 *  
 */
class GraphParser
{
private:
    vector <string> red_list;
    map <string, Vertex> houses;

public:
    GraphParser(void);              // Constructor
    ~GraphParser(void);             // Destructor

    int lineParse(string line);     // Parses a line.
    Vertex* getRoot();              // Returns root vertex (your house).

private:
    bool onRedList(string house);   // Checks if house is on a red list.
    bool hasHouse(string house);    // Checks if house is on parser's list of houses.
    bool redListParse(string line); // Checks if line has a red list label, adds house to red_list if true.
    bool arrowParse(string line);   // Parses a line if it has an arrow, creates Vertex objects and adds them to houses map.

};