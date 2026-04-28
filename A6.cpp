#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for(int i = 3; i <= (int)sqrt(n); i+=2){
        if (n % i == 0) return false;
    }
    return true;
}

void countPrime(const string& filename, const string& output){
    ifstream file(filename);
    ofstream out(output);

    int count = 0, number;
    while (file >> number){
        if (isPrime(number)){
            out << number << "\n";
            count++;
        }
    }

    out << "Prime Count: " << count << "\n";

    file.close();
    out.close();
}

int main(){
    countPrime("NUMS.TXT", "RESULT.TXT");
    cout << "Done! Result written to RESULT.TXT\n";
    return 0;
}