// Simple test of readline

#include <iostream>
#include <string>
#include "readline/readline.h"
#include "readline/history.h"

using namespace std;

int main(int argc, char** argv)
{
    string line;
    while ((line = readline("ShiRu@linux:~$ ")) != "exit") {
        cout << "[" << line << "]" << endl;
        if (line!="") add_history(line.c_str());
        //free((char*)line.c_str());
    }

    return 0;
}