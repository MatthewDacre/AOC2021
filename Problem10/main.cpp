#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

vector<string> lines;

bool isLeft(char c){
    return c == '(' || c == '[' || c == '{' || c == '<';
}

char toLeft(char c){
    switch (c)
    {
    case ')':
        return '(';
        break;
    case ']':
        return '[';
        break;
    case '}':
        return '{';
        break;
    case '>':
        return '<';
        break;
    default:
        return '0';
        break;
    }
}

int toScore(char c){
    switch (c)
    {
    case '(':
        return 3;
        break;
    case ')':
        return 3;
        break;
    case '[':
        return 57;
        break;
    case ']':
        return 57;
        break;
    case '}':
        return 1197;
        break;
    case '{':
        return 1197;
        break;
    case '<':
        return 25137;
        break;
    case '>':
        return 25137;
        break;
    default:
        return -1; 
        break;
    }
}

void part1(){
    int score = 0;
    for(string line : lines){
        stack<char> c;
        for(char t : line){
            if(c.empty()){
                c.push(t);
            }
            else{
                if(isLeft(t)){
                    c.push(t);
                }
                else{
                    //Right bracket, so need to make sure its the correct one
                    if(toLeft(t) != c.top()){
                        //Broken
                        //cout<<"Expected "<<c.top()<<", But found "<<t<<endl;
                        score += toScore(t);
                        break;
                    }
                    else{
                        //Correct character
                        c.pop();
                    }
                }
            }
        }
    }
    cout<<score<<endl;
}

int toScoreCompletion(char c){
    switch (c)
    {
    case '(':
        return 1;
        break;
    case ')':
        return 1;
        break;
    case '[':
        return 2;
        break;
    case ']':
        return 2;
        break;
    case '}':
        return 3;
        break;
    case '{':
        return 3;
        break;
    case '<':
        return 4;
        break;
    case '>':
        return 4;
        break;
    default:
        return -1; 
        break;
    }
}

void part2(){
    vector<long long> scores;
    for(string line : lines){
        stack<char> c;
        long long score = 0;
        bool broke = false;
        for(char t : line){
            if(c.empty()){
                c.push(t);
            }
            else{
                if(isLeft(t)){
                    c.push(t);
                }
                else{
                    //Right bracket, so need to make sure its the correct one
                    if(toLeft(t) != c.top()){
                        //Broken
                        //Discard the line
                        broke = true;
                        break;
                    }
                    else{
                        //Correct character
                        c.pop();
                    }
                }
            }
        }
        if(!broke){
            //Never broke, now need to complete the line
            while(!c.empty()){
                //For each element, pop it and add its score
                score = score*5 + toScoreCompletion(c.top());
                c.pop();
            }
            scores.push_back(score);
        }
    }
    sort(scores.begin(), scores.end());
    for(long long s : scores){
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<scores[round(scores.size()/2)]<<endl;

}

int main(int argc, char const *argv[])
{
    fstream file;
    file.open("input", ios::in);
    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    while(!file.eof()){
        string s;
        file>>s;
        lines.push_back(s);
    }

    part1();
    part2();

    return 0;
}
