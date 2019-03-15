#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "Logger.h"

class Parser {
public:
    Parser();
    void read_csv(std::string filename);
    Logger logger;

};

#endif

