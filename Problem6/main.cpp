#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <assert.h>

using namespace std;

int main(int argc, char const *argv[])
{
    fstream file;
    file.open("input", ios::in);
    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    while(!file.eof()){
    }
    return 0;
}
