#include "Parser.h"
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


Parser::Parser() {
    
    logger.info("Created Parser");
    
}

void Parser::read_csv(string filename){
    filename = filename+".csv";
    logger.info("Reading from"+filename);
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

