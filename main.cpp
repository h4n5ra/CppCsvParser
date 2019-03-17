#include "CSVParser.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    CSVParser p;
//    p.print_csv("test");
    map<string, vector<string>> map = p.to_map("test");
    p.print_map(map);

    return 0;
}

