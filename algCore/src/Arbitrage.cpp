#include "Arbitrage.h" 
#include <cmath>
#include "EdgeWeightedDigraph.h"

int Arbitrage::run()
{
	int ret = 0;
	std::ifstream ifs { "./input/rates.txt" };
	if (!ifs.good()) return ret;

	std::stringstream ss;
	std::string line;
	std::getline(ifs, line);
	ss << line;
	int V;
	ss >> V;
	ss.clear();
	std::cout<<"V:"<<V<<std::endl;

	EdgeWightedDigraph G(V);
	for(int v = 0; v < V; v++) {
		std::getline(ifs, line);
		ss << line;
		std::string mS;
		ss >> mS;
		std::cout<<"$:"<<mS<<std::endl;
		for(int w = 0; w < V; w++) {
			double rate;
			ss >> rate;
			DirectedEdge e(v, w, -1.0 * std::log(rate));
			std::cout<<e<<std::endl;
			G.addEdge(e);
		}
		ss.clear();
	}
	std::cout<<G<<std::endl;
	return ret;
}
