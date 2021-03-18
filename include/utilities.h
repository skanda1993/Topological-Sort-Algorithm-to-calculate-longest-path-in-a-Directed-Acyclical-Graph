#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "directed_acyclic_graph.h"
#include <vector>
#include <cmath>

//  Calculates Eucleadean distance betwen two segments
//
//
//  @param a - From segment.
//  @param b - To segment
//  @return double - The cost of the edge.
//
double GetWeight(navigator::data::SmurfSegment& a,
                 navigator::data::SmurfSegment& b)
{
    return std::hypot((a._x - b._x), (a._y - b._y));
}


//  Adds each segment to as a directed edge to DAG
//
//
//  @param segments - array of segments
//  @param graph - DAG to be constructed
//
void UpdateGraph(std::vector<navigator::data::SmurfSegment>& segments,
                 navigator::dag::DirectedAcyclicGraph& graph)
{
    /*for(auto i: segments)
    {
        auto from_node = i._id;
        for(auto j: i._children)
        {
            graph.AddDirectedEdge(from_node, j, GetWeight(i, segments[j]));
        }
    }*/


  graph.AddDirectedEdge(0, 1, 3.);
  graph.AddDirectedEdge(0, 2, 2.);
  graph.AddDirectedEdge(0, 5, 3.);
  graph.AddDirectedEdge(1, 3, 1.);
  graph.AddDirectedEdge(1, 2, 6.);
  graph.AddDirectedEdge(2, 3, 1.);
  graph.AddDirectedEdge(2, 4, 10.);
  graph.AddDirectedEdge(3, 4, 5.);
  graph.AddDirectedEdge(5, 4, 7.);

}



#endif // UTILITIES_H_INCLUDED
