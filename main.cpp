#include <iostream>
#include "sources/Direction.hpp"
#include "sources/Notebook.hpp"
#include <vector>

using namespace std;

int main()
{

    ariel::Notebook note;
    bool flag = true;
    while (flag)
    {
        cout << "Press 1 to write,\n2 to read,\n3 to erase,\n4 to show,\n5 to exit: " << endl;
        string command;
        cin >> command;

        if (command == "1")
        {
            int page, row, column;
            string str;
            int direc;
            ariel::Direction dir;
            cout << "Enter page, row, column, string \nand direction\n( 0->Horizontal, 1->Vertical ) : " << endl;
            cin >> page >> row >> column >> str >> direc;
            if (direc == 0)
            {
                dir = ariel::Direction::Horizontal;
            }
            else
            {
                dir = ariel::Direction::Vertical;
            }
            note.write(page, row, column, dir, str);
        }
        else if (command == "erase")
        {
            int page, row, column, length;

            int direc;
            ariel::Direction dir;
            cout << "Enter page, row, column, length \nand direction\n( 0->Horizontal, 1->Vertical ) : " << endl;
            cin >> page >> row >> column >> length >> direc;
            if (direc == 0)
            {
                dir = ariel::Direction::Horizontal;
            }
            else
            {
                dir = ariel::Direction::Vertical;
            }
            note.erase(page, row, column, dir, length);
        }
        else if (command == "read")
        {
            int page, row, column, length;
            int direc;
            ariel::Direction dir;
            cout << "Enter page, row, column, length \nand direction\n( 0->Horizontal, 1->Vertical ) : " << endl;
            cin >> page >> row >> column >> length >> direc;
            if (direc == 0)
            {
                dir = ariel::Direction::Horizontal;
            }
            else
            {
                dir = ariel::Direction::Vertical;
            }
            cout << note.read(page, row, column, dir, length) << endl;
        }
        else if (command == "exit")
        {
            flag = false;
        }
        else
        {
            cout << "error" << endl;
        }
    }
    return 0;
}