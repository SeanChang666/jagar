#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    float step,stepi;
    float x0,x,best,domainu=100,domaind=-100;
    int a = 0,n = 0,n0 = 0;
    double fit,fitr,fitl,tmp = 100;
    srand(114);
    x0 = rand()/(float)RAND_MAX*(domainu-domaind)+domaind;
    step = powf(2.0, (int)log2(domainu) - 11);
    fit = fabs(x0);
    fitr = fabs(x0 + step);
    fitl = fabs(x0 - step);
    n += 3;
    while(x + step != x){

        if(fitr < fitl){
            x = x0 + step;
        }else{
            x = x0 - step;
        }
        while(a == 0){
            step *= 2.0;
            x += step;
            fit = fabs(x);
            n += 1;
            if(fit < tmp){
                tmp = fit;
                best = x;
            }else{
                a = 1;
                step /= 2;
            }
        //cout << setprecision(20) << x << ' ' << fit << ' ' << step << endl;

        }
        while(step != stepi){
            fitr = fabs(x + step);
            fitl = fabs(x - step);
            n ++;
            cout << setprecision(20) << n << ' ' << x + step << ' ' << fitr << ' ' << step << endl;
            n ++;
            cout << setprecision(20) << n << ' ' << x - step << ' ' << fitl << ' ' << step << endl;
        }

    }
}