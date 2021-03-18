#ifndef SMURFSEGMENT_H_INCLUDED
#define SMURFSEGMENT_H_INCLUDED

#include<vector>

namespace navigator
{
namespace data
{

// Data structure to store segments read from file
struct SmurfSegment
{
    size_t _id; //-> starts from 0 and iterates without discontinuity
    double _x;
    double _y;
    std::vector<size_t> _children; //-> segments in link
};

} // data
} // navigator

#endif // SMURFSEGMENT_H_INCLUDED
