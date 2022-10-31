#include <iostream>
#include "read_file.h"
#include "dot_checker.h"
#include "parse_arguments.h"

int main(int argc, char** argv)
{
    string filename;
    double x, y;
//    cout << "Input full filename: ";
//    cin >> filename;
//    if (filename == "\n") {
//        filename == "D:\\Files\\CLionProjects\\Task1-3\\poly.txt";
//    }
    ErrorHandler arg_err_info = parse_errors(argc, argv, filename, x,y);
    cout << get_argument_error_name(arg_err_info) << endl;
    if (get_argument_error_name(arg_err_info) == "Arguments inputted successfully"){
        vector<double> poly_x;
        vector<double> poly_y;
        DecrypErrors err_info = parse_file(filename, poly_x, poly_y);

        cout << get_error_name(err_info) << endl;

        if (get_error_name(err_info) == "Polygon is imported successfully!") {
            int res = check_dot(poly_x, poly_y, x, y);
            if (res == 1) cout << "Inside!";
            if (res == 2) cout << "Belong polygon!";
            if (res == 0) cout << "Outside";
            return 0;
        }
        else return -1;
    }
    else return -1;

    return 0;
}
