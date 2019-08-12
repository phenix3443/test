#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <vector>

using namespace std;

int TestStream () {
    ofstream outFile ("hello.txt", ofstream::out);
    if (outFile) {
        for (int i = 0; i < 100; ++i) {
            outFile << "This is Line " << i << endl;
        }
        outFile.close ();
    }

    ifstream inFile ("hello.txt", ifstream::in);
    if (inFile) {
        string line;
        while (getline (inFile, line)) {
            cout << line << endl;
        }
        inFile.close ();
    }

    return 0;
}
