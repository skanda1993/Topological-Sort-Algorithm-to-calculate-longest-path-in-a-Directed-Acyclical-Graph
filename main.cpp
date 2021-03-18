#include <iostream>
#include "text_file_handler.h"
#include "topological_sort_and_path_planner.h"
#include "utilities.h"

using namespace std;

int main()
{
    navigator::files::TextFileHandler tfh;
    tfh.ReadFile();
    std::cout << tfh;

    auto segments = tfh.GetFileData();
    navigator::dag::DirectedAcyclicGraph graph(segments.size());
    UpdateGraph(segments, graph);
    std::cout << graph;

    navigator::planner::topologicalSort_test(graph);
    return 0;
}
