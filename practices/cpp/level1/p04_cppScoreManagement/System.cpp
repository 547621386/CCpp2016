#include "System.h"

System::System()
{
    //ctor
}

System::~System()
{
    //dtor
}

void System::showAllStudent(){
    for(int i=0;i<StudentList.size();i++){
        StudentList[i].showImformation();
    }
}

void System::addStudent(Student newStudent){
    StudentList.push_back(newStudent);
}

void System::addNewStudent(){
    Student newStudent;
    newStudent.setImformation();
    StudentList.push_back(newStudent);
}
void System::delateStudent(){
    cout<<"��������Ҫɾ����ѧ����ѧ�ţ�";
    int delateID;
    cin>>delateID;
    for(int i=0;i<StudentList.size();i++){
        if(StudentList[i].getID() == delateID){
            StudentList.erase(StudentList.begin()+i);
        }
    }
}

void System::enteringScore(){
    for(int i=0;i<StudentList.size();i++){
        StudentList[i].showImformation();
        cout<<"������ɼ���";
        int newScore;
        cin>>newScore;
        StudentList[i].setScore(newScore);
    }
}
