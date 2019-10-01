#pragma once

#include <vector>
#include <string>

using namespace std;

/**
 *  Implementation of a vertex holding pointers to children.
 *  These pointers are used in recursive DFS algorithm.
 *  Class also holds id (friend name) and red attribute. 
 * 
 */
class Vertex
{
private:
    string m_id;
    bool m_red;
    vector <Vertex *> m_branches;

public:
    // Constructors and destructor
    Vertex(void);
    Vertex(string id, bool red);
    ~Vertex(void);

    // Getters
    string getId();
    vector <Vertex *>* getBranches();

    // Methods
    void addBranch(Vertex *branch);
    bool isRed();
    bool hasBranch(string id);
};