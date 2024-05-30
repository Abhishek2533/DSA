#include<iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;

    do                  // In do-while loop will execute the atleast one time without break
    {
        cout<<n<<endl;
        cin>>n;
    } while (n>0);
    
    

    return 0;
}

// There is only one difference in while and do-while that in while first condition will check then execute,,,,, where in do-while execute one time then check the condition