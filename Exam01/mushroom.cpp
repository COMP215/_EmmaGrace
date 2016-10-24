#include "mushroom.h"

void Satchel::PackSatchel(vector<Mushroom> mushrooms) {
    space = capacity_;
    short i = 0;
    while (space != 0 && i < mushrooms.size()) {
        if (mushrooms[i].quantity_ >= space) {
            cout << space << " ounces of " << mushrooms[i].common_name_
            << " (" << mushrooms[i].scientific_name_ << ") mushrooms" << endl;
            space = 0;
        } else {
            cout << mushrooms[i].quantity_ << " ounces of " << mushrooms[i].common_name_
            << " (" << mushrooms[i].scientific_name_ << ") mushrooms" << endl;
            space -= mushrooms[i].quantity_;
        }
        i++;
    }
}
