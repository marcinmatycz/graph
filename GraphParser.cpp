#include "GraphParser.h"
#include <algorithm>
#include <iostream>

/**
 * 
 * 
 * 
 *                  CONSTRUCTORS
 * 
 * 
 * 
 */

GraphParser::GraphParser(void){}
GraphParser::~GraphParser(void){}

/**
 * 
 * 
 * 
 *                  PUBLIC
 * 
 * 
 * 
 */

int GraphParser::lineParse(string line)
{
    if(redListParse(line)) 
    {
        return 1;
    }

    if(arrowParse(line)) 
    {
        return 2;
    }

    return 0;
}

Vertex* GraphParser::getRoot()
{
    return &houses["root"];
}

/**
 * 
 * 
 * 
 *                  PRIVATE
 * 
 * 
 * 
 */

bool GraphParser::onRedList(string house)
{
    return find(red_list.begin(), red_list.end(), house) != red_list.end();
}

bool GraphParser::hasHouse(string house)
{
    return houses.find(house) != houses.end();
}

bool GraphParser::redListParse(string line)
{
    // Remove whitespaces.
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    
    int red_label_start = line.find("[");
    if(red_label_start != string::npos) 
    {
        red_list.push_back(line.substr(0, red_label_start));
        return true;
    }
    else
    {
        return false;
    }
}

bool GraphParser::arrowParse(string line)
{    
    // Remove whitespaces.
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

    int arrow_index = line.find("->");
    string previous = "";

    while(arrow_index != string::npos)
    {
        string current = line.substr(0, arrow_index);

        // Make new house if it is its first appearance.
        if(!(this->hasHouse(current)))
        {
            if(this->onRedList(current))
            {
                houses[current] = Vertex(current, true);
            }
            else
            {
                houses[current] = Vertex(current, false);
            }
        }

        // Connect house to previous house if it is not already.
        if(previous != "" && !houses[previous].hasBranch(current))
        {
            houses[previous].addBranch(&houses[current]);
        };

        // Check if the last house in line was parsed.
        if(line.length() == arrow_index + 1)
        {
            break;
        }

        // Discard parsed house and find new arrow.
        line = line.substr(arrow_index + 2);
        arrow_index = line.find("->");

        // If not succeeded, find semicolon for last house of line.
        if (arrow_index == string::npos)
        {
            arrow_index = line.find(";");
        }

        previous = current;
    }
    return true;
}
