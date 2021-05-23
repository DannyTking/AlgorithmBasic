#include "CC.h" 
#include "inc_io.h"
int CC::run()
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

	CC cc(G);
	auto M = cc.count();
	std::cout<<M<<" components"<<std::endl;

	std::vector<std::vector<int>> components(M);
	for(int v=0; v<G.V(); v++) components[cc.id(v)].push_back(v);
	for(int i=0; i<M; i++) {
			for(auto const& v : components[i]) std::cout<<v<<" ";
			std::cout<<std::endl;
	}

    return ret;
}

CC::CC(Graph &G)
{
		mFlags = std::vector<bool>(G.V(), false);
		mIds = std::vector<int>(G.V(), 0);
		mCount = 0;
		for(int s=0; s < G.V(); s++) {
				if(!mFlags[s]) {
						dfs(G, s, mCount);
						mCount++;
				}
		}
}

void CC::dfs(Graph &G, int s, int id)
{
		mFlags[s] = true;
		mIds[s] = id;
		for(auto const& w : G.adj(s)) {
				if(!mFlags[w]) dfs(G, w, id);
		}
}

bool CC::connected(int v, int w)
{
		return mIds[v] == mIds[w];
}

int CC::id(int v)
{
		return mIds[v];
}

int CC::count()
{
		return mCount;
}
