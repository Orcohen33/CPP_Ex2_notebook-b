#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <string>
#include "Notebook.hpp"
#include "Direction.hpp"
#include "doctest.h"
using namespace std;
using namespace ariel;

const int LINE_LENGTH = 100;
const int MAX_ROW = UINT16_MAX;
const int MAX_PAGE = UINT16_MAX;


// generate random message
string randMessage(){
    string str;
    unsigned int length = rand()%10;
    for(int i = 0; i<length; i++){
        str += rand()%(126-32+1) + 32;
    }
    return str;
}


TEST_CASE("Test 1:Write and then read"){
    Notebook n;
    
    for(int i = 0 ; i<3000; i++){
        unsigned int rand_row = rand() % MAX_ROW;
        unsigned int rand_page = rand() % MAX_PAGE;
        unsigned int rand_col = rand() % 100;
        Direction rand_dir = rand()%2 == 1? Direction::Horizontal : Direction::Vertical;
        string rand_msg = randMessage();
        
        // if message length is greater then 100 we regenerate new string
        if((ulong)rand_col+rand_msg.size()> 100){
            CHECK_THROWS(n.write(rand_page, rand_row, rand_col, rand_dir, rand_msg));
            
        }else{
        CHECK_NOTHROW(n.write(rand_page, rand_row, rand_col, rand_dir, rand_msg));              // write without any error
        CHECK(n.read(rand_page, rand_row, rand_col, rand_dir, rand_msg.size()) == rand_msg);    // read what 'written' above in the notebook
        }
    }

}

TEST_CASE("Test 2:Erase and read"){
    Notebook n;

    for(int i = 0 ; i<3000; i++){
        unsigned int rand_row = rand() % MAX_ROW;
        unsigned int rand_page = rand() % MAX_PAGE;
        unsigned int rand_col = rand() % 100;
        Direction rand_dir = rand()%2 == 1? Direction::Horizontal : Direction::Vertical;
        unsigned int len = rand()% 15;
        
        
        if((ulong)(rand_col+len)> 100){
            CHECK_THROWS(n.erase(rand_page, rand_row, rand_col, rand_dir, len));
        }else{

        string erase_symbol;
        for(int i = 0 ; i< len; i++){    // fill erase_symbol
            erase_symbol+='~';}

        CHECK_NOTHROW(n.erase(rand_page, rand_row, rand_col, rand_dir, len));
        CHECK(n.read(rand_page, rand_row, rand_col, rand_dir, len) == erase_symbol);
        }
    }
}

TEST_CASE("Test 3:Read from empty board"){
        Notebook n;

    for(int i = 0 ; i<3000; i++){
        unsigned int rand_row = rand() % MAX_ROW;
        unsigned int rand_page = rand() % MAX_PAGE;
        unsigned int rand_col = rand() % 100;
        Direction rand_dir = rand()%2 == 1? Direction::Horizontal : Direction::Vertical;
        unsigned int len = rand()% 15;
        
        
        if((ulong)(rand_col+len)> 100){
            CHECK_THROWS(n.erase(rand_page, rand_row, rand_col, rand_dir, len));
        }else{

        string empty_symbol;
        for(int i = 0 ; i< len; i++){    // fill erase_symbol
            empty_symbol+='_';}

        CHECK_NOTHROW(n.erase(rand_page, rand_row, rand_col, rand_dir, len));
        CHECK(n.read(rand_page, rand_row, rand_col, rand_dir, len) == empty_symbol);
        }
    }
}

TEST_CASE("Test 4:Write for both directions"){
    /*
    Test
     o
     u
     r
    board for
    assignment two
    */
    Notebook n;

    n.write(0,0,0,Direction::Horizontal, "Test");
    n.write(0,1,1,Direction::Vertical, "our");
    n.write(0,4,0,Direction::Horizontal, "board");
    n.write(0,4,6,Direction::Horizontal, "for");
    n.write(0,5,0,Direction::Horizontal, "assignment");
    n.write(0,5,11,Direction::Horizontal, "two");

    CHECK(n.read(0,0,0,Direction::Horizontal,4) == "Test");
    CHECK(n.read(0,1,0,Direction::Horizontal,3) == "_o_");
    CHECK(n.read(0,2,0,Direction::Horizontal,4) == "_u_");
    CHECK(n.read(0,3,0,Direction::Horizontal,4) == "_r_");
    CHECK(n.read(0,1,1,Direction::Vertical,4) == "our");
    CHECK(n.read(0,4,0,Direction::Horizontal,9) == "board_for");
    CHECK(n.read(0,5,0,Direction::Horizontal,14) == "assignment_two");
}

