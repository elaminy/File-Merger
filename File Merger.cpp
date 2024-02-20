#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// This program merges two sorted input files into a single output file, maintaining sort order.
// Inputs: Two sorted text files
// Process: Reads lines from both files, compares them, and writes the smallest (in alphabetical order) to the output file.
// Output: A single file containing all lines from both input files in sorted order.

int main() {
    ifstream file1("file1.txt"), file2("file2.txt");
    ofstream outputFile("outputFile.txt");
    string str1, str2;

    // Initial read from both files
    getline(file1, str1);
    getline(file2, str2);

    while (!file1.eof() && !file2.eof()) {
        if (str1 < str2) {
            outputFile << str1 << endl;
            getline(file1, str1);
        }
        else {
            outputFile << str2 << endl;
            getline(file2, str2);
        }
    }

    // Process remaining lines in file1
    while (!file1.eof()) {
        outputFile << str1 << endl;
        getline(file1, str1);
    }

    // Process remaining lines in file2
    while (!file2.eof()) {
        outputFile << str2 << endl;
        getline(file2, str2);
    }

    // Close all files
    file1.close();
    file2.close();
    outputFile.close();

    return 0;
}
