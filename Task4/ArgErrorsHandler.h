#include <iostream>
#include <string>
#pragma once
using namespace std;

enum class ErrorHandler{
    INSUFFICIENT_OR_OVERSUFFICIENT_ARGUMENTS = -1,
    SUCCESS = 0
};

string get_argument_error_name(ErrorHandler err_info);