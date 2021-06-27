#pragma once
#include "inc_std.h"
#include "inc_io.h"

class DirectedEdge {
	public:
		DirectedEdge(int v, int w, double weight);
		double weight();
		int from();
		int to();
		friend std::ostream& operator << (std::ostream& os, DirectedEdge const& rhs) {
			return os << rhs.mV<<"->"<<rhs.mW<<" cost "<<rhs.mWeight;
		}
private:
		int mV {0};
		int mW {0};
		double mWeight {0.0};
};

class EdgeWightedDigraph {
public:
	EdgeWightedDigraph(int V);
	int V();
	int E();
	void addEdge(DirectedEdge & e);
	std::vector<DirectedEdge> const& adj(int v) { return _adj[v]; }
	std::vector<DirectedEdge> edges();
	friend std::ostream& operator << (std::ostream& os,  EdgeWightedDigraph const& p) {
		return os << p.mV <<", "<< p.mE;
	}
private:
	int mV {0};
	int mE {0};
	std::vector<std::vector<DirectedEdge>> _adj;

};
