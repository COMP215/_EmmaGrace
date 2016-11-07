#include <iostream>
#include <cmath>
using namespace std;

void SelectionSort(short* array, short array_size) {
    int min_index;

    for (short i = 1; i < array_size; i++) {
        min_index = i;
        for (short j = i; j < array_size; j++) {
            if (array[min_index] > array[j]) {
                min_index = j;
            }
        }
        swap(array[i], array[min_index]);
    }
}

void BubbleSort(short* array, short array_size) {
    bool swapped = true;

    while(swapped) {
        swapped = false;
        for (short i = 0; i < array_size; i++) {
            if (array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                swapped = true;
            }
        }
    }
}

void Merge(short* left, short left_size, short* right, short right_size, short* array) {    
    short i = 0;
    short j = 0;
    short k = 0;
    
    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            array[k] = left[i];
            k++;
            i++;
        } else {
            array[k] = right[j];
            k++;
            j++;
        }
    }
    
    while (i < left_size) {
        array[k] = left[i];
        k++;
        i++;
    }
    
    while (j < right_size) {
        array[k] = right[j];
        k++;
        j++;
    }
}

short* MergeSort(short* array, short array_size) {
    if (array_size > 1) {
        short left_size = ceil((float)array_size / 2);
        short right_size = floor((float)array_size / 2);
        short midpoint = left_size - 1;
        
        short left[left_size];
        short i;
        short j = 0;
        for (i = 0; i <= midpoint; i++) {
            left[j] = array[i];
            j++;
        }

        short right[right_size];
        j = 0;
        for (i = midpoint + 1; i < array_size; i++) {
            right[j] = array[i];
            j++;
        }
        
        short* temp_l = MergeSort(left, left_size);
        short* temp_r = MergeSort(right, right_size);
        
        Merge(temp_l, left_size, temp_r, right_size, array);
        return array;
        
    } else {
        return array;
    }
}

int main() {
    short array[] = {3, 42, 25, 72, 17, 80, 5};

    MergeSort(array, 7);

    for (short i = 0; i < 7; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
