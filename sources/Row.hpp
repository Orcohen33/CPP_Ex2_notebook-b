#include <iostream>
#include <vector>
#include "Direction.hpp"

using namespace std;

namespace ariel
{
    class Row
    {
        /*
        This class represent a row in page inside notebook class by vector of chars.
        The default char of the vector is '_'
        Each row can contain string of length up to 100 characters.
        */
    private:
    public:
        vector<char> row;
        Row()
        {
            row.resize(100, '_');
        }
    };
}