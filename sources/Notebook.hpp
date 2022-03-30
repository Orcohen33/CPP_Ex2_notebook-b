#include <iostream>
#include <vector>
#include "Direction.hpp"
#include "Page.hpp"

using namespace std;
namespace ariel
{
    class Notebook
    {
        /*
        This class represent a notebook that can store string of length up to 100 characters.
        Notebook object built from page and row class.
        The notebook is represented as vector of pages.
        Each page is represented as vector of rows.
        Each row is represented as vector of chars.
        */
    private:
        vector<Page> notebook;

    public:
        Notebook()
        {
            notebook.resize(1, Page());
        }
        void write(int page, int row, int column, ariel::Direction dir, const string &str);
        string read(int page, int row, int column, ariel::Direction dir, int length);
        void erase(int page, int row, int column, ariel::Direction dir, int length);
        void show(int page);
    };

}