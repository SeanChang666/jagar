#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    float step;
    float x,domainu=100,domaind=-100;
    double fit;
    srand(114);
    x = rand()/(float)RAND_MAX*(domainu-domaind)+domaind;
    step = powf(2.0, (int)log2(domainu) - 11);
    fit = fabs(x);
    cout << setprecision(20) << x << ' ' << fit << endl;
    x += step;
    fit = fabs(x);
    cout << setprecision(20) << x << ' ' << fit << endl;
    x -= 2.0*step;
    fit = fabs(x);
    cout << setprecision(20) << x << ' ' << fit << endl;
    system("pause");
}