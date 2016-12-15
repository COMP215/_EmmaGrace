#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<tuple<float,float>> MakeSkyline(const vector<tuple<float,float,float>>, short);

int main() {
    vector<tuple<float,float,float>> buildings = {make_tuple(2.25,5,5), make_tuple(4,3,9), make_tuple(6,1,8), make_tuple(10,7,12),
        make_tuple(10,1.5,12), make_tuple(13,3,15.5), make_tuple(15,4,19)};    
    vector<tuple<float,float>> skyline;
    
    skyline = MakeSkyline(buildings, 7);
    
    for (short i = 0; i < skyline.size(); i++) {
        cout << "(" << get<0>(skyline[i]) << ", " << get<1>(skyline[i]) << ") ";
    }
    cout << endl;
    
    return 0;
}

vector<tuple<float,float>> MakeSkyline(const vector<tuple<float,float,float>> buildings, short size) {
    vector<tuple<float,float>> skyline;
        
    if (size > 1) {
        vector<tuple<float,float,float>> left_buildings, right_buildings;   
        short i;
        short flr = floor(size/2.0);
        short cl = ceil(size/2.0);
        
        for (i = 0; i < flr; i++) {            
            left_buildings.push_back(buildings[i]);
        }
        for (i = flr; i < size; i++) {
            right_buildings.push_back(buildings[i]);
        }
        vector<tuple<float,float>> left_skyline = MakeSkyline(left_buildings, flr);
        vector<tuple<float,float>> right_skyline = MakeSkyline(right_buildings, cl);
        
        short left_index = 0;
        short right_index = 0;
        float left_height = 0;
        float right_height = 0;
        tuple<float,float> temp;
        
        while (left_index < left_skyline.size() && right_index < right_skyline.size()) {
            if (get<0>(left_skyline[left_index]) < get<0>(right_skyline[right_index])) {
                left_height = get<1>(left_skyline[left_index]);
                temp = make_tuple(get<0>(left_skyline[left_index]), max(left_height, right_height));
                left_index++;
            } else {
                right_height = get<1>(right_skyline[right_index]);
                temp = make_tuple(get<0>(right_skyline[right_index]), max(left_height, right_height));
                right_index++;
            }
            
            if (skyline.size() == 0 || get<1>(temp) != get<1>(skyline.back())) {
                skyline.push_back(temp);
            }
        }
        
        while (left_index < left_skyline.size()) {
            if (get<1>(left_skyline[left_index]) != get<1>(skyline.back())) {
                skyline.push_back(left_skyline[left_index]);
            }
            left_index++;
        }
        while (right_index < right_skyline.size()) {
            if (get<1>(right_skyline[right_index]) != get<1>(skyline.back())) {
                skyline.push_back(right_skyline[right_index]);
            }
            right_index++;
        }
        
        return skyline;
    } else {
        skyline.push_back(make_tuple(get<0>(buildings[0]), get<1>(buildings[0])));
        skyline.push_back(make_tuple(get<2>(buildings[0]), 0));
        
        return skyline;
    }
}

