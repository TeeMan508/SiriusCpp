#include "polynom.h"
using namespace std;

int main(int argc, char **argv){
    //expression example "int + {1,2,3} + {4,5,6}"
    string expression = argv[1];
    vector<double> test_poly_koef;
    polynom test_poly(test_poly_koef);
    test_poly.calculate(expression);
    test_poly.print_poly();

}