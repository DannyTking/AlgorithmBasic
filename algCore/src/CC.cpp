#include "CC.h" 
int CC:run()
{
		
    int ret = 0;
    std::vector<std::vector<int>> edges = InputIntStream("./input/tinyCG.txt");
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

	CC cc(G);
	auto M = cc.count();
	std::cout<<M<<" components"<<std::endl;

	std::vector<std::vector<int>> components(M, {});
	for(int v=0; v<G.V(); v++) components[cc.id(v)].push_back(v);
	for(int i=0; i<M; i++) {
			for(auto const& v : components[i]) std::cout<<v<<" ";
			std::cout<<std::endl;
	}

    return ret;
}
