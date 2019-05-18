#ifndef FUNK_H 
#define FUNK_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <chrono>
#include <list>

using std::cout;
using std::cin;
using std::left;
using std::setw;
using std::setfill;
using std::string;
using std::endl;
using std::sort;
using std::setprecision;
using std::fixed;
using std::vector;
using std::string;
using namespace std::chrono;
using std::list;

struct Student
{
    string name;
    string surname;
    list<int> hw;
    int exam;
    double vid, med;
};

bool compare(const Student&, const Student&);
int generateRandom();
double vidCalc(list<int>, int, int);
double medCalc(list<int>, int, int);
void addData(list<Student>&, list<Student>&, list<Student>&, int, bool);
void addDataFromFile(list<Student>&, list<Student>&, list<Student>&, int&);
void print(list<Student>&, list<Student>&, list<Student>&, int, bool);
bool checkIfFileExists();
void generateFile();

#endif 