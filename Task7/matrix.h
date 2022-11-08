#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

#pragma once
using namespace std;

template<typename Type>
class Matrix{
public:
    int m, n;
    vector<vector<Type>> data;

    Matrix(){
        m = n = 0;
    }

    void write_file(string path){
        ofstream file;
        file.open(path);
        file << m << " " << n << endl;
        file << "csv" << endl;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                file << data[i][j] << " ";
            }
            file << endl;
        }
        file.close();
    }

    void read_file(string arg){
        string file_type;
        ifstream file(arg);
        file >> m >> n;
        file >> file_type;
        for (int i = 0; i < m; i++){
            vector<Type> buf_v;
            for (int j = 0; j < n; j++){
                Type buf;
                file >> buf;
                buf_v.push_back(buf);
            }
            data.push_back(buf_v);
        }
    }

    Matrix<Type> operator*(Matrix<Type> x){
        if (n != x.m) {
            cerr << "Wrong matrix dimensions!" << endl;
            exit(EXIT_FAILURE);
        }
        Matrix<Type> result;
        for (int k=0; k < m; k ++) {
            vector<Type> buf2;
            for (int l = 0; l < x.n; l++) {
                Type buf_num = 0;
                for (int j = 0; j < n; j++) {
                    buf_num += data[k][j] * x.data[j][l];
                }
                buf2.push_back(buf_num);
            }
            result.data.push_back(buf2);
        }
        result.m = m;
        result.n = x.n;
        return result;
    }

    Matrix<Type> operator+(Matrix<Type> x){
        if ((n != x.n) || (m != x.m)){
            cerr << "Wrong matrix dimensions for sum";
            exit(EXIT_FAILURE);
        }
        Matrix<Type> result;
        for (int i=0; i < m; i++){
            vector<Type> buf;
            for (int j=0; j < n; j++){
                buf.push_back(data[i][j] + x.data[i][j]);
            }
            result.data.push_back(buf);
        }
        result.m = m;
        result.n = n;
        return result;
    }

    Matrix<Type> operator-(Matrix<Type> x){
        if ((n != x.n) || (m != x.m)){
            cerr << "Wrong matrix dimensions for -dif";
            exit(EXIT_FAILURE);
        }
        Matrix<Type> result;
        for (int i=0; i < m; i++){
            vector<Type> buf;
            for (int j=0; j < n; j++){
                buf.push_back(data[i][j] - x.data[i][j]);
            }
            result.data.push_back(buf);
        }
        result.m = m;
        result.n = n;
        return result;
    }

    Matrix<Type> operator*(Type x){
        Matrix<Type> result;
        result.data = data;
        result.m = m;
        result.n = n;
        for (int i=0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result.data[i][j] *= x;
            }
        }
        return result;
    }

    Matrix<Type> transpose(){
        Matrix<Type> result;
        result.data = data;
        for (int i=0; i < m; i++){
            for (int j=0; j<n; j++){
                result.data[i][j] = data[j][i];
            }
        }
        result.m = n;
        result.n = m;
        return result;
    }

    template<class UserMatrix>
    friend Matrix<Type> solve(UserMatrix& A, Matrix<Type>& B, Matrix<Type>& X0){
        Matrix<Type> Rk = A.transpose()*B - A.transpose()*A*X0;
        Matrix<Type> ac_R0 = B - A*X0;
        Matrix<Type> ac_Rk = ac_R0;
        //cout << (ac_Rk.transpose()*ac_Rk).data[0][0];
        Matrix<Type> Zk = Rk;
        Matrix<Type> Xk = X0;
        Matrix<Type> r_buf;
        Matrix<Type> z_buf;
        Type Alphak;
        Type Betak;

        while ( sqrt((ac_Rk.transpose()*ac_Rk).data[0][0] / (ac_R0.transpose()*ac_R0).data[0][0]) > pow(10, -1)){
            //cout << sqrt((ac_Rk.transpose()*ac_Rk).data[0][0] / (ac_R0.transpose()*ac_R0).data[0][0]) <<endl;
            r_buf = Rk;
            z_buf = Zk;
            Matrix<Type> AZk = A*Zk;
            Type Rk_norm =(Rk.transpose()*Rk).data[0][0];
            Alphak = (Rk_norm) / ((AZk.transpose()*AZk).data[0][0]);
            Xk = Xk + Zk*Alphak;
            Rk = Rk - A.transpose()*AZk * Alphak;
            ac_Rk = ac_Rk - AZk*Alphak;
            Betak = ((Rk.transpose()*Rk).data[0][0]) / ((r_buf.transpose()*r_buf).data[0][0]);
            Zk = Rk + z_buf * Betak;

//            for (int i=0; i<Xk.m; i++){
//                for (int j=0; j<Xk.n; j++){
//                    cout << Xk.data[i][j] << " ";
//                }
//                cout << endl;
//            }
//            cout << "----" <<endl;
        }
        //cout << count;
        return Xk;
    }
};