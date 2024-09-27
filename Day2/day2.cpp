#include<iostream>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class diceCalculation{
private: 
    vector<string> stringVector;

public: 
    void readFile(const string &filename) {
        ifstream file(filename);
        string line;

        if (!file) {
            cout << "File failed to open." << endl;
        } else {
            cout << "File successfully opened." << endl;
            while (file >> line) {  //need to read the line not individual word 
                stringVector.push_back(line);
            }
            file.close();
        }
    }

    void printVector() {
        for (int i = 0; i < stringVector.size(); i++) {
            cout << stringVector[i] << endl;
        }
    }

};




int main()
{
    diceCalculation myObj; 
    myObj.readFile("sampleinput.txt");
    myObj.printVector(); 
    return 0;
}