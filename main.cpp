#include "funk.h"

int main()
{
    int n;
    vector<Student> student;

    srand(time(NULL));

    bool ifFileUsed;
    cout << "Ar duomenys bus gaunami is failo ar vedami ranka?  Jei is failo, iveskite 1, jei ne - 0" << endl;
    cin >> ifFileUsed;
    cout << "Duomeyns gaunami is failo bus spausdinami faile rezultatai.txt" << endl;

    if(ifFileUsed == 0)
    {
        cout << "Iveskite kiek pazymiu tures kiekvienas mokinys" << endl;
        cin >> n;
        bool ifRandom;
        cout << "Ar ivesite pazymius patys, ar sugeneruoti juos? Jei taip, iveskite 1, jei ne - 0" << endl;
        cin >> ifRandom;
        int whichCycle = 0;
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
    }
    else
    {
        try
        {
            addDataFromFile(student, n);   
        }
        catch(const char* msg)
        {
            std::cerr << msg << endl;
            return 1;
        }
    }
    print(student, n, ifFileUsed);  
    return 0;
}