#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <assert.h>

using namespace std;

#define B_SIZE 1000

void printBoard(vector<vector<int>> &counts){
    for(int i = 0; i < B_SIZE; i++){
        for(int j = 0; j < B_SIZE; j++){
            cout<<counts[i][j]<<" ";
        }
        cout<<endl;
    }
}

int count(vector<vector<int>> &counts){
    int c = 0;

    for(int i = 0; i < B_SIZE; i++){
        for(int j = 0; j < B_SIZE; j++){
            if(counts[i][j] > 1){
                c++;
            }
        }
    }

    return c;
}

void place(string c1, string c2, vector<vector<int>> &counts){
    //Assuming counts has preallocated space
   stringstream coord1(c1);
   stringstream coord2(c2);
   string temp;
   getline(coord1, temp, ',');
   int x1 = stoi(temp);
   getline(coord1, temp, ',');
   int y1 = stoi(temp);
   getline(coord2, temp, ',');
   int x2 = stoi(temp);
   getline(coord2, temp, ',');
   int y2 = stoi(temp);

    if(x1 == x2){
        //Vertical
        if(y1 > y2){
            for(int i = 0; i <= y1-y2; i++){
                counts[y2+i][x1]++;
            }
        }
        else{
            for(int i = 0; i <= y2-y1; i++){
                counts[y1+i][x1]++;
            }
        }
    }
    else if(y1 == y2){
        //Horizontal
        if(x1 > x2){
            for(int i = 0; i <= x1-x2; i++){
                counts[y1][x2+i]++;
            }
        }
        else{
            for(int i = 0; i <= x2-x1; i++){
                counts[y1][x1+i]++;
            }
        }
    }
    else{
        //Diagonal
        //Steps will be the same for x and y, 45 deg diagonal
        int steps = abs(x1 - x2);
        if(x1 < x2){
            if(y1 < y2){
                //Big: x2, y2
                for(int i = 0; i <= steps; i++){
                    counts[y1+i][x1+i]++;
                }
            }
            else{
                //Big: x2, y1
                for(int i = 0; i <= steps; i++){
                    counts[y2+i][x1+i];
                }
            }
        }
        else{
            if(y1 < y2){
                //Big: x1, y2
                for(int i = 0; i <= steps; i++){
                    counts[y1+i][x2+i]++;
                }
            }
            else{
                //Big: x1, y1
                for(int i = 0; i <= steps; i++){
                    counts[y2+i][x2+i]++;
                }
            }
        }

    }

}

int main(int argc, char const *argv[])
{
    fstream file;
    file.open("input", ios::in);
    vector<vector<int>> counts(B_SIZE, vector<int>(B_SIZE));

    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    while(!file.eof()){
        string c1, tmp, c2;
        file>>c1>>tmp>>c2;
        stringstream s1(c1);
        stringstream s2(c2);
        place(c1, c2, counts);        
    }
    printBoard(counts);
    cout<<count(counts)<<endl;
    return 0;
}
