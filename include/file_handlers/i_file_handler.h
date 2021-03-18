#ifndef IFILEHANDLER_H_INCLUDED
#define IFILEHANDLER_H_INCLUDED

namespace navigator
{
namespace files
{


class IFileHandler
{
public:
    virtual void ReadFile() = 0;
    virtual void WriteFile() = 0;
};

} // files
} // navigator
#endif // IFILEHANDLER_H_INCLUDED
