#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

char mostCommon(int pos, vector<string> vals){
    int count0 = 0;
    int count1 = 0;
    for(string s : vals){
        switch (s[pos])
        {
        case '0':
            count0++;
            break;
        case '1':
            count1++;
            break;
        default:
            break;
        }
    }
    if(count0 > count1){
        return '0';
    }
    else{
        return '1';
    }
}

string oxygen(vector<string> vals){
    int max = vals[0].size();
    for(int i = 0; i < max; i++){
        char most = mostCommon(i, vals);
        for(int j = 0; j < vals.size(); j++){
            if(vals[j][i] != most){
                vals.erase(vals.begin()+j);
            }
        }
        if(vals.size() == 1){
            return vals[0];
        }
    }
    return vals[0];
}
string co2(vector<string> vals){
    int max = vals[0].size();
    for(int i = 0; i < max; i++){
        char most = mostCommon(i, vals);
        for(int j = 0; j < vals.size(); j++){
            if(vals[j][i] == most){
                vals.erase(vals.begin()+j);
            }
        }
        if(vals.size() == 1){
            return vals[0];
        }
    }
    return vals[0];
}

string invert(string s){
    string ret = "";
    for(char c : s){
        if(c == '1'){
            ret = ret + "0";
        }
        else{
            ret = ret + "1";
        }
    }
    return ret;
}

int main(int argc, char const *argv[]){

    fstream file;
    file.open("input", ios::in);

    vector<string> vals;

    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    else{
        while(!file.eof()){
            string f;
            file>>f;
            if(f.size() > 0){
                vals.push_back(f);
            }
        }
        string oxy = oxygen(vals);
        string c0 = co2(vals);
        
        cout<<oxy<<" "<<c0<<endl;
    }
    file.close();
    return 0;
}

//Part 1 values
//1916 2179

//Part 2 values
//2043 1100