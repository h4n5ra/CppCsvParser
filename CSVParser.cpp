#include "CSVParser.h"
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;


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
        map["Name"].push_back(name);
        map["Age"].push_back(age);
        map["Weight"].push_back(weight);
        counter++;
        logger.info("Successfully mapped line "+to_string(counter));
    }
    
    return map;
}

void CSVParser::print_map(map<string, vector<string>> map){
    logger.info("Printing saved map of CSV file");
    for (auto t : map){
        cout << t.first << endl;
        cout << "[";
        for (auto i : t.second){
            cout << i << ", ";
        }
        cout << "]"<< endl;
    }
    logger.info("Finished printing map of CSV file");
}
