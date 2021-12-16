#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <assert.h>

using namespace std;

struct Tuple{
    int first;
    int second;
};

struct Board{

    vector<vector<int>> numbers{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    vector<vector<bool>> marked{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    bool mark = false;

    void printMarked(){
        for(int row = 0; row < 5; row++){
            for(int col = 0; col < 5; col++){
                cout<<marked[row][col]<<" ";
            }
            cout<<endl;
        }
    }

    void addNum(int n, int row, int col){
        numbers[row][col] = n;
    }

    void markNum(int called){
        for(int row = 0; row < 5; row++){
            for(int col = 0; col < 5; col++){
                if(numbers[row][col] == called){
                    marked[row][col] = 1;
                    return;
                }
            }
        }
    }

    bool hasWon(){
        //First lets check each col
        for(int row = 0; row < 5; row++){
            bool com = 1;
            for(int col = 0; col < 5; col++){
                if(!marked[row][col]){
                    //0, col not complete
                    com = 0;
                    break;
                }
            }
            if(com){
                //col complete
                return 1;
            }
        }

        //Each row

        for(int row = 0; row < 5; row++){
            bool com = 1;
            for(int col = 0; col < 5; col++){
                if(!marked[col][row]){
                    //0, row not complete
                    com = 0;
                    break;
                }
            }
            if(com){
                //row complete
                return 1;
            }
        }

        return 0;
    }

    int sum(vector<int> nums){
        int total = 0;
        for(int row = 0; row < 5; row++){
            for(int col = 0; col < 5; col++){
                if(marked[row][col] == 0){
                    total += numbers[row][col];
                }  
            }
        }
        return total;
    }
};

vector<int> parseNumbers(string in){
    vector<int> ret;
    const char delim = ',';
    stringstream ss(in);
    string s;
    while(getline(ss, s, delim)){
        if(s.length() > 0) ret.push_back(stoi(s));
    }
    return ret;
}

Tuple findWinners(vector<int> nums, vector<Board> &boards){

    Tuple tuple;
    tuple.first = -1;
    tuple.second = -1;
    int j = 0;
    for(int called : nums){
        for(int i = 0; i < boards.size(); i++){
            boards[i].markNum(called);
            if(boards[i].hasWon()){
                tuple.first = j;
                tuple.second = i;
                return tuple;
            }
        }
        j++;
    }

    return tuple;
}

Tuple findLosers(vector<int> nums, vector<Board> &boards){

    Tuple tuple;
    tuple.first = -1;
    tuple.second = -1;
    int numWinners = 0;
    int j = 0;
    for(int called : nums){
        for(int i = 0; i < boards.size(); i++){
            if(!boards[i].mark){
                boards[i].markNum(called);
                if(boards[i].hasWon()){
                    boards[i].mark = true;
                    numWinners++;
                    if(numWinners == boards.size()){
                        tuple.second = i;
                        tuple.first = j;
                        return tuple;
                    }
                }
            }
        }
        j++;
    }

    return tuple;
}

int main(int argc, char const *argv[])
{
    fstream file;
    file.open("input", ios::in);
    vector<Board> boards;
    vector<int> nums;

    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
        string numbers;
    file>>numbers;
    nums = parseNumbers(numbers);
    while(!file.eof()){
        Board b;
        for(int row = 0; row < 5; row++){
            for(int col = 0; col < 5; col++){
                string f;
                file >> f;
                int n;
                if(f.length() > 0) n = stoi(f);
                b.addNum(n, row, col);
            }
        }
        boards.push_back(b);         
    }
    //Now have all the boards stored, as well as input
    //Need to determine which one wins first

    Tuple tuple = findLosers(nums, boards);

    assert(tuple.first > 0);
    assert(tuple.second >  0);

    //Now have the winning number in tuple.first, 
    //and winning board in tuple.second


    int t = boards[tuple.second].sum(nums);

    

    cout<<nums[tuple.first]<<" "<<tuple.second<<endl;

    cout<<t*nums[tuple.first]<<endl;

    file.close();
    return 0;
}
