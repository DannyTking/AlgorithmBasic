#include "io_file_inc.h"
//#include "Paths.h"
#include "Search.h"
int main(int argn, char* args[])
{
    int ret = 0;
    std::vector<std::vector<int>> edges = InputIntStream("./input/tinyG.txt");
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

    int s = 0;
    std::cin >> s;
    std::cout<<"search dfs path v: "<<s<<":"<<std::endl;
    Search search(G,s);
    for(int v = 0; v < G.V(); v++) {
        if (search.marked(v)) {
	    std::cout<<v<<" ";
	}
    }
    std::cout<<std::endl;
    if (search.count() != G.V()){
        std::cout<<"Not ";
    }
    std::cout<<"connected"<<std::endl;
    return ret;
}
