#include "Logger.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;

Logger::Logger(string name) {
    this->filename = name+".log";
    cout << "Logging to: ";
    cout << this->filename << endl;  
}

string string_time(){
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    string time_s = ctime(&time);
    time_s = time_s.substr(0, time_s.size()-1);
    return time_s;   
}

void Logger::print_log(){
    ifstream file;
    string line;
    file.open(this->filename);
    
    if (file.fail()){
        cerr << "Error opening file." << endl;
        exit(1);
    }
    
    while (getline(file, line)){
        cout << line << endl;
    }
    
    file.close();
}

void Logger::write_to_file(string line){
    ofstream file;
    file.open(this->filename, ios::out | ios::app);
    file << line << endl;
    file.close();
}

void Logger::info(string message){
    string line = "LOGGER - "+string_time()+" - INFO - "+message;
    write_to_file(line);
}

void Logger::warning(string message){
    string line = "LOGGER - "+string_time()+" - WARNING - "+message;
    write_to_file(line);
}

void Logger::debug(string message){
    string line = "LOGGER - "+string_time()+" - DEBUG - "+message;
    write_to_file(line);
}

void Logger::error(string message){
    string line = "LOGGER - "+string_time()+" - ERROR - "+message;
    write_to_file(line);
}

void Logger::fatal(string message){
    string line = "LOGGER - "+string_time()+" - FATAL - "+message;
    write_to_file(line);
}
