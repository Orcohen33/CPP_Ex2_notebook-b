#include <iostream>
#include <vector>
#include "Direction.hpp"
#include "Notebook.hpp"

using namespace std;

namespace ariel
{
    void Notebook::write(int page, int row, int column, ariel::Direction dir, const string &str)
    {
        int const max_row_length = 99;
        if (page < 0 || row < 0 || column < 0 || column > max_row_length || ((uint)column + str.length() > max_row_length && dir == Direction::Horizontal))
        {
            throw invalid_argument("Wrong input");
        }
        if (notebook.size() < page + 1)
        {
            notebook.resize((uint)page + 1, Page());
        }
        try
        {
            notebook[(uint)page].write((uint)row, (uint)column, dir, str);
        }
        catch (const string msg)
        {
            throw msg;
        }
    }

    string Notebook::read(int page, int row, int column, ariel::Direction dir, int length)
    {
        std::string str;
        if (page < 0 || row < 0 || column < 0 || length < 0)
        {
            throw "error";
        }
        if (notebook.size() < page + 1)
        {
            notebook.resize((uint)page + 1, Page());
        }
        try
        {
            str = this->notebook[(uint)page].read((uint)row, (uint)column, dir, length);
            return str;
        }
        catch (const string msg)
        {
            throw msg;
        }
    }
    void Notebook::erase(int page, int row, int column, ariel::Direction dir, int length)
    {
        if (page < 0 || row < 0 || column < 0 || length < 0)
        {
            throw "error";
        }
        if (notebook.size() < page + 1)
        {
            notebook.resize((uint)page + 1, Page());
        }
        try
        {
            notebook[(uint)page].erase((uint)row, (uint)column, dir, length);
        }
        catch (const string msg)
        {
            throw msg;
        }
    }
    void Notebook::show(int page)
    {
        cout << "*************** Page " << page << " ***************" << endl;
        if (page < 0)
        {
            throw "error";
        }
        this->notebook[(uint)page].show();
    }
}