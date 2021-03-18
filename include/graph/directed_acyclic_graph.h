#ifndef DIRECTEDACYCLICGRAPH_H
#define DIRECTEDACYCLICGRAPH_H


#include <list>
#include <set>
#include <unordered_map>
#include <stack>
#include <sstream>
#include <iostream>
#include <memory>

namespace navigator
{
namespace dag
{


using GRAPH_EDGE = std::unordered_map<int, double>;
using GRAPH_VERTEX = std::unordered_map<int, GRAPH_EDGE>;

class DirectedAcyclicGraph
{
public:
    DirectedAcyclicGraph() = delete;
    explicit DirectedAcyclicGraph(int n);
    DirectedAcyclicGraph(const DirectedAcyclicGraph& other) noexcept;
    DirectedAcyclicGraph(const DirectedAcyclicGraph&& other) noexcept;
    DirectedAcyclicGraph& operator= (const DirectedAcyclicGraph& rhs) noexcept;
    DirectedAcyclicGraph& operator= (const DirectedAcyclicGraph&& rhs) noexcept;

    GRAPH_VERTEX* operator()();
    void Clear();
    unsigned int GetSize() const;
    unsigned int GetEdgeCount() const;
    void AddDirectedEdge(const int u, const int v, const double cost = 0.0);
    void AddUndirectedEdge(const int u, const int v, const double cost = 0.0);
    void AddUnweightedUndirectedEdge(const int u, const int v);
    static std::string FormatPath(int start, int end, std::list<int>& path);
    std::string ToString() const;

private:
    GRAPH_VERTEX* _vertices;
    int _edge_count;

};

std::ostream& operator<<(std::ostream &strm, const DirectedAcyclicGraph &graph) noexcept;

} // namespace dsa
} // namespace navigator

#endif // DIRECTEDACYCLICGRAPH_H
