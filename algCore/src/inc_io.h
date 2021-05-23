#pragma once

#include "inc_std.h"
#include <fstream>
#include <sstream>

std::vector<std::vector<int>> InputIntStream(std::string const& filePath);
std::map<std::string, int> InputMapStream(std::string const& filePath);
std::vector<std::vector<std::string>> InputStringStream(std::string const& filePath, std::unordered_map<std::string, int> &mStats);
