#ifndef CSVPARSER_H
#define CSVPARSER_H
#include <string>
#include "Logger.h"

class CSVParser {
public:
    CSVParser();
    void print_csv(std::string filename);
    Logger logger;

};

#endif

