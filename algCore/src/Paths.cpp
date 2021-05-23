#include "Paths.h" 
#include "inc_io.h"
int Paths::run()
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

    int s = 0;
    std::cin >> s;
    std::cout<<"search dfs path v: "<<s<<":"<<std::endl;
    Paths search(G,s);
    for(int v = 0; v < G.V(); v++) {
	    std::cout<<s<<" to "<<v<<": ";
        if (search.hasPathTo(v)) {
		for(auto const& x : search.pathTo(v)) {
			if (x == s) std::cout<<x;
			else std::cout<<"-"<<x;
		}
		std::cout<<std::endl;
	}
	else std::cout<<"Not reach"<<std::endl;
    }
    return ret;
}
Paths::Paths(Graph &G, int s)
{

	mFlags = std::vector<bool>(G.V(), false);
	for(int v=0; v<G.V(); v++){
		mEdgeTo.push_back(v);
	}
	mS = s;
	this->dfs(G, s);
}

void Paths::dfs(Graph &G, int v)
{
	mFlags[v] = true;
	auto edgs = G.adj(v);
//	std::sort(edgs.begin(), edgs.end());
	for(auto const& w : edgs){
		if (!mFlags[w]) {
			mEdgeTo[w] = v;
			dfs(G, w);
		}
	}
}

bool Paths::hasPathTo(int v)
{
	return mFlags[v];
}

std::vector<int> Paths::pathTo(int v)
{
	std::vector<int> ret;
	if (!this->hasPathTo(v)) return ret;
	for(int x=v; x!=mS; x=mEdgeTo[x]) ret.push_back(x);
	ret.push_back(mS);
	std::reverse(ret.begin(), ret.end());
	return ret;
}
