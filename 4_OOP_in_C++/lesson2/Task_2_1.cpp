#include <iostream>
using namespace std;

class Person
{
public:
	Person(string _name = "NoName", int _age = 0, char _gender = 'N', int _weight = 0)
	{
		name = (_name == "\0" || _name == " ") ? "NoName" : _name;
		age = (_age > 0) ? _age : 0;
		gender = (_gender != 'M' && _gender != 'W') ? 'N' : _gender;
		weight = (_weight > 0) ? _weight : 0;
	}

	Person(Person& P)
	{
		name = P.name;
		age = P.age;
		gender = P.gender;
		weight = P.weight;
	}

	void setName(string newName)
	{
		name = newName;
	}

	void setAge(int newAge)
	{
		age = newAge;
	}

	void setWeight(int newWeight)
	{
		weight = newWeight;
	}

	void print()
	{
		cout << name << " " << age << " " << gender << " " << weight << " ";
	}

protected:
	string name;
	int age;
	string gender;
	int weight;
};



class Student:public Person
{
public:
	Student(string _name = "NoName", int _age = 0, char _gender = 'N', int _weight = 0, int _studyYear = 0) :Person(_name, _age, _gender, _weight)
	{
		studyYear = (_studyYear > 0) ? _studyYear : 0;
		summStud++;
	}

	~Student()
	{
		summStud--;
	}

	void setStudyYear(int newStudyYear)
	{
		studyYear = newStudyYear;
	}

	void nextStudyYear()
	{
		studyYear++;
	}

	void print()
	{
		Person::print();
		cout << studyYear << endl;
	}

	static int getSummStudent()
	{
		return summStud;
	}
private:
	int studyYear;
	static int summStud;
};