#include "matrix.h"
//#include "matrix.cpp"

int main(int argc, char **argv){
    if (argc != 5){
        cerr << "Wrong amount of arguments." << endl;
        exit(EXIT_FAILURE);
    }
    Matrix<double> A;
    Matrix<double> B;
    Matrix<double> X0;
    A.read_file(argv[1]);
    B.read_file(argv[2]);
    X0.read_file(argv[3]);
    Matrix<double> C = A.solve(A,B,X0);

    for (int i=0; i<C.m; i++){
        for (int j=0; j<C.n; j++){
            cout << C.data[i][j] << " ";
        }
        cout << endl;
    }

    C.write_file(argv[4]);
    return 0;
}