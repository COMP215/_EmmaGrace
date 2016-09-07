// This ran for ~11 min

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

const short RUN_CYCLES = 1;    // number of data generation + sort cycles

// see setupExperiment() for use
const long LEN_CTRL1 = 500;
const long LEN_CTRL2 = 20000;
const long STR_CTRL1 = 647;
const long STR_CTRL2 = 2147483000;
// modular functions
void setupExperiment(long& max_len, long& num_str);
void getData(long max_len, long num_str);
void sortData(long num_str);

void runExperiment();    // three above packaged together and repeated RUN_CYCLES times

//------------------------------------
// MAIN: AKA THE STAR OF THE SHOW

int main()
{
    steady_clock timer;
    auto start = timer.now();

    srand((unsigned)time(NULL));
    runExperiment();

    auto finish = timer.now();
    auto wall_time = finish - start;

    cout << "The program ran for " << wall_time.count()/double(CLOCKS_PER_SEC/1000) << " seconds." << endl; // not giving right number?

    return 0;
}

//------------------------------------
// FUNCTION DEFINITIONS

void setupExperiment(long& max_len, long& num_str)
{
    // string max length and number for this experiment
    max_len = rand()%LEN_CTRL1 + LEN_CTRL2;
    cout << "Max length of strings = " << max_len << endl;
    num_str = rand()%STR_CTRL1 + LEN_CTRL2;
    cout << "Number of strings = " << num_str << endl;
}

void getData(long max_len, long num_str)
{
    long current_len;    // current string length
    short letter_loc;    // location in letter list
    char letter;        // holds current generated letter
    ofstream infile;    // output pipe into file
    char alphalist[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',    // letter selection array
        'n','o','p','q','r','s','t','u','v','w','x','y','z'};

    infile.open("Alg1.txt");

    for (short i = 0; i < num_str; i++)
    {
        current_len = rand()%max_len + 1;

        for (short j = 0; j < current_len; j++)
        {
            letter_loc = rand()%26;
            letter = alphalist[letter_loc];
            infile << letter;
        }

        infile << "\n";
    }

    infile.close();

    cout << "Sorting..." << endl;
}

void sortData(long num_str)
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

void runExperiment()
{
    // these change each cycle
    long max_len,
    num_str;

    for (short i = 0; i < RUN_CYCLES; i++)
    {
        setupExperiment(max_len, num_str);
        getData(max_len, num_str);
        sortData(num_str);
    }
}
