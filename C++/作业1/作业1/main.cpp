//
//  main.cpp
//  作业1
//
//  Created by Ice Bear on 2021/3/19.
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

#define M 4
#define N 5

int** shenqing()
{
    int **mat = new int*[M];
    for(int i = 0;i<M;i++)
    {
        mat[i] = new int[N];
    }
    return mat;
}

void init(int **mat)
{
    cout<<"请输入"<<endl;
    for(int i = 0;i<M;i++)
    {
        for(int j = 0;j<N;j++)
        {
            int x;
            cin>>x;
            mat[i][j] = x;
        }
    }
}

void print(int **mat)
{
    cout<<"矩阵如下："<<endl;
    for(int i = 0;i<M;i++)
    {
        for(int j = 0;j<N;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void add(int **mat1, int **mat2, int **mat)
{
    for(int i = 0;i<M;i++)
    {
        for(int j = 0;j<N;j++)
        {
            mat[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
}

void sub(int **mat1, int **mat2, int **mat)
{
    for(int i = 0;i<M;i++)
    {
        for(int j = 0;j<N;j++)
        {
            mat[i][j] = mat1[i][j]-mat2[i][j];
        }
    }
}

void shifang(int **mat)
{
    for(int i = 0;i<M;i++) delete []mat[i];
    delete []mat;
}

int main() {
    int **mat1 = shenqing();
    int **mat2 = shenqing();
    int **mat3 = shenqing();
    init(mat1);
    init(mat2);
    add(mat1, mat2, mat3);
    print(mat3);
    sub(mat1, mat2, mat3);
    print(mat3);
    shifang(mat1);
    shifang(mat2);
    shifang(mat3);
    return 0;
}
