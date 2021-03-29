//
//  main.cpp
//  作业2
//
//  Created by Ice Bear on 2021/3/21.
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
#include "point.hpp"
#include "circle.hpp"

int main() {
    double a,b,c;
    Circle c1,c2;
    cout<<"输入d以采用默认构造的圆1"<<endl;
    char ch,ch2;
    cin>>ch;
    if(ch!='d')
    {
        cout<<"请输入圆1的圆心坐标及半径"<<endl;
        cin>>a>>b>>c;
        c1 = Circle(a,b,c);
    }
    cout<<"输入d以采用默认构造的圆2"<<endl;
    cin>>ch2;
    if(ch2!='d')
    {
        cout<<"请输入圆2的圆心坐标及半径"<<endl;
        cin>>a>>b>>c;
        c2 = Circle(a,b,c);
    }
    if(c1.xiangjiao(c1,c2)) cout<<"两圆相交"<<endl;
    else cout<<"两圆不相交"<<endl;
    Point p;
    ++p;
    p.output();
    --p;
    p.output();
    p++;
    p.output();
    p--;
    p.output();
    return 0;
}
