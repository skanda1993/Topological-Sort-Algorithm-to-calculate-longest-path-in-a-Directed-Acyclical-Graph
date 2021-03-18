#ifndef TEXTFILEHANDLER_H
#define TEXTFILEHANDLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "i_file_handler.h"
#include "smurf_segment.h"

namespace navigator
{
namespace files
{

class TextFileHandler: public IFileHandler
{

public:
    explicit TextFileHandler() = default;
    TextFileHandler(const TextFileHandler& other) = delete;
    TextFileHandler(const TextFileHandler&& other) = delete;
    TextFileHandler& operator=(const TextFileHandler& other) = delete;
    TextFileHandler& operator=(const TextFileHandler&& other) = delete;
    virtual ~TextFileHandler() = default;

    void ReadFile();
    void WriteFile();
    std::vector<navigator::data::SmurfSegment> GetFileData();

private:
    void AddSegment(navigator::data::SmurfSegment& segment) noexcept;

private:
    std::vector<navigator::data::SmurfSegment> _segments;
};

std::istream& operator>>(std::istream& str, navigator::data::SmurfSegment& segment) noexcept;
std::ostream& operator<<(std::ostream &str, TextFileHandler &handler) noexcept;

} // files
} // navigator

#endif // TEXTFILEHANDLER_H
