#include "SymbolGraph.h" 
#include "inc_io.h"
#include "Graph.h"

int SymbolGraph::run()
{
    int ret = 0;
    std::unordered_map<std::string, int> mStats;
    std::vector<std::vector<std::string>> edgeSymbols = InputStringStream("./input/routes.txt", mStats);
    
    std::map<std::string, int> mTrans = InputMapStream("./input/routes.st");
    std::vector<std::vector<int>> edges;
    edges.push_back({mStats.size()});
    edges.push_back({edgeSymbols.size()});
	    for(auto const& iEdges : edgeSymbols) {
	    	edges.push_back({mTrans[iEdges[0]], mTrans[iEdges[1]]});
	    }
	   
    int V = edges[0][0], E = edges[1][0];
    Graph G(V);
    int iLine = 2;
    while(E > 0) {
        int v = edges[iLine][0], w = edges[iLine][1];
	G.addEdge(v, w);
	E--;
	iLine++;
    }
    std::cout<<"start print to IO"<<std::endl;
    std::cout<<G.toString()<<std::endl;

    return ret;
}
