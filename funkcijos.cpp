#include "funk.h"

//Checks if the first name is lower than the second one. Used for sort
bool compare(const Student& x, const Student& y)
{
    return x.vid < y.vid;
}

//Checks if the data file "kursiokai.txt" exists for a failsafe
bool checkIfFileExists()
{
    std::ifstream fd("kursiokai.txt");
    if(!fd)
    {
        return 0; //If the file does not exist, returns a false bool value
    }
    else
    {
        return 1; //If the file exists, returns a true bool value
    }
}

//Basic function for generating a grade
int generateRandom()
{
    int random;
    return random = 9 * rand()/RAND_MAX + 1;
}

//Function responsible for generating the data file
void generateFile()
{
    std::ofstream fd("kursiokai.txt");

    int mokiniai;
    cout << "Kiek mokiniu reikia sugeneruoti?" << endl;
    cin >> mokiniai;
    while(mokiniai < 0) //Waits for the user to enter a valid value for the amount students
    {
        cout << "Iveskite teisinga reiksme!" << endl;
        cin >> mokiniai;
    }
    int n;
    cout << "Kiek pazymiu tures kiekvienas mokinys?" << endl;
    cin >> n;
    while(n < 0) // Waits for the user to enter a valid value for the amount of grades each student has
    {
        cout << "Iveskite teisinga reiksme!" << endl;
        cin >> n;
    }
    
    //Writes the first line of the data file
    fd << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde";
    for(int i = 0; i != n; i++)
    {
        fd << "ND" << left << setw(3) << i+1;
    }
    fd << "Egzaminas" << endl;

    //Generates the student ID's and their grades
    for(int i = 0; i != mokiniai; i++)
    {
        fd  << "Vardas" << left << setw(9) << i+1 << "Pavarde" << left << setw(13) << i+1;
        for(int k = 0; k != n; k++)
        {
            fd << left << setw(5) << generateRandom();
        }
        fd << generateRandom() << endl;
    }
    fd.close();

    //Responds with the completed function
    cout << "Failas sugeneruotas" << endl;
}

//Counts the average value of a student
double vidCalc(list<int> hw, int exam, int n)
{
    int temp = 0;
    for(auto & it : hw)
    {
        temp += it;
    }
    return 0.4 * (double)(temp / n) + 0.6 * exam;
}

//Counts the median value of a student
double medCalc(list<int> hw, int exam, int n)
{
    //sort(hw.begin(), hw.end());
    hw.sort();

    list<int>::iterator it = hw.begin();
	advance(it, std::distance(hw.begin(), hw.end()) / 2);

    if(n % 2 == 1)
    {
        return 0.4 * (double)(*it) + 0.6 * exam;
    }
    else
    {
        return 0.4 * (double)(((*it) + (*(++it))) / 2) + 0.6 * exam;
    }
}

//Adds data from the user via console
// void addData(list<Student> &student, int n, bool ifRandom)
// {
//     student.push_back(Student());
//     int k = student.size() - 1;
//     cout << "Iveskite mokinio varda" << endl;
//     cin >> student[k].name;
//     cout << "Iveskite mokinio pavarde" << endl;
//     cin >> student[k].surname;
//     int temp;

//     //Checks if RNG is used for creating marks
//     if(ifRandom == true)
//     {
//         //Goes through every mark
//         for(int i = 0; i != n; i++)
//         {
//             cout << "Generuojamas " << i+1 << " pazymys = ";
//             temp = generateRandom();
//             student[k].hw.push_back(temp);
//             cout << temp << endl;
//         }
//         cout << "Generuojamas egzamino pazymys = ";
//         student[k].exam = generateRandom();
//         cout << student[k].exam << endl;
//     }
//     else
//     {       
//         //Goes through every mark
//         for(int i = 0; i != n; i++)
//         {
//             cout << "Iveskite " << i+1 << " pazymi" << endl;
//             cin >> temp;
//             student[k].hw.push_back(temp);
//         }
//         cout << "Iveskite egzamino pazymi" << endl;
//         cin >> student[k].exam;
//     }
// }

//Function responsible for adding data from a file into the memory (struct)
void addDataFromFile(list<Student> &student, list<Student> &Bad, int &n)
{
    std::ifstream fd("kursiokai.txt");
    
    //Checks if the data file exists, if not, throws an exeption
    if(!fd)
    {
        throw "Nera duomenu failo!";
    }
    
    //Takes the first line of the file to count how many marks are there based on the amount of characters the marks take up
    string temp;
    std::getline(fd, temp);
    n = (temp.size() - 44) / 5;

    int k = 0;
    int tempMark;

    list<Student>::iterator it = student.end();
    list<Student>::iterator B = Bad.end();
    string tempname, tempsurname;
    int tempexam;
    //Runs a loop until it checks if it reached the end of the file
    while(fd.peek() != EOF)
    {
        student.push_back(Student());
        it--;
        fd >> tempname >> tempsurname;
        it->name = tempname;
        it->surname = tempsurname;
        for(int i = 0; i != n; i++)
        {
            fd >> tempMark;
            it->hw.push_back(tempMark);
        }
        fd >> tempexam;
        it->exam = tempexam;
        it->vid = vidCalc(it->hw, it->exam, n);
        it->med = medCalc(it->hw, it->exam, n);
        if(it->vid < 5)
        {
            Bad.push_back(Student());
            B--;
            B->name = it->name;
            B->surname = it->surname;
            B->vid = it->vid;
            B->med = it->med;
            B++;
            it = student.erase(it);
        }
        else
        {
            it++;
        }

    }
    cout << "xd";
}

//Function responsible for printing out the result
void print(list<Student> &student, list<Student> &Bad, int n, bool ifFileUsed)
{
    //Sorting the struct via first name
    //sort(student.begin(), student.end(), compareForSort);
    student.sort(compare);
    Bad.sort(compare);

    //The variable k holds the info for the number of students in the memory
    int k = student.size(); 

    //Checks if the used requested to use files for the program, if not console printing for the result is used
    // if(ifFileUsed == false)
    // {
    //     cout << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    //     for(int i = 0; i != 72; i++)
    //     {
    //         cout << "-";
    //     }
    //     cout << endl;

    //     for(int i = 0; i != k; i++)
    //     {
    //         cout << left << setw(15) << student[i].name << left << setw(20) << student[i].surname;
    //         cout << left << setw(19) << fixed << setprecision(2) << student[i].vid;
    //         cout << left << setw(16) << fixed << setprecision(2) << student[i].med << endl;
    //     }
    // }  
    // else
    // {
        //Creates 2 output files for 2 different groups of students
        std::ofstream resultGood("rezultatai-good.txt");
        std::ofstream resultBad("rezultatai-bad.txt");

        //Prints the first line
        resultGood << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
        resultBad << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
        
        //Prints the second line
        for(int i =0; i != 72; i++)
        {
            resultGood << "-";
            resultBad << "-";
        }
        
        resultGood << endl;
        resultBad << endl;
        
        for(auto & G : student)
        {
            resultGood << left << setw(15) << G.name << left << setw(20) << G.surname;
            resultGood << left << setw(19) << fixed << setprecision(2) << G.vid;
            resultGood << left << setw(16) << fixed << setprecision(2) << G.med << endl;
        }
        for(auto & B : Bad)
        {
            resultBad << left << setw(15) << B.name << left << setw(20) << B.surname;
            resultBad << left << setw(19) << fixed << setprecision(2) << B.vid;
            resultBad << left << setw(16) << fixed << setprecision(2) << B.med << endl;
        }
    //}

    //Prints out the completed function text
    cout << "Rezultatas isspausdinas" << endl;
}
