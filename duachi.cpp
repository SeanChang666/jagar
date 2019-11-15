#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    double fit;
    //double 
    float x,domainu=100,domaind=-100;
    int y;
    srand(114);
    for(int i = 0;i < 30;i++){
        y = rand();
        x = y/(float)RAND_MAX*(domainu-domaind)+domaind;
        fit = fabs(x);
        cout << setprecision(20) << x << ' ' << fit << endl;
    }
    system("pause");
}
