#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class calculationParser {
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
            while (file >> line) {
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

    void parseVector() {
        for (int i = 0; i < stringVector.size(); i++) {
            string line = stringVector[i];
            string clippedString;

            for (int j = 0; j < line.length(); j++) {
                if (isdigit(line[j])) {
                    clippedString.push_back(line[j]);
                }
            }
            stringVector[i] = clippedString;
        }
    }

    void trimData() {
        for (int i = 0; i < stringVector.size(); i++) {
            string line = stringVector[i];
            string clippedString;
            int length = line.length();
            char first = line[0];

            if (length != 1) {
                clippedString.push_back(first);
                char last = line[length - 1];
                clippedString.push_back(last);
            } else {
                clippedString.push_back(first);
                clippedString.push_back(first);
            }
            stringVector[i] = clippedString;
        }
    }

    int calculateData() {
        int total = 0;

        for (int i = 0; i < stringVector.size(); i++) {
            int line = stoi(stringVector[i]);
            total = total + line; 
        }

        return total;
    }
};

int main() {
    calculationParser myObj;

    myObj.readFile("input.txt");

    myObj.parseVector();
    cout << "After parse: ";  
    myObj.printVector();
    cout << endl; 

    myObj.trimData();
    cout << "After Trim: "; 
    myObj.printVector(); 
    cout << endl; 

    int total = myObj.calculateData();

    cout << "Total: " << total << endl;

    return 0;
}