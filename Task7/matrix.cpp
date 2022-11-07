#include "Matrix.h"
#include <cmath>
//template<typename Type>
//Matrix<Type>::Matrix(){
//    m = n = 0;
//}
//
//template<typename Type>
//void Matrix<Type>::read_file(std::string arg){
//    string file_type;
//    ifstream file(arg);
//    file >> m >> n;
//    file >> file_type;
//    for (int i = 0; i < m; i++){
//        vector<Type> buf_v;
//        for (int j = 0; j < m; j++){
//            Type buf;
//            file >> buf;
//            //cout << buf;
//            buf_v.push_back(buf);
//        }
//        data.push_back(buf_v);
//    }
//}

//template<typename Type>
//Matrix<Type> Matrix<Type>::operator*(Matrix<Type> x) {
//    if (n != x.m) {
//        cerr << "Wrong matrix dimensions!" << endl;
//        exit(EXIT_FAILURE);
//    }
//    Matrix<Type> result;
//    for (int k=0; k < m; k ++) {
//        vector<Type> buf2;
//        for (int l = 0; l < x.n; l++) {
//            Type buf_num = 0;
//            for (int j = 0; j < n; j++) {
//                buf_num += data[k][j] * x.data[j, l];
//            }
//            buf2.push_back(buf_num);
//        }
//        result.data.push_back(buf2);
//    }
//    result.m = m;
//    result.n = x.n;
//    return result;
//}

//template <typename Type>
//Matrix<Type> Matrix<Type>::transpose() {
//    Matrix<Type> result;
//    for (int i=0; i < m; i++){
//        vector<Type> buf;
//        for (int j=0; j<n; j++){
//            buf.push_back(data[j][i]);
//        }
//        result.data.push_back(buf);
//    }
//    result.m = n;
//    result.n = m;
//    return result;
//}
//template<typename Type>
//Matrix<Type> Matrix<Type>::operator*(Type x) {
//    Matrix<Type> result;
//    result.m = m;
//    result.n = n;
//    for (int i=0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            result.data[i][j] *= x;
//        }
//    }
//    return result;
//}

//template<typename Type>
//Matrix<Type> Matrix<Type>::operator+(Matrix<Type> x) {
//    if ((n != x.n) || (m != x.m)){
//        cerr << "Wrong matrix dimensions for sum";
//        exit(EXIT_FAILURE);
//    }
//    Matrix<Type> result;
//    for (int i=0; i < m; i++){
//        vector<Type> buf;
//        for (int j=0; j < n; j++){
//            buf.push_back(data[i][j] + x.data[i][j]);
//        }
//        result.data.push_back(buf);
//    }
//    result.m = m;
//    result.n = n;
//    return result;
//}

//template<typename Type>
//Matrix<Type> Matrix<Type>::operator-(Matrix<Type> x) {
//    if ((n != x.n) || (m != x.m)){
//        cerr << "Wrong matrix dimensions for -dif";
//        exit(EXIT_FAILURE);
//    }
//    Matrix<Type> result;
//    for (int i=0; i < m; i++){
//        vector<Type> buf;
//        for (int j=0; j < n; j++){
//            buf.push_back(data[i][j] - x.data[i][j]);
//        }
//        result.data.push_back(buf);
//    }
//    result.m = m;
//    result.n = n;
//    return result;
//}

//template<typename Type>
//
//Type Matrix<Type>::dot(Matrix<Type> x, Matrix<Type> y){
//    if ((x.n != 1)){
//        cerr << "Can't calculate scalar for matrix's, just for vectors!";
//    }
//    Type result = 0;
//    for (int i = 0; i < m; i++){
//        result += data[m][0] * data[m][0];
//    }
//
//}

//
//template<typename Type>
//Matrix<Type> Matrix<Type>::solve(Matrix<Type> A, Matrix<Type> B, Matrix<Type> X0) {
//    Matrix<Type> Rk = B - A.transpose()*A*X0;
//    Matrix<Type> ac_Rk = B - A*X0;
//    Matrix<Type> Zk = Rk;
//    Matrix<Type> Xk = X0;
//    Matrix<Type> r_buf;
//    Matrix<Type> z_buf;
//    Type Alphak;
//    Type Betak;
//
//
//    while ((ac_Rk*ac_Rk.transpose()).data[0][0] > pow(10, -3)){
//        r_buf = Rk;
//        z_buf = Zk;
//        Alphak = ((Rk*Rk).data[0][0]) / (((A*Zk)*(A*Zk)).data[0][0]);
//        Xk += Zk*Alphak;
//        Rk -= A.transpose()*A*Zk;
//        ac_Rk -= A*Zk*Alphak;
//        Betak = ((Rk*Rk).data[0][0]) / ((r_buf*r_buf).data[0][0]);
//        Zk = Rk + Betak * z_buf;
//    }
//
//    return Xk;
//
//}