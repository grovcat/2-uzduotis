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
#include <deque>

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
using std::deque;

struct Student
{
    string name;
    string surname;
    deque<int> hw;
    int exam;
    double vid, med;
};

int generateRandom();
double vidCalc(deque<int>, int, int);
double medCalc(deque<int>, int, int);
void addData(deque<Student>&, int, bool);
void addDataFromFile(deque<Student>&, deque<Student>&,  int&);
void print(deque<Student>&,deque<Student>&, int, bool);
bool checkIfFileExists();
void generateFile();

#endif 