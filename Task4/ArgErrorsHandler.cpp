#include "ArgErrorsHandler.h"

string get_argument_error_name(ErrorHandler err_info){
    switch (err_info) {
        case ErrorHandler::INSUFFICIENT_OR_OVERSUFFICIENT_ARGUMENTS:
            return "Wrong amount of arguments!";
        case ErrorHandler::SUCCESS:
            return "Arguments inputted successfully!";
        default:
            return "Unknown Error.";
    }
    return "Unknown Error";
}