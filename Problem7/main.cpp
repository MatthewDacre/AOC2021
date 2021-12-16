#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

vector<int> crabs;


double sumNat(int n){
    return (n*(n+1))/2;
}
void part1(){
    int sum = 0;
    int midVal = crabs[round(crabs.size()/2)];
    for(int i = 0; i < crabs.size(); i++){
        sum += abs(crabs[i] - midVal);
    }
    cout<<sum<<endl;
}

void part2(){
    int sum;
    int small = INT_MAX;
    for(int i = 0; i < crabs[crabs.size() - 1]; i++){
        sum=0;
        for(int t : crabs){
            sum += sumNat(abs(i - t));
            // if(i == 5){
            //     cout<<"From "<<t<<" Fuel "<<sumNat(abs(i - t))<<endl;
            // }
        }
        small = min(sum, small);
    }
    cout<<small<<endl;
}

int main(int argc, char const *argv[])
{
    fstream file;
    string s;
    file.open("input", ios::in);
    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    while(!file.eof()){
        string s;
        getline(file, s, ',');
        crabs.push_back(stoi(s));
    }
    sort(crabs.begin(), crabs.end());
    part1();
    part2();

    return 0;
}
