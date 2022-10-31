#include <string>
#include <vector>
#pragma once
using namespace std;
enum class DecrypErrors {
    INCORRECT_DTYPE = -3,
    WRONG_NUMBER_OF_COORDINATES = -2,
    WRONG_PATH_OR_FTYPE = -1,
    SUCCESS = 0
};

[[nodiscard]] DecrypErrors parse_file(const string filename, vector<double>& x, vector<double>& y);
string get_error_name(DecrypErrors err_info);