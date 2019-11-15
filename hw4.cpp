#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    float step;
    float x0,x,domainu=100,domaind=-100;
    double fit,fitl,fitr,tmp = 100;
    int a = 0,n = 0;
    srand(114);
    x0 = rand()/(float)RAND_MAX*(domainu-domaind)+domaind;
    step = powf(2.0,(int)log2(domainu) - 11);
    fit = fabs(x0);
    fitr = fabs(x0 + step);
    fitl = fabs(x0 - step);
    n += 3;
    if(fitr < fitl){
        x = x0 + step;
    }else{
        x = x0 - step;
    }
    cout << setprecision(20) << n << ' ' << x << ' ' << fit << endl;
    while(a == 0){
        step *= 2;
        x += step;
        fit = fabs(x);
        n += 1;
        if(fit < tmp){
            tmp = fit;
        }else{
            a = 1;
        }
        cout << setprecision(20) << n << ' ' << x << ' ' << fit << ' ' << step << endl;

    }
    system("pause");
}