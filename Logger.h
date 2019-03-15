#ifndef LOGGER_H
#define LOGGER_H
#include <string>

using namespace std;

class Logger {
public:
    Logger(string filename = "app");
    void print_log();
    void write_to_file(string line);
    void info(string message);
    void warning(string message);
    void debug(string message);
    void error(string message);
    void fatal(string message);
private:
    string filename;
};

#endif

