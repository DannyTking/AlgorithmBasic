//#include "inc_search.h"
//#include "Paths.h"
//#include "CC.h"
#include "inc_io.h"
#include "SymbolGraph.h"

int main(int argn, char* args[])
{
//    int ret = runSearch();
//    int ret = Paths::run();
//    int ret = CC::run();
   
    BinData cc {3333, 'i', 2.31};
    std::cout<<"init data struct : "<<cc<<std::endl;
    SaveBinData("./input/struct.bin", reinterpret_cast<char const*>(&cc), sizeof(cc));

    BinData fcc = ReadBinData("./input/struct.bin");
    std::cout<<"file date struct : " <<fcc<<std::endl;
    int ret = SymbolGraph::run();
    return ret;
}
