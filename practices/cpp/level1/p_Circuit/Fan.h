#ifndef FAN_H
#define FAN_H

#include <SwitchAble.h>
#include<iostream>
using namespace std;

class Fan : public SwitchAble
{
    public:
        Fan();
        virtual ~Fan();
        virtual void on(){
            cout<<"������"<<endl;
        }
        virtual void off(){
            cout<<"�ط���"<<endl;
        }
    protected:
    private:
};

#endif // FAN_H
