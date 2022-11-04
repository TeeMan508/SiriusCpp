#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>

#pragma once
using namespace std;

class polynom{
public:
    vector<double> koef;
    polynom(vector<double> arg);
    void print_poly();
    polynom operator+(polynom x);
    polynom operator-(polynom x);
    polynom operator*(polynom x);
    polynom der();
    polynom integ(); // integral from 0 to x
    void calculate(string arg);
    void read_string(string arg);


};
