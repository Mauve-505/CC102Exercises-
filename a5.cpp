#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream inFile("original.txt");
    vector<string> lines;
    string line;

    while (getline(inFile, line)) {
        if (!line.empty()) lines.push_back(line);
    }
    inFile.close();

    sort(lines.begin(), lines.end());

    ofstream outFile("sorted.txt");
    for (const auto& l : lines) {
        outFile << l << "\n";
    }
    outFile.close();

    cout << "Sorted successfully!\n";
    return 0;
}