#pragma once

#include "Graph.h"

int degree(Graph &G, int v)
{
    auto const& vw = G.adj(v);
    return vw.size();
}

int maxDegree(Graph &G)
{
    int max = 0;
    for(int v = 0; v < G.V(); v++) {
        max = std::max(max, degree(G, v));
    }
    return max;
}

double avgDegree(Graph const &G)
{
    return 2.0 * G.E() / G.V();
}


int numberOfSelfLoops(Graph &G)
{
   int count = 0;
   for (int v = 0; v < G.V(); v++) {
       for(auto w : G.adj(v)) {
           if (v == w) {
	       count++;
	   }
       }
   }
   return count;
}
