#include <string>
#include <sstream>
#include <fstream>
#include "text_file_handler.h"

namespace navigator
{
namespace files
{

void TextFileHandler::ReadFile()
{
    std::ifstream readFile("my_data.txt", std::ios::in);
    navigator::data::SmurfSegment segment;
    std::string line;

    while(readFile >> segment)
    {
        AddSegment(segment);
    }
}

void TextFileHandler::WriteFile()
{
    // Not implemented for this assignment
}

std::vector<navigator::data::SmurfSegment> TextFileHandler::GetFileData()
{
    return _segments;
}

void TextFileHandler::AddSegment(navigator::data::SmurfSegment& segment) noexcept
{
    _segments.push_back(std::move(segment));
}

std::istream& operator>>(std::istream& str, navigator::data::SmurfSegment& segment) noexcept
{
    std::string line;
    if(std::getline(str,line))
    {
        std::stringstream  lineStream(line);

        lineStream >> segment._id;
        lineStream >> segment._x;
        lineStream >> segment._y;

        size_t value;
        segment._children.clear();
        while(lineStream >> value)
        {
            segment._children.push_back(value);
        }
    }
    else
    {
        str.setstate(std::ios::failbit);
    }
    return str;
}

std::ostream& operator<<(std::ostream &str, TextFileHandler &handler) noexcept
{
    auto segments = handler.GetFileData();
    str << "Road Segments: " << segments.size() << " segments"
        << std::endl << "___________________" << std::endl;


    if(segments.size() > 0)
    {
        for(auto i: segments)
        {
            str << "{id:-> " << i._id << ", "
                << "x:-> " << i._x << ", "
                << "y:-> " << i._y << ", "
                << "children:-> {";

            for(auto j: i._children)
            {
                str  << j << ", ";
            }

            str << "}}" << std::endl;

        }
    }
    str << std::endl << "___________________" << std::endl;

    return str;
}

} // file
} // navigator
