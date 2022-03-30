#include <iostream>
#include <vector>
#include "Direction.hpp"
#include "Row.hpp"

using namespace std;

namespace ariel
{
    class Page
    {
        /*
        This class represent a page from notebook by vector of rows .
        initialize the vector with size of row and by default char '_'.
        max length of each row is 100.
        */
    private:
    public:
        vector<Row> page;
        Page()
        {
            page.resize(0, Row());
        }

        void write(uint row, uint column, ariel::Direction dir, const string &str)
        {
            {
                if (row < 0 || column < 0 || (column + str.length() > 100 && dir == Direction::Horizontal))
                {
                    throw "Wrong input";
                    return;
                }
                // check if str contain illegal chars
                for (uint i = 0; i < str.size(); i++)
                {
                    if ((int)(str[i]) < 32 || (int)(str[i]) > 125)
                    {
                        throw "Illegal char";
                    }
                }

                if (page.size() < row + 1)
                {
                    page.resize((uint)row + 1, Row());
                }

                if (dir == Direction::Horizontal)
                {
                    for (uint i = 0; i < str.size(); i++)
                    {
                        if (page[row].row[column + i] == '_')
                        {
                            page[row].row[column + i] = str[i];
                        }
                        else
                        {
                            throw "Need to erase before overwrite";
                            return;
                        }
                    }
                }
                else
                {
                    if (row + str.size() > page.size())
                    {
                        page.resize(row + str.size() + 1, Row());
                    }
                    for (uint i = 0; i < str.size(); i++)
                    {
                        if (page[row + i].row[column] == '_')
                        {
                            page[row + i].row[column] = str[i];
                        }
                        else
                        {
                            throw "Need to erase before overwrite";
                            return;
                        }
                    }
                }
            }
        }
        string read(uint row, uint column, ariel::Direction dir, int length)
        {
            if (row < 0 || column < 0 || column > 99 || ((uint)length + column > 100 && dir == Direction::Horizontal) || length < 0)
            {
                throw "error";
            }
            if (page.size() < row + 1)
            {
                page.resize((uint)row + 1, Row());
            }
            string str;
            if (dir == Direction::Horizontal)
            {
                for (uint i = 0; i < length; i++)
                {
                    str += page[row].row[column + i];
                }
            }
            else
            {
                if (row + (uint)length > page.size())
                {
                    page.resize(row + (uint)length + 1, Row());
                }
                for (uint i = 0; i < length; i++)
                {
                    str += page[row + i].row[column];
                }
            }
            return str;
        }

        void erase(uint row, uint column, ariel::Direction dir, int length)
        {
            try
            {
                if (row < 0 || column < 0 || column > 99 || ((uint)length + column > 99 && dir == Direction::Horizontal) || length < 0)
                {
                    throw "error";
                }
                if (page.size() < row + 1)
                {
                    page.resize((uint)row + 1, Row());
                }
                if (dir == Direction::Horizontal)
                {
                    for (uint i = 0; i < length; i++)
                    {
                        page[row].row[column + i] = '~';
                    }
                }
                else
                {
                    for (uint i = 0; i < length; i++)
                    {
                        page[row + i].row[column] = '~';
                    }
                }
            }
            catch (const char *msg)
            {
                throw msg;
            }
        }
        void show()
        {
            for (uint i = 0; i < page.size(); i++)
            {
                cout << i << ": ";
                for (uint j = 0; j < page[i].row.size(); j++)
                {
                    cout << page[i].row[j];
                }
                cout << endl;
            }
        }
    };
}