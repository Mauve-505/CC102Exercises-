#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream write;
    ifstream read;
    ofstream copy;

    write.open("color.txt");
    if(write.is_open()){
        write <<"red\n";
        write <<"skyblue\n";
        write <<"ivory\n";
        write <<"Tyrian Purple\n";
        write <<"Green\n";
        write.close();
        cout<<"Color Written Successfully";
    } else {
        cout<<"Failed to create color.txt";
        return 1;
    }

    read.open("color.txt");
    if(!read.is_open()){
        cout<<"Failed to open color.txt";
        return 1;
    }
    copy.open("color_copy.txt");
    if(!copy.is_open()){
        cout<<"Failed to open copy of color\n";
        return 1;
    }

    string line;

    while(getline(read, line)) {
        copy<< line << endl;
    }
    read.close();
    copy.close();

    cout<<"Sucessfully Copied color to color_copy.txt";

    return 0;
}