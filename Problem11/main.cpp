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

vector<vector<int>> board;
int flashes = 0;

void printVect(){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

void flash(int i, int j){
    flashes++;
    board[i][j] = 0;
    if(i == 0){
        if(j == 0){
            //Top Left Corner
            //Down
            board[i + 1][j]++;
            if(board[i + 1][j] > 9){
                flash(i+1, j);
            }
            //Right
            board[i][j+1]++;
            if(board[i][j+1] > 9){
                flash(i, j+1);
            }
            //Down Right
            board[i+1][j+1]++;
            if(board[i+1][j+1] > 9){
                flash(i+1, j-1);
            }
        }
        else if(j == board[i].size()){
            //Top Right Corner
            //Down
            board[i + 1][j]++;
            if(board[i + 1][j] > 9){
                flash(i+1, j);
            }
            //Left
            board[i][j-1]++;
            if(board[i][j-1] > 9){
                flash(i, j - 1);
            }
            //Down Left
            board[i+1][j-1]++;
            if(board[i+1][j-1] > 9){
                flash(i+1, j-1);
            }
        }
        else{
            //Just the top
            //Left
            board[i][j-1]++;
            if(board[i][j-1] > 9){
                flash(i, j - 1);
            }
            //Right
            board[i][j+1]++;
            if(board[i][j+1] > 9){
                flash(i, j+1);
            }
            //Down
            board[i + 1][j]++;
            if(board[i + 1][j] > 9){
                flash(i+1, j);
            }
            //Down Right
            board[i+1][j+1]++;
            if(board[i+1][j+1] > 9){
                flash(i+1, j-1);
            }
            //Down Left
            board[i+1][j-1]++;
            if(board[i+1][j-1] > 9){
                flash(i+1, j-1);
            }

        }
    }
    else if(i == board.size() - 1){
        if(j == 0){
            //Bottom Left
            //Up
            board[i - 1][j]++;
            if(board[i - 1][j] > 9){
                flash(i-1, j);
            }
            //Right
            board[i][j+1]++;
            if(board[i][j+1] > 9){
                flash(i, j+1);
            }
            //Up Right
            board[i-1][j+1]++;
            if(board[i-1][j+1] > 9){
                flash(i-1, j+1);
            }

        }
        else if(j == board[i].size()){
            //Bottom Right
            //Left
            board[i][j-1]++;
            if(board[i][j-1] > 9){
                flash(i, j - 1);
            }
            //Up
            board[i - 1][j]++;
            if(board[i - 1][j] > 9){
                flash(i-1, j);
            }
            //Up Left
            board[i-1][j-1]++;
            if(board[i-1][j-1] > 9){
                flash(i-1, j-1);
            }
        }
        else{
            //Bottom
            //Left
            board[i][j-1]++;
            if(board[i][j-1] > 9){
                flash(i, j - 1);
            }
            //Right
            board[i][j+1]++;
            if(board[i][j+1] > 9){
                flash(i, j+1);
            }
            //Up
            board[i - 1][j]++;
            if(board[i - 1][j] > 9){
                flash(i-1, j);
            }
            //Up Right
            board[i-1][j+1]++;
            if(board[i-1][j+1] > 9){
                flash(i-1, j+1);
            }
            //Up Left
            board[i-1][j-1]++;
            if(board[i-1][j-1] > 9){
                flash(i-1, j-1);
            }
            
        }
    }
    else{
        if(j == 0){
            //Left Side
            //Up
            board[i - 1][j]++;
            if(board[i - 1][j] > 9){
                flash(i-1, j);
            }
            //Down
            board[i + 1][j]++;
            if(board[i + 1][j] > 9){
                flash(i+1, j);
            }
            //Right
            board[i][j+1]++;
            if(board[i][j+1] > 9){
                flash(i, j+1);
            }
            //Up Right
            board[i-1][j+1]++;
            if(board[i-1][j+1] > 9){
                flash(i-1, j+1);
            }
            //Down Right
            board[i+1][j+1]++;
            if(board[i+1][j+1] > 9){
                flash(i+1, j-1);
            }
        }
        else if(j == board[i].size()){
            //Right Side
            //Up
            board[i - 1][j]++;
            if(board[i - 1][j] > 9){
                flash(i-1, j);
            }
            //Down
            board[i + 1][j]++;
            if(board[i + 1][j] > 9){
                flash(i+1, j);
            }
            //Left
            board[i][j-1]++;
            if(board[i][j-1] > 9){
                flash(i, j - 1);
            }
            //Up Left
            board[i-1][j-1]++;
            if(board[i-1][j-1] > 9){
                flash(i-1, j-1);
            }
            //Down Left
            board[i+1][j-1]++;
            if(board[i+1][j-1] > 9){
                flash(i+1, j-1);
            }
        }
        else{
            //Up
            board[i - 1][j]++;
            if(board[i - 1][j] > 9){
                flash(i-1, j);
            }
            //Down
            board[i + 1][j]++;
            if(board[i + 1][j] > 9){
                flash(i+1, j);
            }
            //Left
            board[i][j-1]++;
            if(board[i][j-1] > 9){
                flash(i, j - 1);
            }
            //Right
            board[i][j+1]++;
            if(board[i][j+1] > 9){
                flash(i, j+1);
            }





            //Up Left
            board[i-1][j-1]++;
            if(board[i-1][j-1] > 9){
                flash(i-1, j-1);
            }
            //Up Right
            board[i-1][j+1]++;
            if(board[i-1][j+1] > 9){
                flash(i-1, j+1);
            }
            //Down Left
            board[i+1][j-1]++;
            if(board[i+1][j-1] > 9){
                flash(i+1, j-1);
            }
            //Down Right
            board[i+1][j+1]++;
            if(board[i+1][j+1] > 9){
                flash(i+1, j-1);
            }
        }
    }
}

void part1(){
    for(int steps = 0; steps < 10; steps++){
        //First need to loop through and add one to each value
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                board[i][j]++;
            }
        }
        //printVect();
        //Next need to update everything that flashes, and if it does
        //Check if values around them need to be updated
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] > 9){
                    flash(i, j);
                }
            }
        }
    }
    cout<<flashes<<endl;
    cout<<"Part 1 done"<<endl;
}

void part2(){


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
        string s;
        file>>s;
        vector<int> temp;
        for(char c : s){
            int t = c - '0';
            temp.push_back(t);
        }
        board.push_back(temp);
    }
    //printVect();
    part1();
    part2();

    return 0;
}
