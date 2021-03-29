//
//  main.cpp
//  NFAtoDFA
//
//  Created by Ice Bear on 2021/3/24.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

void outSet(set<char> s){
    cout<<"[";
    for(set<char>::iterator iter = s.begin();iter!=prev(s.end());iter++){
        cout<<*iter<<",";
    }
    cout<<*prev(s.end());
    cout<<"]";
}

class NFA{
private:
    set<char> Q;   //NFA的状态集合
    set<char> T;    //字符集合
    map<pair<char,char>,set<char>> delta;    //状态转移集合
    char q0;        //起始状态
    set<char> F;   //NFA的终止状态集合
public:
    NFA();
    set<char> getQ(){return Q;}
    set<char> getT(){return T;}
    map<pair<char,char>,set<char>> getdelta(){return delta;}
    char getq0(){return q0;}
    set<char> getF(){return F;}
};

NFA::NFA(){
    char ch;
    cout<<"请输入NFA状态集合，以#结束"<<endl;
    cin>>ch;
    while(ch!='#'){
        Q.insert(ch);
        cin>>ch;
    }
    cout<<"请输入字符集合，以#结束"<<endl;
    cin>>ch;
    while(ch!='#'){
        T.insert(ch);
        cin>>ch;
    }
    cout<<"请输入起始状态"<<endl;
    cin>>q0;
    cout<<"请输入终止状态集合，以#结束"<<endl;
    cin>>ch;
    while(ch!='#'){
        F.insert(ch);
        cin>>ch;
    }
    char x;//转移条件
    char y;//转移后的状态
    cout<<"请输入状态转移集合，空状态用*表示，以#结束"<<endl;
    cout<<"请输入转移前的状态"<<endl;
    cin>>ch;
    while(ch!='#'){
        cout<<"请输入转移条件"<<endl;
        cin>>x;
        cout<<"请输入转移后的状态"<<endl;
        cin>>y;
        delta[{ch,x}].insert(y);
        cout<<"请输入转移前的状态"<<endl;
        cin>>ch;
    }
}

class DFA{
private:
    vector<set<char>> Q;   //DFA的状态集合
    set<char> T;    //字符集合
    map<pair<set<char>,char>,set<char>> delta;    //状态转移集合
    set<char> q0;
    set<set<char>> F;
    map<set<char>, int> inQ; //判断Q中是否已有该状态
public:
    DFA(NFA& nfa);
    void outDFA();
};

DFA::DFA(NFA& nfa){
    T = nfa.getT();
    q0.insert(nfa.getq0());
    Q.push_back(q0);
    inQ[q0] = 1;
    set<char> nF = nfa.getF();
    map<char,int> inF;
    for(auto item : nF) inF[item]=1;
    map<pair<char,char>,set<char>> deltan = nfa.getdelta();
    for(int i = 0;i<Q.size();i++)
    //遍历dfa中已有的状态，并不断向其中加入新的状态
    {
        //for(char item : Q[i])
        //for each不能改变！Q既不能删除变短也不能变长，会出bug！
        for(set<char>::iterator iter = Q[i].begin();iter!=Q[i].end();iter++)
        //Q[i]是set<char>类型的
        {
            char item = *iter;
            for(char t : T)
            {
                if(*deltan[{item,t}].begin()=='*') continue;
                //遇到空跳过
                else if(inQ[deltan[{item,t}]]==0)
                //遇到未出现的状态将其加入Q
                {
                    Q.push_back(deltan[{item,t}]);
                    inQ[deltan[{item,t}]] = 1;
                }
                //deltan[{item,t}]表示nfa中状态item经过输入t得到的状态集合
                //delta[{Q[i],t}]表示dfa中状态集合Q[i]经过输入t得到的状态集合
                delta[{Q[i],t}].insert(deltan[{item,t}].begin(),deltan[{item,t}].end());
            }
            if(inF[item]){
                F.insert(Q[i]);
            }
        }
    }
}

void DFA::outDFA(){
    cout<<"DFA的状态集合为："<<endl;
    for(auto item : Q) outSet(item);
    cout<<endl<<"DFA的字符集合为："<<endl;
    outSet(T);
    cout<<endl<<"DFA的起始状态为："<<endl;
    outSet(q0);
    cout<<endl<<"DFA的终止状态集合为："<<endl;
    for(auto item : F) outSet(item);
    cout<<endl<<"DFA的状态转换集合为："<<endl;
    map<pair<set<char>,char>,set<char>>::iterator iter;
    for(iter = delta.begin();iter!=delta.end();iter++)
    {
        cout<<"delta(";
        outSet(iter->first.first);
        cout<<","<<iter->first.second<<")="<<endl;
        outSet(iter->second);
        cout<<endl;
    }
}

int main() {
    NFA nfa;
    DFA dfa(nfa);
    dfa.outDFA();
    return 0;
}
