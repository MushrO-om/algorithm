//
//  main.cpp
//  矩阵
//
//  Created by Ice Bear on 2021/3/22.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

class Matrix{
private:
    int lines;
    int rows;
    int** mat;
public:
    Matrix(int m, int n):lines(m),rows(n){
        mat = new int*[m];
        for(int i = 0;i<m;i++)
            mat[i] = new int[n];
    }
    Matrix(Matrix &m){
        for(int i = 0; i<lines; i++){
            for(int j = 0; j<rows; j++){
                mat[i][j] = m.mat[i][j];
            }
        }
    }
    ~Matrix(){
        for(int i = 0;i<lines;i++)
            delete[] mat[i];
        delete[] mat;
    }
    int get_lines(){return lines;}
    int get_rows(){return rows;}
    int get_mat(int i, int j){return mat[i][j];}
    void input();
    void output();
    bool add(Matrix *a, Matrix *b, Matrix *c);
    bool sub(Matrix *a, Matrix *b, Matrix *c);
};

void Matrix::input(){
    cout<<"请依次输入"<<lines<<"x"<<rows<<"矩阵的共计"<<lines*rows<<"个元素"<<endl;
    for(int i = 0;i<lines;i++)
        for(int j = 0;j<rows;j++)
            cin>>mat[i][j];
}

void Matrix::output(){
    cout<<"矩阵如下"<<endl;
    for(int i = 0; i<lines; i++){
        for(int j = 0; j<rows; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool Matrix::add(Matrix *a, Matrix *b, Matrix *c){
    if(a->lines!=b->lines||a->rows!=b->rows) return false;
    for(int i = 0;i<a->lines;i++){
        for(int j = 0;j<a->rows;j++){
            c->mat[i][j] = a->mat[i][j]+b->mat[i][j];
        }
    }
    return true;
}

bool Matrix::sub(Matrix *a, Matrix *b, Matrix *c){
    if(a->lines!=b->lines||a->rows!=b->rows) return false;
    for(int i = 0;i<a->lines;i++){
        for(int j = 0;j<a->rows;j++){
            c->mat[i][j] = a->mat[i][j]-b->mat[i][j];
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    Matrix *pA1 = new Matrix(2,3), *pA2 = new Matrix(2,3), *pA3 = new Matrix(2,3);
    pA1->input();
    pA2->input();
    pA1->add(pA1, pA2, pA3);
    pA3->output();
    pA1->sub(pA1, pA2, pA3);
    pA3->output();
    delete pA1;
    delete pA2;
    delete pA3;
    return 0;
}
