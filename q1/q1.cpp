#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class Solution{
public: 
    int n; 
    vector<int> firstLineParams;
    vector<string> testCases;
    vector<string> ans;

    Solution(string fileName){ 
        readFile(fileName);
        parseTestCase();
        writeFile();
    }

    void readFile(string fileName){
        ifstream inFile;
        inFile.open(fileName);
        if(!inFile.is_open()) return;

        string line, holdInt;
        getline(inFile, line);
        istringstream ss(line);
        while(ss >> holdInt) firstLineParams.push_back(stoi(holdInt));
        int n = firstLineParams[0];

        for(int i = 0; i < n; i++){
            string newLine;
            getline(inFile, newLine);
            testCases.push_back(newLine);
        }
        inFile.close();
    }
    
    void parseTestCase(){
        vector<string> testParams;
        for(string test : testCases){
            string currentTestCase;
            istringstream ss(test);
            while(ss >> currentTestCase) testParams.push_back(currentTestCase);
            int a = stoi(testParams[0]);
            string b = testParams[1];
            string c = testParams[2];
            string d = testParams[3];
            solveQuestion(a, b, c, d);
            testParams.clear();
        }
    }

    void solveQuestion(int a, const string& b, const string& c, const string& d){
        ans.push_back(string(b + c + d));
    }

    void writeFile(){
        ofstream outFile;
        outFile.open("output.txt");
        if(outFile.is_open()){
            for(auto a : ans) outFile << a << endl;
            outFile.close();
        }
    }
};

int main(){
    Solution answer(string("test_case.in"));
}