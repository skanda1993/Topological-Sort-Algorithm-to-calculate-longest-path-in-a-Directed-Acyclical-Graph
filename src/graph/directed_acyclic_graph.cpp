#include "directed_acyclic_graph.h"

namespace navigator
{
namespace dag
{

DirectedAcyclicGraph::DirectedAcyclicGraph(int n)
{
    _vertices = new GRAPH_VERTEX();
    for (int i = 0; i < n; i++)
    {
        GRAPH_EDGE edge_;
        _vertices->insert(make_pair(i, std::move(edge_)));
    }
    _edge_count = 0;
}

DirectedAcyclicGraph::DirectedAcyclicGraph(const DirectedAcyclicGraph& other) noexcept
{
    _vertices = other._vertices;
    _edge_count = other._edge_count;
}

DirectedAcyclicGraph::DirectedAcyclicGraph(const DirectedAcyclicGraph&& other) noexcept
{
    _vertices = other._vertices;
    _edge_count = other._edge_count;
}

DirectedAcyclicGraph& DirectedAcyclicGraph::operator= (const DirectedAcyclicGraph& rhs) noexcept
{
    if (this != &rhs)
    {
        for (auto it = rhs._vertices->begin();; it++)
        {
            if (it == rhs._vertices->end())
                break;
            GRAPH_EDGE edges;
            if (!it->second.empty())
            {
                for (auto edge: it->second)
                {
                    edges.insert(std::move(edge));
                }
            }
            _vertices->insert(make_pair(it->first, std::move(edges)));
        }
    }

    return *this;
}

DirectedAcyclicGraph& DirectedAcyclicGraph::operator= (const DirectedAcyclicGraph&& rhs) noexcept
{
    if (this != &rhs)
    {
        _vertices = rhs._vertices;
    }
    return *this;
}

GRAPH_VERTEX* DirectedAcyclicGraph::operator()()
{
    return _vertices;
}

void DirectedAcyclicGraph::Clear()
{
    for (auto itr = _vertices->begin(); itr != _vertices->end(); itr++)
        itr->second.erase(itr->second.begin(), itr->second.end());
    _vertices->erase(_vertices->begin(), _vertices->end());
}

unsigned int DirectedAcyclicGraph::GetSize() const
{
    return _vertices->size();
}

unsigned int DirectedAcyclicGraph::GetEdgeCount() const
{
    return _edge_count;
}

void DirectedAcyclicGraph::AddDirectedEdge(const int u, const int v, const double cost)
{
    (*_vertices)[u][v] = cost;
    _edge_count++;
}

void DirectedAcyclicGraph::AddUndirectedEdge(const int u, const int v, const double cost)
{
    AddDirectedEdge(u, v, cost);
    AddDirectedEdge(v, u, cost);
}

void DirectedAcyclicGraph::AddUnweightedUndirectedEdge(const int u, const int v)
{
    AddUndirectedEdge(u, v, 0.0);
}

std::string DirectedAcyclicGraph::FormatPath(int start, int end, std::list<int>& path)
{
    std::stringstream ss;
    ss << "Path(" << start << ":" << end << ")[";
    if (path.size())
    {
        for (auto node: path)
        {
            ss << " -> ";
            ss << node;
        }
    }
    ss << "]";
    std::string s = ss.str();

    return s;
}

std::string DirectedAcyclicGraph::ToString() const
{
    std::stringstream os;
    os << "Graph[" << std::endl;

    for (auto it = _vertices->begin();; it++)
    {
        if (it == _vertices->end())
            break;
        os << " Node(" << it->first << ")[";
        if (!it->second.empty())
        {
            for (auto edge: it->second)
            {
                os << "Edge(" << "->" << edge.first << ",cost:" << edge.second << ")";
                os << ",";
            }
        }
        os << "]" << std::endl;
    }

    os << "]";

    return os.str();
}

std::ostream& operator<<(std::ostream &strm, const DirectedAcyclicGraph &graph) noexcept
{
    return strm << "____________________" << std::endl
                << graph.ToString()       << std::endl
                << "____________________" << std::endl ;
}

} // namespace dag
} // namespace navigator
