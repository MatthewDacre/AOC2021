#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;



int main(int argc, char const *argv[])
{
    
    fstream file;
    file.open("input", ios::in);

    vector<vector<int>> map;

    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    while(!file.eof()){
        string numbers;
        file>>numbers;
        if(numbers.length() > 0){
            vector<int> temp;
            for(char c : numbers){
                temp.push_back(atoi(&c));
            }
            map.push_back(temp);
        }
    }

    //cout<<parse(map)<<endl;

    

    return 0;
}
