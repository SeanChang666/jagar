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
    x = x0;
    step = powf(2.0, (int)log2(domainu) - 11);
    stepi = step;
    fit = fabs(x0);
    fitr = fabs(x0 + step);
    fitl = fabs(x0 - step);
    n += 3;
    cout << setprecision(20) << n << ' ' << x << ' ' << fit << ' ' << step << endl;
    while(x + step != x){                       
        if(fitr < fitl){                                       //左右看
            x = x0 + step;
        }else{
            x = x0 - step;
        }                                   
        while(a == 0){                                         //加速
            step *= 2.0;
            x += step;
            fit = fabs(x);
            n ++;
            
            if(fit < tmp){
                tmp = fit;
                best = x;
            }else{
                a = 1;
                step /= 2;
            }
            cout << setprecision(20) << n << ' ' << x << ' ' << fit << ' ' << step << endl;

        }
        step /= 2;
        while(step != stepi){                                  //減速
            
            fitr = fabs(x + step);
            fitl = fabs(x - step);
            n ++;
            cout << setprecision(20) << n << ' ' << x + step << ' ' << fitr << ' ' << step << endl;
            n ++;
            cout << setprecision(20) << n << ' ' << x - step << ' ' << fitl << ' ' << step << endl;
            if(fitr < fitl){
                if(fitr < fabs(best)){
                    break;
                    best = x + step;
                    step *= 2;
                }else{
                    step /= 2;
                    best = x + step;
                }
                x = best;
            }else if(fitr > fitl){
                if(fitl < fabs(best)){
                    break;
                    best = x - step;
                    step *= 2;
                }else{
                    step /= 2;
                    best = x - step;
                }
                x = best;
            }else{
                step /= 2;
                x = best;
            }
        }
        step /= 2;
    }
    system("pause");
}