#include <iostream>
#include <fstream>

using namespace std;

//
//  main.cpp
//  classbst
//
//  Created by Tom Armstrong on 9/19/16. Modified by Emma Steffens on 9/20/16.
//  Copyright © 2016 tarmstro and emmagrace. All rights reserved.
//

#include <iostream>
#include "binarysearchtree.h"
#include "linkedlist.h"


int main(){

    /*
    BinarySearchTree* people_names = new BinarySearchTree();
    people_names->Insert("gousie");
    people_names->Insert("patel");
    people_names->Insert("bloch");
    people_names->Insert("ratliff");
    people_names->Insert("leibowitz");
    people_names->Insert("gagne");
    people_names->Insert("armstrong");
    people_names->Insert("sklensky");
    people_names->Insert("leblanc");
    people_names->Insert("decoste");
    people_names->Insert("kahn");

    people_names->InOrder();

    string name1, name2;
    name1 = "kahn";
    name2 = "case";

    if (people_names->Search(name1)) {
        cout << endl << name1 << " found!" << endl;
    } else {
        cout << endl << name1 << " not found :(" << endl;
    }
    if (people_names->Search(name2)) {
        cout << name2 << " found!" << endl;
    } else {
        cout << name2 << " not found :(" << endl << endl;
    }

    LinkedList* math_courses = new LinkedList();
    math_courses->Insert("calculus 1");
    math_courses->Insert("discrete");
    math_courses->Insert("calculus 2");
    math_courses->Insert("linear algebra");

    math_courses->Unnamed();

    string course1, course2;
    course1 = "abstract algebra";
    course2 = "calculus 2";

    if (math_courses->Search(course1)) {
        cout << endl << course1 << " found!" << endl;
    } else {
        cout << endl << course1 << " not found :(" << endl;
    }
    if (math_courses->Search(course2)) {
        cout << course2 << " found!" << endl;
    } else {
        cout << course2 << " not found :(" << endl;
    }
    */

    ifstream fin;
    string a_word;
    BinarySearchTree* words = new BinarySearchTree;

    fin.open("foowords.txt");

    while (!fin.eof()) {
        getline(fin, a_word);
        words->Insert(a_word);
    }

    fin.close();
    fin.open("words.txt");

    long i = 0;
    while (!fin.eof()) {
        getline(fin, a_word);
        i++;
        if (!words->Search(a_word)) {
            cout << "Oh no! " << a_word << " not found!" << endl;
        }
    }
    cout << i << " words checked. Search complete." << endl;

    return 0;
}
