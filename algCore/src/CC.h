#pragma once
#include "inc_std.h"
#include "Graph.h"
// date:2021-05-23 10:45:36 
class CC {
		public:
				static int run();
		public:
				CC(Graph &G);
				bool connected(int v, int w);
				int count();
				int id(int v);
};
