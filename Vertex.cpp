#include "Vertex.h"

/**
 * 
 * 
 * 
 *                  CONSTRUCTORS
 * 
 * 
 * 
 */

Vertex::Vertex(void){}
Vertex::Vertex(string id, bool red): m_id(id), m_red(red) {}
Vertex::~Vertex(void){}

/**
 * 
 * 
 * 
 *                  PUBLIC
 * 
 * 
 * 
 */


// Getters
string Vertex::getId() { return m_id; }
vector <Vertex*>* Vertex::getBranches() { return &m_branches; }

// Methods
void Vertex::addBranch(Vertex *branch) { m_branches.push_back(branch); }
bool Vertex::isRed() { return m_red; }

bool Vertex::hasBranch(string id)
{
    for(int i=0; i<m_branches.size(); i++)
    {
        if(m_branches[i]->m_id == id)
        {
            return true;
        }
    }

    return false;
}
