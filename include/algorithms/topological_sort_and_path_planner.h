#ifndef TOPOLOGICALSORTANDPATHPLANNER_H
#define TOPOLOGICALSORTANDPATHPLANNER_H


#include "directed_acyclic_graph.h"

#include <vector>
#include <unordered_map>
#include <exception>



namespace navigator
{
namespace planner
{

using Graph = navigator::dag::DirectedAcyclicGraph;

class TopologicalSortAndPathPlanner
{
public:

  explicit TopologicalSortAndPathPlanner(Graph *graph);
  TopologicalSortAndPathPlanner() = delete;
  TopologicalSortAndPathPlanner(const TopologicalSortAndPathPlanner&) = delete;
  TopologicalSortAndPathPlanner(const TopologicalSortAndPathPlanner&&) = delete;
  TopologicalSortAndPathPlanner& operator=(TopologicalSortAndPathPlanner const&) = delete;
  TopologicalSortAndPathPlanner& operator=(TopologicalSortAndPathPlanner const&&) = delete;

  const Graph& operator()();
  std::vector<int> RunTopologicalSort();
  std::vector<double> GetLongestPath(int start);

private:
  int RunDepthFirstSearch(int i, int at, std::vector<bool>& visited, std::vector<int>& ordering);


  private:
  Graph* graph_;
  unsigned n_;

};


int topologicalSort_test(navigator::dag::DirectedAcyclicGraph& graph);

} // namespace planner
} // namespace dsa

#endif // TOPOLOGICALSORTANDPATHPLANNER_H
