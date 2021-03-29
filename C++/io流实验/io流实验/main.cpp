//
//  main.cpp
//  io流实验
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

int main(int argc, const char * argv[]) {
    srand((unsigned)time(nullptr));
    int n = rand()%1000+1;
    int x;
    do{
        cout<<"请输入你猜的数字"<<endl;
        cin>>x;
        while(cin.fail()){
            cout<<"输入不合法，请重新输入"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            cin>>x;
        }
        if(x>n) cout<<"大了"<<endl;
        else if(x<n) cout<<"小了"<<endl;
        else cout<<"回答正确"<<endl;
    }while(x!=n);
    return 0;
}
