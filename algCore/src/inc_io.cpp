#include "inc_io.h"

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

std::vector<std::vector<std::string>> InputStringStream(std::string const& filePath, std::unordered_map<std::string, int> &mStats)
{
    std::vector<std::vector<std::string>> ret;
    std::ifstream ifs(filePath);
    if (!ifs.is_open()) {
        return ret;
    }
    std::string line;
    std::stringstream ss;


    while(std::getline(ifs, line)) {
	    std::string v;
	    std::string w;
	ss<<line;
	ss >> v >> w;
        ss.clear();

	mStats[v]++;
	mStats[w]++;
	ret.push_back({v, w});
    }
    return ret;
}

std::map<std::string, int> InputMapStream(std::string const& filePath)
{
    std::map<std::string, int> ret;
    std::ifstream ifs(filePath);
    if (!ifs.is_open()) {
        return ret;
    }
    std::string line;
    std::stringstream ss;

    while(std::getline(ifs, line)) {
	    std::string v;
	    int w;
	ss<<line;
	ss >> v >> w;
        ss.clear();

	ret.insert({v, w});
    }
    return ret;
}
