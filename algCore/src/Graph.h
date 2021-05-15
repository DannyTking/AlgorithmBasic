#pragma once

#include "std_inc.h"

class Graph {
public:
   Graph(int V):mV(V) { 
     for(int v=0; v<V; v++) {
	  adjMap.insert({v, {}});
     }
   }

   int V() const { return mV; }
   int E() const { return mE; }
   void addEdge(int v, int w);
   std::vector<int> const& adj(int v);
   std::string toString();
private:
   int mV {0};
   int mE {0};
   std::map<int, std::vector<int>> adjMap;
};
