#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    float step;
    float x,domainu=100,domaind=-100;
    step = powf(2.0, (int)log2(domainu) - 11);
    cout << setprecision(20) << step;
    system("pause");
}