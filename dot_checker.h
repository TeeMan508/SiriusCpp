#include <string>
#include <vector>
#pragma once
using namespace std;

int check_dot(const vector<double>& poly_x, const vector<double>& poly_y, const double x, const double y);

class Line {
public:
    double x1, x2, y1, y2;
    Line(double x_begin, double x_end, double y_begin, double y_end);

    bool check_cross(double x, double y);
    bool check_belong(double x, double y);
};