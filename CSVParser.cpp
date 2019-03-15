#include "CSVParser.h"
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

//TODO: Implement header reading
CSVParser::CSVParser() {
    
    logger.info("Created Parser");
    
}

void CSVParser::print_csv(string filename){
    filename = filename+".csv";
    logger.info("Printing from"+filename);
    ifstream file(filename);
    string name, age, weight, line;
    int counter = 0;
    while(getline(file,line)){
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,age,',');
        getline(ss,weight,'\n');
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "Weight: " << weight << '\n';
        cout << "------------" << '\n';
        counter++;
        logger.info("Successfully read line "+to_string(counter));
    }
    file.close();

}

map<string, vector<string>> CSVParser::to_map(string filename){
    filename = filename+".csv";
    logger.info("Reading from "+filename);
    ifstream file(filename);
    string name, age, weight, line;
    map<string, vector<string>> map{
        {"Name",{}},
        {"Age",{}},
        {"Weight",{}}
    };
    int counter = 0;
    while(getline(file,line)){
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,age,',');
        getline(ss,weight,'\n');
        map["Name"].push_back(remove_r(name));
        map["Age"].push_back(remove_r(age));
        map["Weight"].push_back(remove_r(weight));
        counter++;
        logger.info("Successfully mapped line "+to_string(counter));
    }
    
    return map;
}

//TODO: Fix incorrect order of printing data. Maps are iterated alphabetically
void CSVParser::print_map(map<string, vector<string>> map){
    logger.info("Printing saved map of CSV file");
    for (auto t : map){
        cout << t.first << " :: ";
        cout << "[";
        for (auto i : t.second){
            cout << i << ", ";
        }
        cout << "]"<< endl;
    }
    logger.info("Finished printing map of CSV file");
}

string CSVParser::remove_r(std::string s){
    if(!s.empty() && s[s.size() - 1] == '\r'){
        return s.substr(0, s.size()-1);
    } else {
        return s;
    }
}
