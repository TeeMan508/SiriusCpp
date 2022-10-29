#include <iostream>
#include "read_file.h"
#include "dot_checker.h"

int main()
{
    string filename;
    cout << "Input full filename: "; 
    cin >> filename;
    if (filename == "\n") {
        filename == "C:\\Users\\TMN\\source\\repos\\Task1-2\\poly.txt";
    }
    vector<double> poly_x;
    vector<double> poly_y;
    DecrypErrors err_info = parse_file(filename, poly_x, poly_y);

    cout << get_error_name(err_info);

    if (get_error_name(err_info) == "Polygon is imported successfully!") {
        double x, y;
        cout << "Input point check to: ";
        cin >> x >> y;

        if (check_dot(poly_x, poly_y, x, y)) cout << "Inside!";
        else cout << "Outside!";
        return 0;
    }
    else return -1;
    return 0;
}
