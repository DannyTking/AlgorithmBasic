#pragma once

#include "inc_std.h"
#include <fstream>
#include <sstream>

struct BinData {
	int a;
	char c;
	float b;
};

std::ostream& operator << (std::ostream& os, BinData const& bin);

std::vector<std::vector<int>> InputIntStream(std::string const& filePath);
std::map<std::string, int> InputMapStream(std::string const& filePath);
std::vector<std::vector<std::string>> InputStringStream(std::string const& filePath, std::unordered_map<std::string, int> &mStats);

void SaveBinData(std::string const& filePath, char const* buffer, size_t len);
BinData ReadBinData(std::string const& filePath);
