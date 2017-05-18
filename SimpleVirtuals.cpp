#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
protected:
	string name;
	int age;
	int id;

public:
	virtual void getdata()
	{
		cin >> name;
		cin >> age;
	}

	virtual void putdata() const
	{
		cout << name << " " << age << endl;
	}
};

class Professor : public Person
{
	static int curId;
	int publications;
	
	void getdata()
	{
		id = curId++;	
		Person::getdata();
		cin >> publications;
	}
	
	void putdata() const
	{
		cout << name << " " << age << " " << publications << " " << id << endl;
	}
};

class Student : public Person
{
	static int curId;
	static const int numMarks = 6;
	int marks[numMarks];
	int marksTotal = 0;
	
	void getdata()
	{
		id = curId++;
		Person::getdata();
		for ( int i = 0; i < numMarks; ++i )
		{
			cin >> marks[i];
			marksTotal += marks[i];
		}
	}
	
	void putdata() const
	{
		cout << name << " " << age << " " << marksTotal << " " << id << endl;
	}
};

int Professor::curId = 1;
int Student::curId = 1;


int main(){

    int n, val;
    n = 2; //The number of objects that is going to be created.
    Person *per[n];
	per[0] = new Professor;
    per[0]->getdata(); // Get the data from the user.
	per[1] = new Student;
	per[1]->getdata();
    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
