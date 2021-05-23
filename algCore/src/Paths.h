#pragma once
#include "inc_std.h"
#include "Graph.h"
// date:2021-05-23 09:12:18 
class Paths {
	public:
		static int run();
	public:
		Paths(Graph &G, int s);
		bool hasPathTo(int v);
		std::vector<int> pathTo(int v);
	private:
		void dfs(Graph &G, int v);
		std::vector<bool> mFlags;
		std::vector<int> mEdgeTo;
		int mS;
};
