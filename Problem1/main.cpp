#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct slider{
    string A;
    string B;
    string C;

    void shuffle(){
        A = B;
        B = C;
        C = "";
    }
    void print(){
        cout<<A<<" "<<B<<" "<<C<<endl;   
    }
    int sum(){
        return (stoi(A) + stoi(B) + stoi(C));
    }
};

bool parse(string curr, string prev){
    int n1 = stoi(curr);
    int n2 = stoi(prev);

    return n1 > n2;
}

int main(int argc, char const *argv[])
{
    fstream file;
    file.open("input", ios::in);

    int count = 0;
    slider curr, prev;

    if(!file){
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    else{
        file>>prev.A;
        file>>prev.B;
        curr.A = prev.B;
        file>>prev.C;
        curr.B = prev.C;
        while(!file.eof()){
            file >> curr.C;
            if(curr.C.length() > 0){
                cout<<prev.sum()<<" | "<<curr.sum()<<endl;
                if(prev.sum() < curr.sum()){
                    count++;
                }
                prev.A = curr.A;
                prev.B = curr.B;
                prev.C = curr.C;
                curr.A = curr.B;
                curr.B = curr.C;               
            }
        }
    }
    file.close();
    cout<<count<<endl;
    return 0;
}
