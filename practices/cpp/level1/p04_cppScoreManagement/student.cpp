#include<iostream>
using namespace std;
#include"student.h"
void Student::inputgrade()
{
	int grade;
	cout << "������"<<name<<"�ĳɼ�" << endl;
	cin >> grade;
	this->grade = grade;
}

int Student::getID()
{
	return ID;
}

string Student::getname()
{
	return name;
}

int Student::getgrade()
{
	return grade;
}

Student::~Student()
{
	cout << "ɾ���ɹ�" << endl;
}
