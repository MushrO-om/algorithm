//
//  main.cpp
//  继承与派生
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
#include <time.h>
#include <cstdlib>

using namespace std;

class Shape{//抽象类
public:
    Shape(){cout<<"构造Shape类"<<endl;}
    virtual ~Shape(){cout<<"析构Shape类"<<endl;}
    virtual double area() = 0;//纯虚函数
};

class Rectangle : public Shape{
private:
    double height;
    double width;
public:
    Rectangle(){cout<<"无参数构造Rectangle类"<<endl;}
    Rectangle(double a, double b):height(a),width(b){cout<<"有参数构造Rectangle类"<<endl;}
    ~Rectangle(){cout<<"析构Rectangle类"<<endl;}
    double area();
};

double Rectangle::area(){
    return width*height;
}

class Circle : public Shape{
private:
    double r;
public:
    Circle(){cout<<"无参数构造Circle类"<<endl;}
    Circle(double a):r(a){cout<<"有参数构造Circle类"<<endl;}
    ~Circle(){cout<<"析构Circle类"<<endl;}
    double area();
};

double Circle::area(){
    return M_PI*r*r;
}

class Square : public Rectangle{
private:
    double edge;
public:
    Square(){cout<<"无参数构造Square类"<<endl;}
    Square(double a):edge(a){cout<<"有参数构造Square类"<<endl;}
    ~Square(){cout<<"析构Square类"<<endl;}
    double area();
};

double Square::area(){
    return edge*edge;
}

int main(int argc, const char * argv[]) {
    Rectangle rec(1,2);
    cout<<rec.area()<<endl;
    Circle c(2);
    cout<<c.area()<<endl;
    Square s(2);
    cout<<s.area()<<endl;
    return 0;
}
