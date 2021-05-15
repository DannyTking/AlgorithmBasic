#pragma once
#include "graph_inc.h"

class Search {
public:
    Search(Graph &G, int s){
        mFlags = std::vector<bool>(G.V(), false);
        dfs(G, s);	
    }
    bool marked(int v) { return mFlags[v]; }
    int count() { return mCount; }
private:
    void dfs(Graph & G, int v) 
    {
	mFlags[v] = true;
	mCount++;
	for(auto w : G.adj(v)) {
	    if (!this->marked(w)) {
	        dfs(G,w);
	    }
	}
    }
private:
    int mCount{0};
    std::vector<bool> mFlags;
};
