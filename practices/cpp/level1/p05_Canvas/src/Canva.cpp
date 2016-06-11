#include "Canva.h"

Canva::Canva()
{
    //ctor
}

Canva::~Canva()
{
    //dtor
}

void Canva::draw(Circle circle){
    circleList.push_back(circle);
}

void Canva::draw(Rect rect){
    rectList.push_back(rect);
}


void Canva::showAllShape(){
    for(int i=0;i<circleList.size();i++){
        cout<<"Բ�����꣺��"<<circleList[i].keyPointX<<"��"<<circleList[i].keyPointY<<"��,"<<"�뾶Ϊ��"<<circleList[i].r<<endl;
    }
    for(int i=0;i<rectList.size();i++){
        cout<<"���������Ͻ����꣺��"<<rectList[i].keyPointX<<"��"<<rectList[i].keyPointY<<"������Ϊ��"<<rectList[i].length<<",��Ϊ��"<<rectList[i].width<<""<<endl;
    }
}

