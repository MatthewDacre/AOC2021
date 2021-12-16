#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int horz = 0;
int depth = 0;
int aim = 0;

void parse(string ins, string size){
    int s = stoi(size);
    if(ins == "forward"){
        horz += s;
        depth += aim * s;
    }
    else if(ins == "down"){
        aim += s;
    }
    else if(ins == "up"){
        aim -= s;
    }
}

int main(int argc, char const *argv[])
{

    fstream file;
    file.open("input", ios::in);

    

    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    else{
        while(!file.eof()){
            string ins,size;
            file>>ins>>size;
            if(ins.size() > 0){
                parse(ins, size);
            }
        }
    }
    file.close();
    cout<<horz*depth<<endl;
    return 0;


    return 0;
}
