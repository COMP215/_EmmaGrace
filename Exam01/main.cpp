#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "mushroom.h"
using namespace std;

bool BestMushroom(Mushroom, Mushroom);

int main() {
    ifstream infile;
    string filename, line, temp;
    short capacity;
    vector<Mushroom> mushrooms;
    Satchel S;
    
    cout << "Enter filename: ";
    cin >> filename;
    cout << filename << endl;
    cout << "Enter satchel capacity: ";
    cin >> capacity;
    infile.open(filename.c_str());
    if (infile) {
        getline(infile, line);
        while (getline(infile, line)) {
            istringstream ss1(line);
            stringstream ss2;
            Mushroom M;
            getline(ss1, M.common_name_, ',');
            ss1 >> ws;
            getline(ss1, M.scientific_name_, ',');
            ss1 >> ws;
            getline(ss1, temp, ',');
            ss1 >> ws;
            ss2 << temp;
            ss2 >> M.quantity_;
            getline(ss1, temp, ',');
            ss1 >> ws;
            ss2 << temp;
            ss2 >> M.dollars_;
            M.dollar_per_oz_ = M.dollars_ / M.quantity_;
            mushrooms.push_back(M);    
        }
        infile.close();
        sort(mushrooms.begin(), mushrooms.end(), BestMushroom);
        S.capacity_ = capacity;
        S.PackSatchel(mushrooms);
        
    } else {
        cout << "File not found." << endl;
    }
    return 0;    
}

bool BestMushroom (Mushroom a, Mushroom b) {
    return (a.dollar_per_oz_ > b.dollar_per_oz_);
}
