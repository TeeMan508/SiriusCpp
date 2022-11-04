#include "polynom.h"
#include <regex>

polynom::polynom(vector<double> arg) {
    koef = arg;
}
void polynom::print_poly() {
    if (koef.size() < 1) {
        cout << "{}" << endl;
        return;
    }
    cout << "{";
    for (int i = 0; i<koef.size(); i++){
        if (i == koef.size() - 1) {
            cout << koef[i] << "}" << endl;
            return;
        }
        else{
            cout << koef[i] << ", ";
        }
    }
}

polynom polynom::operator+(polynom x) {
    vector<double> res_koef;
    polynom res(res_koef);
    for (int i=0; i < max(koef.size(), x.koef.size()); i++){
        if (i<koef.size()){
            if (i<x.koef.size()){
                res.koef.push_back(koef[i] + x.koef[i]);
            }
            else{
                res.koef.push_back(koef[i]);
            }
        }
        else{
            res.koef.push_back(x.koef[i]);
        }
    }
    return res;
}

polynom polynom::operator-(polynom x) {
    vector<double> res_koef;
    polynom res(res_koef);
    for (int i=0; i < max(koef.size(), x.koef.size()); i++){
        if (i<koef.size()){
            if (i<x.koef.size()){
                res.koef.push_back(koef[i] - x.koef[i]);
            }
            else{
                res.koef.push_back(koef[i]);
            }
        }
        else{
            res.koef.push_back(-x.koef[i]);
        }
    }
    return res;
}

polynom polynom::operator*(polynom x) {
    vector<double> res_koef;
    polynom res(res_koef);
    for (int i = 0; i < koef.size()+x.koef.size()-1; i++){
        double buf = 0;
        for (int j = 0; j <= i; j++){
            buf += koef[j] * x.koef[i-j];
        }
        res.koef.push_back(buf);
    }
    return res;
}

polynom polynom::der() {
    vector<double> res_koef;
    polynom res(res_koef);
    for (int i = 1; i <koef.size(); i++){
        res.koef.push_back(i*koef[i]);
    }
    return res;
}
// integral from 0 to x
polynom polynom::integ() {
    vector<double> res_koef;
    polynom res(res_koef);
    res.koef.push_back(0);
    for (int i = 0; i < koef.size(); i++){
        res.koef.push_back(koef[i]/(i+1));
    }
    return res;
}

void polynom::read_string(string arg) {
    stringstream ss(arg.substr(1, arg.size()-2));
    while (!ss.eof()){
        string line;
        std::getline(ss, line, ',');
        if ((line != "{") && (line != "}")){
            koef.push_back(stod(line));
        }
    }
}

void polynom::calculate(std::string arg) {
    string test = arg;
    regex regular("([\\w\\s-\+\*]+)"
                  "([\\d\\s\{\}\,]*)"
    );
    cmatch expression_res;
    try {
        regex_search(test.c_str(), expression_res, regular);
    } catch (const regex_error &e){
        cerr << "Wrong expression";
        exit(EXIT_FAILURE);
    }
    //cout << expression_res[0];
    stringstream poly_ss(expression_res[2]);
    vector<polynom> polynom_vec;
    while (!poly_ss.eof()){
        string poly_string;
        poly_ss >> poly_string;
        vector<double> poly_koef;
        polynom poly(poly_koef);

        poly.read_string(poly_string);
        polynom_vec.push_back(poly);
    }

    stringstream expression_ss(expression_res[1]);
    vector<string> operations_vec;
    while (!expression_ss.eof()){
        string operation;
        expression_ss >> operation;
        if (operation != "") {
            operations_vec.push_back(operation);
            //cout << operation << " ";
        }
    }
    vector<double> res_koef;
    polynom result(res_koef);
    //cout << polynom_vec.size() << "!!!" << operations_vec.size() <<endl;
    for (int i = operations_vec.size()-1; i >= 0; i--){
        if (operations_vec[i] == "int"){
            if (i == operations_vec.size()-1){
                //cout << operations_vec.size() - 1 - i + 1;
                result = polynom_vec[operations_vec.size() - 1 - i].integ();
            }
            else {
                //cout << "intgrating this: ";
                //result.print_poly();
                result = result.integ();
            }
        }
        if (operations_vec[i] == "der"){
            if (i == operations_vec.size()-1){
                result = polynom_vec[operations_vec.size() - 1 - i].der();
            }
            else {
                result = result.der();
            }
        }
        if (operations_vec[i] == "*"){
            if (i == operations_vec.size()-1){
                result = polynom_vec[operations_vec.size() - 1 - i] * polynom_vec[operations_vec.size() - 1 - i + 1];
            }
            else{
                result = result * polynom_vec[operations_vec.size() - 1 - i];
            }
        }
        if (operations_vec[i] == "+"){
            //cout << i <<endl;
            if (i == operations_vec.size()-1){
                result = polynom_vec[operations_vec.size() - 1 - i] + polynom_vec[operations_vec.size() - 1 - i + 1];
                //result.print_poly();
            }
            else {
                //result.print_poly();
                result = result + polynom_vec[operations_vec.size() - 1 - i];
            }
        }
        if (operations_vec[i] == "-"){
            if (i == operations_vec.size()-1){
                result = polynom_vec[operations_vec.size() - 1 - i] - polynom_vec[operations_vec.size() - 1 - i + 1];
            }
            else {
                //result.print_poly();
                result = result - polynom_vec[operations_vec.size() - 1 - i];
            }
        }
    }
    koef = result.koef;
}
