#include "topological_sort_and_path_planner.h"
#include <algorithm>
#include <limits>

namespace navigator
{
namespace planner
{

TopologicalSortAndPathPlanner::TopologicalSortAndPathPlanner(Graph *graph)
{
    if (graph == nullptr)
    {
        throw std::invalid_argument("GRAPH NULL");
    }
    n_ = graph->GetSize();
    graph_ = graph;
}

const Graph& TopologicalSortAndPathPlanner::operator()()
{
    return *graph_;
}

int TopologicalSortAndPathPlanner::RunDepthFirstSearch(int i, int at, std::vector<bool>& visited, std::vector<int>& ordering)
{

    visited.at(at) = true;

    auto graphItr = (*graph_)()->find(at);
    if (graphItr != (*graph_)()->end())
    {
        if (!graphItr->second.empty())
        {
            for (auto edge: graphItr->second)
            {
                if (!visited[edge.first])
                {
                    i = RunDepthFirstSearch(i, edge.first, visited, ordering);
                }
            }
        }
    }

    ordering[i] = at;
    return i - 1;
}

std::vector<int> TopologicalSortAndPathPlanner::RunTopologicalSort()
{

    std::vector<int> ordering(n_, 0);
    std::vector<bool> visited(n_, false);

    int i = n_ - 1;
    for (unsigned at = 0; at < n_; at++)
        if (!visited[at])
            i = RunDepthFirstSearch(i, at, visited, ordering);

    return ordering;
}

std::vector<double> TopologicalSortAndPathPlanner::GetLongestPath(int start)
{
    std::vector<double> dist(n_, std::numeric_limits<double>::max());
    if (n_ == 0)
    {
        return dist;
    }

    if (start < 0 || (unsigned)start >= n_)
    {
        throw std::invalid_argument("Invalid start node index");
    }

    std::vector<int> topsort = RunTopologicalSort();

    dist[start] = 0.;

    for (unsigned i = 0; i < n_; i++)
    {

        int nodeIndex = topsort[i];
        if (dist[nodeIndex] != std::numeric_limits<double>::max())
        {

            auto adjacentEdges = (*graph_)()->find(nodeIndex);
            if (adjacentEdges != (*graph_)()->end())
            {
                if (!adjacentEdges->second.empty())
                {
                    for (auto edge: adjacentEdges->second)
                    {
                        double newDist = dist[nodeIndex] + (-1 * edge.second);


                        if (dist[edge.first] == std::numeric_limits<double>::max())
                        {
                            dist[edge.first] =  newDist;
                        }
                        else
                        {
                            dist[edge.first] = std::min(dist[edge.first],  newDist);
                        }
                    }
                }
            }
        }
    }

    std::transform(dist.begin(), dist.end(), dist.begin(), std::bind1st(std::multiplies<double>(), -1));
    return dist;
}


int topologicalSort_test(navigator::dag::DirectedAcyclicGraph& graph)
{

    TopologicalSortAndPathPlanner solver(&graph);

    std::vector<int> ordering = solver.RunTopologicalSort();

    {
        std::stringstream ss;
        for (auto node: ordering)
        {
            ss << "-> ";
            ss << node;
        }
        std::string s = ss.str();
        std::cout << std::endl << "Ordering :" << s << std::endl;
    }

    std::vector<double> dists = solver.GetLongestPath(0);

    for (size_t i=0; i< dists.size(); i++)
    {
        std::cout << "Longest path weight from 0 to " <<  i << ": " <<  dists[i] << std::endl;
    }

    return 0;
}


}
}
