#include "EdgeWeightedDigraph.h"

DirectedEdge::DirectedEdge(int v, int w, double weight):
	mV(v), mW(w), mWeight(weight)
{
}

double DirectedEdge::weight() {
	return mWeight;
}

int DirectedEdge::from() {
	return mV;
}

int DirectedEdge::to() {
	return mW;
}
EdgeWightedDigraph::EdgeWightedDigraph(int V):mV(V)
					      ,_adj(V)
{
}

int EdgeWightedDigraph::V() { return mV; }
int EdgeWightedDigraph::E() { return mE; }
void EdgeWightedDigraph::addEdge(DirectedEdge & e) {
	_adj[e.from()].push_back(e);
	mE++;
}

std::vector<DirectedEdge> EdgeWightedDigraph::edges() {
std::vector<DirectedEdge> ret;
for(int v = 0; v < mV; v++) {
	for(auto const& e : adj(v)) {
		ret.push_back(e);
	}
}
return ret;
}

