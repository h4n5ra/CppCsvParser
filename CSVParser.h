#ifndef CSVPARSER_H
#define CSVPARSER_H
#include <string>
#include <map>
#include <vector>
#include "Logger.h"

class CSVParser {
public:
    CSVParser();
    void print_csv(std::string filename);
    std::map<std::string,std::vector<std::string>> to_map(std::string filename);
    void print_map(std::map<std::string, std::vector<std::string>> map);
    Logger logger = Logger("csv_parser");

};

#endif

