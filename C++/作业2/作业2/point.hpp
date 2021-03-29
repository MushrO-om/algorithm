//
//  point.hpp
//  作业2
//
//  Created by Ice Bear on 2021/3/27.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef point_hpp
#define point_hpp

using std::cout;
using std::endl;
using std::cin;

class Point{
private:
    double x;
    double y;
public:
    Point():x(0),y(0){cout<<"默认构造了（0，0）点"<<endl;}
    Point(double a, double b):x(a),y(b){cout<<"有参数构造点"<<endl;}
    Point(Point &p):x(p.x),y(p.y){cout<<"拷贝构造点"<<endl;}
    ~Point(){cout<<"点析构"<<endl;}
    double get_dis(Point a, Point b);
    double get_x(){return x;}
    double get_y(){return y;}
    void set_x(double a){x = a;}
    void set_y(double a){y = a;}
    void output(){cout<<"点("<<x<<","<<y<<")"<<endl;}
    Point operator ++();//前置
    Point operator --();
    Point operator ++(int);//后置
    Point operator --(int);
};

Point Point::operator ++(){//调用了拷贝构造函数
    ++x;
    ++y;
    return *this;
}

Point Point::operator --(){
    --x;
    --y;
    return *this;
}

Point Point::operator ++(int){
    x++;
    y++;
    return *this;
}

Point Point::operator --(int){
    x--;
    y--;
    return *this;
}


double Point::get_dis(Point a, Point b)
{
    double dis = 0;
    dis = sqrt(pow((a.x-b.x),2)+pow(a.y-b.y,2));
    return dis;
}

#endif /* point_hpp */
