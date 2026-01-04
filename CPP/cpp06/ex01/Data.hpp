#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data {
    int id;
    std::string name;
    double value;
    
    Data(int i = 0, const std::string& n = "", double v = 0.0);
    bool operator==(const Data& other) const;
    
    void display() const;
};

#endif