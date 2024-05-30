// A person can go out only on odd days

#include<iostream>
using namespace std;

int main ()
{
    int pocketMoney=3000;
    for (int date = 1; date <= 30; date++)
    {
        if (date%2==0)
        {
            continue;       //use to skip to the next iternation of the loop
        }

        if (pocketMoney==0)
        {
            break;          // use to terminate the loop
        }
        
        
        cout<<"Go out today!"<<endl;
        pocketMoney=pocketMoney-300;
    }
    
}