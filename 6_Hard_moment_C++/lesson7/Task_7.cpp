#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;


namespace Stud
{
    class FullName
    {
    public:
        FullName()
        {
            name = "No";
            surname = "Name";
            !patronymic;
        }
        FullName(string _name, string _surname, string _patronymic)
        {
            name = _name;
            surname = _surname;
            if (&_patronymic == nullptr && _patronymic == " ")
                !patronymic;
            else
                patronymic = _patronymic;
        }

        void print()
        {
            cout << name << " " << surname << " " << patronymic.value();
        }
        string getName() { return name; }
        string getSurname() { return surname; }
        optional<string> getPatron() { return patronymic; }

        void setName(string n) { name = n; }
        void setSurname(string sn) { surname = sn; }
        void setPatron(string pat) { patronymic = pat; }
    protected:
        string name;
        string surname;
        optional<string>patronymic;
    };

    class Student : public FullName
    {
    public:
        Student() : FullName() { averageScore = 0; }
        Student(string n, string sn, string pat, vector<int>& v) : FullName(n, sn, pat)
        {
            evaluations.resize(v.size());
            copy(v.begin(), v.end(), evaluations.begin());
            averageScore = calculateAS(v);
            FullName f;
        }

        double getAverageScore() { return averageScore; }
        void print()
        {
            cout << "ФИО: "; FullName::print();
            cout << endl << "Оценки: ";
            for (auto it : evaluations)
            {
                cout << it << " ";
            }
            cout << endl << "Средняя оценка: " << averageScore << endl;
        }

    protected:
        vector<int>evaluations;
        double averageScore;

        double calculateAS(const vector<int>& v)
        {
            int sum = 0;
            int count = 0;
            for (auto it : v)
            {
                sum += it;
                count++;
            }
            return (double)sum / count;
        }
    };


    class StudentsGroup : public Student
    {
    public:
        StudentsGroup() {}

        StudentsGroup(vector<Student> vs)
        {
            SG.resize(vs.size());
            copy(vs.begin(), vs.end(), SG.begin());
        }

        void pushStudent(Student stud)
        {
            SG.push_back(stud);
        }

        void print()
        {
            for (auto it : SG)
            {
                it.print();
            }
        }

    private:
        vector<Student> SG;
    };
}
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
class IRepository 
{
    virtual void Open() = 0;
    virtual void Save() = 0;
};

class IMethods 
{
    virtual double GetAverageScore(Stud::FullName& name) = 0;
    virtual string GetAllInfo(Stud::FullName& name) = 0;
    virtual string GetAllInfo() = 0;
};



class StudentsGroup : public Stud::Student, public IRepository, public IMethods
{
public:
    StudentsGroup() {}

    StudentsGroup(string str)
    {
        nameBinFile = str;
    }

    StudentsGroup(vector<Stud::Student> vs, string nameFile)
    {
        nameBinFile = nameFile;
        SG.resize(vs.size());
        copy(vs.begin(), vs.end(), SG.begin());
    }

    void pushStudent(Stud::Student stud)
    {
        SG.push_back(stud);
    }

    void print()
    {
        for (auto it : SG)
        {
            it.print();
        }
    }

    virtual void Save() override
    {
        ofstream out(nameBinFile, ios::binary);
        for (auto it : SG)
        {
            out.write(reinterpret_cast<char*>(&it), sizeof(it));
        }
        out.close();
    }

    virtual void Open() override
    {
        ifstream in(nameBinFile, ios::binary);
        for (auto it : SG)
        {
            in.read(reinterpret_cast<char*>(&it), sizeof(it));
        }
        in.close();
    }


    virtual double GetAverageScore(Stud::FullName& _name) override
    {
        for (auto it : SG)
        {
            if (it.getName() == _name.getName() && it.getSurname() == _name.getSurname() && it.getPatron() == _name.getPatron())
            {
                return (it.getAverageScore());
            }
        }
    }

    virtual string GetAllInfo(Stud::FullName& _name) override
    {
        string res;
        for (auto it : SG)
        {
            if (it.getName() == _name.getName() && it.getSurname() == _name.getSurname() && it.getPatron() == _name.getPatron())
            {
                res += it.getName() + " " + it.getSurname() + " " + it.getPatron().value() + " ";
                res += it.getAverageScore();
                res += "\n";
                return res;
            }
        }
    }

    virtual string GetAllInfo() override
    {
        string res;
        for (auto it : SG)
        {
            res += it.getName() + " " + it.getSurname() + " " + it.getPatron().value() + " ";
            res += it.getAverageScore();
            res += "\n";
        }
        return res;
    }
private:
    vector<Stud::Student> SG;
    string nameBinFile;
};

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


int main()
{   
    setlocale(LC_ALL, "RUSSIAN");
    vector<int>scores1 = { 4, 4, 3, 4, 4, 5, 5, 4 };
    vector<int>scores2 = { 3, 4, 3, 5, 5, 5, 5, 4 };
    vector<int>scores3 = { 4, 4, 3, 3, 4, 3, 3, 4 };
    

    Stud::Student st1("Ivan", "Smirnov", "Vasilievich", scores1);
    Stud::Student st2("Michail", "Smit", "Alekseevich", scores2);
    Stud::Student st3("Vasilii", "Prohorov", " ", scores3);
    Stud::StudentsGroup stGroup;
    stGroup.pushStudent(st1);
    stGroup.pushStudent(st2);
    stGroup.pushStudent(st3);
    stGroup.print();
    ////////////////////////////////////////////////////////////////////////////////////////
    StudentsGroup StudGroup("data.bin");
    Stud::Student stud1("Ivan", "Ivanov", "Ivanovich", scores1);
    Stud::Student stud2("Mihail", "Mihailov", "Mihaiilovich", scores2);
    Stud::Student stud3("Vasilii", "Vasiliev", " ", scores3);
    Stud::Student stud4("Petr", "Petrov", "Petrovich", scores1);
    Stud::Student stud5("Aleksey", "Alekseev", "Alekseevich", scores2);
    StudGroup.pushStudent(stud1);
    StudGroup.pushStudent(stud2);
    StudGroup.pushStudent(stud3);
    StudGroup.pushStudent(stud4);
    StudGroup.pushStudent(stud5);

    StudGroup.Save();
    StudGroup.Open();

    return 0;
}