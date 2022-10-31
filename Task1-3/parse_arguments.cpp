#include "parse_arguments.h"
#include "sstream"

ErrorHandler parse_errors(int argc, char** argv, string& filename, double& x, double& y){
    if (argc < 4) return ErrorHandler::INSUFFICIENT_ARGUMENTS;
    if (argc > 4) return ErrorHandler::TO_MUCH_ARGUMENTS;

    filename = string(argv[1]);
    istringstream issx(argv[2]);
    istringstream issy(argv[3]);
    issx >> x;
    issy >> y;
    if ((issx.fail()) || (issy.fail())) return ErrorHandler::NOT_A_NUMBER;

    return ErrorHandler::SUCCESS;

}

string get_argument_error_name(ErrorHandler err_info){
    switch (err_info) {
        case ErrorHandler::INSUFFICIENT_ARGUMENTS:
            return "Not enough arguments";
        case ErrorHandler::TO_MUCH_ARGUMENTS:
            return "To much arguments";
        case ErrorHandler::NOT_A_NUMBER:
            return "Point coordinates is not double";
        case ErrorHandler::SUCCESS:
            return "Arguments inputted successfully";
        default:
            return "Unknown Error";
    }
    return "Unknown Error";
}