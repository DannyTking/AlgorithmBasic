#include "inc_search.h"
#include "Paths.h"
#include "CC.h"
#include "SymbolGraph.h"
int main(int argn, char* args[])
{
//    int ret = runSearch();
//    int ret = Paths::run();
//    int ret = CC::run();
    int ret = SymbolGraph::run();
    return ret;
}
