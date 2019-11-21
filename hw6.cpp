#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    float step,stepi;
    float x0,x,best,domainu=100,domaind=-100;
    double fit,fitr,fitl,tmp = 100;
    int a = 0,n = 0;
    srand(114);
    x0 = rand()/(float)RAND_MAX*(domainu-domaind)+domaind;
    x = x0;
    step = powf(2.0, (int)log2(domainu) - 11);
    stepi = step;
    fit = fabs(x0);
    fitr = fabs(x0 + step);
    fitl = fabs(x0 - step);
    n += 3;
    if(fitr < fitl){
        x = x0 + step;
    }else{
        x = x0 - step;
    }
    //cout << setprecision(20) << x << ' ' << fit << endl;
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
        }
        //cout << setprecision(20) << x << ' ' << fit << ' ' << step << endl;

    }
    step /= 2;
    x = best;
    while(step != stepi){
        step /= 2;
        fitr = fabs(x + step);
        fitl = fabs(x - step);
        n ++;
        cout << setprecision(20) << n << ' ' << x + step << ' ' << fitr << ' ' << step << endl;
        n ++;
        cout << setprecision(20) << n << ' ' << x - step << ' ' << fitl << ' ' << step << endl;
        if(fitr < fitl){
            if(fitr < fabs(best)){
                best = x + step;
            }
            x = best;
        }else if(fitr > fitl){
            if(fitl < fabs(best)){
                best = x - step; 
            }
            x = best;
        }
        
    }
    //
    system("pause");
}