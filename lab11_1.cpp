// cout << "Press Enter 3 times to reveal your future.";
// cout << "You will get A in this 261102.";
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main (){

    srand(time(0)) ;
    string grade[9] = {"A","B+","B","C+","C","D+","D","F","W"};
    cout << "Press Enter 3 times to reveal your future.";  
    cin.get();
    cin.get();
    cin.get();
    int num = rand() % 9;
    cout << "You will get "<< grade[num]<<" in this 261102."; 

    return 0;
}
