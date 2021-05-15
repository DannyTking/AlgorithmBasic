#include "Graph.h"
#include <sstream>

void Graph::addEdge(int v, int w)
{
    adjMap[v].push_back(w);
    adjMap[w].push_back(v);
    mE++;
}

std::vector<int> const& Graph::adj(int v)
{
    return adjMap[v];
}

std::string Graph::toString()
{
    std::stringstream ss;
    ss <<"This Graph has "<<mV << " vertices, " << mE << " edges\n";
    for (int v = 0; v < mV; v++)
    {
        ss << v << ": ";
	auto vw = this->adj(v);
	std::sort(vw.begin(), vw.end());
	for(auto w : vw) 
	{
	    ss << w << " ";
	}
	ss << "\n";
    }
    return ss.str();
}
