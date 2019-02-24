#include "funk.h"

int generateRandom()
{
    int random;
    random = 9 * rand()/RAND_MAX + 1;
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

void addDataFromFile(vector<Student> &student, int &n)
{
    std::ifstream fd("kursiokai.txt");
    if(!fd)
    {
        throw "Nera duomenu failo!";
    }
    string temp;
    std::getline(fd, temp);
    n = (temp.size() - 44) / 5;
    int k = 0;
    int tempMark;
    while(fd.peek() != EOF)
    {
        student.push_back(Student());
        fd >> student[k].name >> student[k].surname;
        for(int i = 0; i != n; i++)
        {
            fd >> tempMark;
            student[k].hw.push_back(tempMark);
        }
        fd >> student[k].exam;
        student[k].vid = vidCalc(student[k].hw, student[k].exam, n);
        student[k].med = medCalc(student[k].hw, student[k].exam, n);
        k++;
    }
}

void print(vector<Student> &student, int n, bool ifFileUsed)
{
    int k = student.size(); 
    if(ifFileUsed == false)
    {
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
    else
    {
        std::ofstream result("rezultatai.txt");
        result << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
        for(int i =0; i != 72; i++)
        {
            result << "-";
        }
        result << endl;
        int vid, med;
        for(int i = 0; i != k; i++)
        {
            result << left << setw(15) << student[i].name << left << setw(20) << student[i].surname;
            result << left << setw(19) << fixed << setprecision(2) << student[i].vid;
            result << left << setw(16) << fixed << setprecision(2) << student[i].med << endl;
        }
    }
}
