#include "Student.h"

Student::Student()
{
    //ctor
}

Student::Student(int ID,string name,int score)
{
    this->ID = ID;
    this->name = name;
    this->score = score;
}

void Student::setImformation(){
    int ID;
    string name;
    int score = 0;
    cout<<"������ѧ��ѧ�ţ�"<<endl;
    cin>>ID;
    cout<<"������ѧ�����֣�"<<endl;
    cin>>name;

    this->ID = ID;
    this->name = name;
    this->score = score;
}

Student::~Student()
{
    //dtor
}

void Student::showImformation(){
    cout<<name<<" ѧ��:"<<ID<<" ����:"<<score<<endl;
}

int Student::setScore(int score){
    this->score = score;
}
