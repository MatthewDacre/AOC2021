#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

vector<vector<int>> map;

void print2dVec(){
    for(int row = 0; row < map.size(); row++){
        for(int col = 0; col < map[row].size(); col++){
            cout<<map[row][col]<<" ";
        }
        cout<<endl;
    }
}

void part1(){
    int sum = 0;
    for(int row = 0; row < map.size(); row++){
        for(int col = 0; col < map[row].size(); col++){
            int val = map[row][col];
            if(row == 0){
                if(col == 0){
                    //Top Left
                    //Right
                    if(map[row][col + 1] < val){
                        continue;
                    }
                    //Down
                    if(map[row+1][col] < val){
                        continue;
                    }
                }
                else if(col == map[row].size() - 1){
                    //Top Right
                    //Left
                    if(map[row][col - 1] < val){
                        continue;
                    }
                    //Down
                    if(map[row+1][col] < val){
                        continue;
                    }
                }
                else{
                    //Top
                    //Left
                    if(map[row][col - 1] < val){
                        continue;
                    }
                    //Right
                    if(map[row][col + 1] < val){
                        continue;
                    }
                    //Down
                    if(map[row + 1][col] < val){
                        continue;
                    }
                }
            }
            else if(row == map.size() - 1){
                if(col == 0){
                    //Bottom Left
                    //Right
                    if(map[row][col + 1] < val){
                        continue;
                    }
                    //Up
                    if(map[row - 1][col] < val){
                        continue;
                    }
                }
                else if(col == map[row].size() - 1){
                    //Bottom Right
                    //Left
                    if(map[row][col - 1] < val){
                        continue;
                    }
                    //Up
                    if(map[row - 1][col] < val){
                        continue;
                    }
                }
                else{
                    //Bottom
                    //Left
                    if(map[row][col - 1] < val){
                        continue;
                    }
                    //Right
                    if(map[row][col + 1] < val){
                        continue;
                    }
                    //Up
                    if(map[row - 1][col] < val){
                        continue;
                    }
                }
            }
            else{
                if(col == 0){
                    //Left
                    //Right
                    if(map[row][col + 1] < val){
                        continue;
                    }
                    //Up
                    if(map[row - 1][col] < val){
                        continue;
                    }
                    //Down
                    if(map[row + 1][col] < val){
                        continue;
                    }
                }
                else if(col == map[row].size() - 1){
                    //Right
                    //Left
                    if(map[row][col - 1] < val){
                        continue;
                    }
                    //Up
                    if(map[row - 1][col] < val){
                        continue;
                    }
                    //Down
                    if(map[row + 1][col] < val){
                        continue;
                    }
                }
                else{
                    //Nothing
                    //Left
                    if(map[row][col - 1] < val){
                        continue;
                    }
                    //Right
                    if(map[row][col + 1] < val){
                        continue;
                    }
                    //Up
                    if(map[row - 1][col] < val){
                        continue;
                    }
                    //Down
                    if(map[row + 1][col] < val){
                        continue;
                    }
                }
            }
            sum+= val + 1;
        }
    }
    cout<<sum<<endl;
}

int main(int argc, char const *argv[])
{
    
    fstream file;
    file.open("sample", ios::in);

    

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
    
    //print2dVec();
    part1();


    return 0;
}
