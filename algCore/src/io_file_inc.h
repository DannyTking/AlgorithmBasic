#pragma once

#include "std_inc.h"
#include <fstream>
#include <sstream>

std::vector<std::vector<int>> InputIntStream(std::string const& filePath)
{
    std::vector<std::vector<int>> ret;
    std::ifstream ifs(filePath);
    if (!ifs.is_open()) {
        return ret;
    }
    int V = 0, E = 0;
    std::string line;
    std::stringstream ss;

    std::getline(ifs, line);
    ss << line;
    ss >> V;
    ss.clear();

    std::getline(ifs, line);
    ss << line;
    ss >> E;
    ss.clear();
    
    ret.push_back({V});
    ret.push_back({E});

    while(E > 0) {
    	int v = 0;
	int w = 0;
        std::getline(ifs, line);
	ss<<line;
	ss >> v >> w;
        ss.clear();

	E--;
	ret.push_back({v, w});
    }
    return ret;

}
