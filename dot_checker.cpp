#include "dot_checker.h"
#include <iostream>
Line::Line(double x_begin, double x_end, double y_begin, double y_end) {
	x1 = x_begin;
	x2 = x_end;
	y1 = y_begin;
	y2 = y_end;
}

bool Line::check_cross(double x, double y) {
	if (x1 == x2) {
		if ((y1 < y < y2) && (x <= x2)) return true;
		else return false;
	}
	else {
		if (y1 == y2) {
			if ((y == y1) && ((x < x2) || (x < x1))) return true;
			else return false;
		}
		else {
			if (((x1< x2) && (x1 < ((x2 - x1) * (y - y1) / (y2 - y1) + x1) < x2)) && ((x < x2) || (x < x1))) return true;
			else return false;
		}
	}
	return false;
}


bool check_dot(const vector<double>& poly_x, const vector<double>& poly_y, const double x, const double y) {
	int count = 0;
	//for (int i = 0; i < poly_x.size(); i += 1) { cout << poly_y.size() << endl; }
	for (int i = 0; i < poly_x.size()-1; i += 1) {
		//cout << i;
		Line line(poly_x[i], poly_x[i + 1], poly_y[i], poly_y[i + 1]);
		if (line.check_cross(x, y)) {
			count += 1;
		}
	}
	//cout << count << endl;
	if (count % 2 == 1) return true;
	return false;
}
