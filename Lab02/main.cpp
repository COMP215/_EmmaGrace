// I CHANGED THE NAMES OF THE VARIABLES AND NOW IT EITHER RUNS SUB 5 MIN OR STALLS OUT
// AAAAAAAAAARG

//------------------------------------
// HEADER JUNK

#include <iostream>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

const long kNumCycles = 3;  // number of data generation + sort cycles

// rand()%_____1 + _____2, where the blank specifies what quality is being generated
const long kLenGen1 = 100;
const long kLenGen2 = 2700;
const long kNumStrGen1 = 500;
const long kNumStrGen2 = 32300;

// modular functions
void SetupExperiment(long& max_len, long& num_str);
void GetData(long max_len, long num_str);
void SortData(long num_str);

void RunExperiment();  // three above packaged together and repeated kNumCycles times

//------------------------------------
// MAIN: AKA THE STAR OF THE SHOW

int main()
{
    steady_clock my_clock;  // clock object
    auto start = my_clock.now();  // starting point for measuring run time

    srand((unsigned)time(NULL));
    RunExperiment();

    auto finish = my_clock.now();  // ending point for run time
    auto wall_time = duration_cast<seconds>(finish - start);  // real world run time

    cout << "The program ran for " << wall_time.count() << " seconds." << endl; // not giving right number?

    return 0;
}

//------------------------------------
// FUNCTION DEFINITIONS

void SetupExperiment(long& max_len, long& num_str)
{
    // string max length and number for this experiment
    max_len = rand()%kLenGen1 + kLenGen2;
    cout << "Max length of strings = " << max_len << endl;
    num_str = rand()%kNumStrGen1 + kNumStrGen2;
    cout << "Number of strings = " << num_str << endl;
}

void GetData(long max_len, long num_str)
{
    long current_len;  // length of current string
    short letter_location;  // location in alphabet_list
    char letter;  // holds current generated letter
    ofstream infile;  // output pipe into file
    char alphabet_list[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',  // letter selection array
        'n','o','p','q','r','s','t','u','v','w','x','y','z'};

    infile.open("Alg1.txt");

    for (short i = 0; i < num_str; i++)
    {
        current_len = rand()%max_len + 1;

        for (short j = 0; j < current_len; j++)
        {
            letter_location = rand()%26;
            letter = alphabet_list[letter_location];
            infile << letter;
        }

        infile << "\n";
    }

    infile.close();
}

void SortData(long num_str)
{
    ifstream outfile;    // input pipe out of file
    string to_sort[num_str];    // array of strings from file

    outfile.open("Alg1.txt");
    for (long i = 0; i < num_str; i++)
        getline(outfile, to_sort[i]);
    outfile.close();

    sort(to_sort, to_sort + num_str);

    for (long j = 0; j < num_str; j++)
        cout << to_sort[j] << endl;
    cout << "------------------------------------------------" << endl << endl;
}

void RunExperiment()
{
    // these change each cycle
    long max_len,
    num_str;

    for (short i = 0; i < kNumCycles; i++)
    {
        SetupExperiment(max_len, num_str);
        GetData(max_len, num_str);
        SortData(num_str);
    }
}
