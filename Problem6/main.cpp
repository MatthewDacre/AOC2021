#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <assert.h>

using namespace std;

long long fish[9];

void printFish(){
    for(int i = 0; i < 9; i++){
        cout<<"Timer: "<<i<<" Amount: "<<fish[i]<<endl;
    }
}

void printSum(){
    long long sum = 0;
    for(int i = 0; i < 9; i++){
        sum += fish[i];
    }
    cout<<sum<<endl;
}

string counts(){
    string s;
    for(int i = 0; i < 9; i++){
        s += to_string(fish[i]) + ", ";
    }
    return s;
}

void part1(){
    for(int day = 0; day < 256; day++){
        //cout<<"Day "<<day<<" : "<<counts()<<endl;
        //printSum();
        int nextday[9];
        for(int i = 1; i < 9; i++){
            nextday[i-1] = fish[i];
        }
        //0 case
        nextday[6] += fish[0];
        nextday[8] = fish[0];
        for(int i = 0; i < 9; i++){
            fish[i] = nextday[i];
        }
        
    }
    printFish();
    printSum();
}

int main(int argc, char const *argv[])
{
    fstream file;
    string s;
    file.open("sample", ios::in);
    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    while(!file.eof()){
        file>>s;
    }
    for(char c : s){
        if(c != ','){
            int a = c - '0';
            fish[a]++;
        }
    }
    //printFish();
    part1();
    return 0;
}
