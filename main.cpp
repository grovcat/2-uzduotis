#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>


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

struct Student
{
    string name;
    string surname;
    vector<int> hw;
    int exam;
    double vid, med;
};

int generateRandom()
{
    int random;
    random = 9 * rand()/RAND_MAX + 1;
}

void addData(vector<Student> &student, int n, bool ifRandom)
{
    student.push_back(Student());
    int k = student.size() - 1;
    cout << "Iveskite mokinio varda" << endl;
    cin >> student[k].name;
    cout << "Iveskite mokinio pavarde" << endl;
    cin >> student[k].surname;
    int temp;
    if(ifRandom == true)
    {
        for(int i = 0; i != n; i++)
        {
            cout << "Generuojamas " << i+1 << " pazymys = ";
            temp = generateRandom();
            student[k].hw.push_back(temp);
            cout << temp << endl;
        }
        cout << "Generuojamas egzamino pazymys = ";
        student[k].exam = generateRandom();
        cout << student[k].exam << endl;
    }
    else
    {       
        for(int i = 0; i != n; i++)
        {
            cout << "Iveskite " << i+1 << " pazymi" << endl;
            cin >> temp;
            student[k].hw.push_back(temp);
        }
        cout << "Iveskite egzamino pazymi" << endl;
        cin >> student[k].exam;
    }
}

double vidCalc(vector<int> hw, int exam, int n)
{
    int temp = 0;
    for(int i = 0; i != n; i++)
    {
        temp += hw[i];
    }
    return 0.4 * (double)(temp / n) + 0.6 * exam;
}

double medCalc(vector<int> hw, int exam, int n)
{
    sort(hw.begin(), hw.end());
    if(n % 2 == 1)
    {
        return 0.4 * (double)hw[n / 2] + 0.6 * exam;
    }
    else
    {
        return 0.4 * (double)((hw[n / 2 - 1] + hw[n / 2]) / 2) + 0.6 * exam;
    }
}

void print(vector<Student> &student, int n) 
{
    int k = student.size();   
    cout << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    for(int i =0; i != 72; i++)
    {
        cout << "-";
    }
    cout << endl;
    int vid, med;
    for(int i = 0; i != k; i++)
    {
        cout << left << setw(15) << student[i].name << left << setw(20) << student[i].surname;
        cout << left << setw(19) << fixed << setprecision(2) << student[i].vid;
        cout << left << setw(16) << fixed << setprecision(2) << student[i].med << endl;
    }
}

int main()
{
    vector<Student> student;

    srand(time(NULL));

    int n, whichCycle = 0;
    bool ifRandom;
    cout << "Iveskite keik pazymiu tures kiekvienas mokinys" << endl;
    cin >> n;
    cout << "Ar ivesite pazymius patys, ar sugeneruoti juos? Jei taip, iveskite 1, jei ne - 0" << endl;
    cin >> ifRandom;
    bool cycle = 1;
    while(cycle != 0)
    {
        addData(student, n, ifRandom);
        student[whichCycle].vid = vidCalc(student[whichCycle].hw, student[whichCycle].exam, n);
        student[whichCycle].med = medCalc(student[whichCycle].hw, student[whichCycle].exam, n);
        cout << "Jeigu norite susdabdyti vedima, iveskite 0" << endl;
        cout << "Jeigu norite vesti daugiau duomenu, iveskite 1" << endl;
        cin >> cycle;
        whichCycle++;
    }
    print(student, n);
    return 0;
}