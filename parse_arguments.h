#include <iostream>
#include <string>
#pragma once
using namespace std;

enum class ErrorHandler{
    TO_MUCH_ARGUMENTS = -3,
    NOT_A_NUMBER = -2,
    INSUFFICIENT_ARGUMENTS = -1,
    SUCCESS = 0
};

[[nodiscard]] ErrorHandler parse_errors(int argc, char** argv, string& filename, double& x, double& y);
string get_argument_error_name(ErrorHandler err_info);