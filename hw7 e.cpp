#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    float step,stepi;
    float x0,x,best,domainu=100,domaind=-100;
    int n = 0,n0 = 0,skip = 0,dir;
    double fit,fitr,fitl,tmp = 100,fitb;
    srand(114);
    x = rand()/(float)RAND_MAX*(domainu-domaind)+domaind;
    step = powf(2.0, (int)log2(domainu) - 11);
    stepi = step;
    fit = fabs(x);
    n++;
    cout << setprecision(50) << n << ' ' << x << ' ' << fit << ' ' << step << endl;
    while(x + step != x){
        //cout << "rlrlrlrlrlrl"<< endl;           
        fitr = fabs(x + step);
        fitl = fabs(x - step);
        n++;
        cout << setprecision(50) << n << ' ' << x+step << ' ' << fitr << ' ' << step << endl;
        n++;
        cout << setprecision(50) << n << ' ' << x-step << ' ' << fitl << ' ' << step <<endl;            
        if(fitr < fitl){                     //左右看
            if(fitr < tmp){                  //找到右邊較好的解
                skip = 1;
                tmp = fitr;
                x += step;
                dir = 1;
            }                                     
        }else if(fitr > fitl){
            if(fitl < tmp){                  //找到左邊較好的解
                skip = 1;
                tmp = fitl;
                x -= step;
                dir = 0;
            }
        }
        //cout << "pppppp"<< endl;                                   
        while(skip == 1){                                         //加速
            step *= 2;
            if(dir == 1){
                if(x + step > 100){
                    step /= 2;
                    fit = fabs(x+step);
                    n++;
                    cout << setprecision(50) << n << ' ' << x + step << ' ' << fit << ' ' << step << endl;
                    skip = 0;
                    break;
                }
                fit = fabs(x+step);
                n++;
                cout << setprecision(50) << n << ' ' << x+step << ' ' << fit << ' ' << step << endl;
                fitb = fabs(x);
                if(fit < fitb){
                    tmp = fit;
                    x += step;
                    
                }else{
                    step /= 2;
                    fit = fabs(x+step);
                    skip = 0;
                    n++;
                    cout << setprecision(50) << n << ' ' << x+step << ' ' << fit << ' ' << step << endl;
                }
            }else{
                if(x - step < -100){
                    step /= 2;
                    fit = fabs(x-step);
                    n++;
                    cout << setprecision(50) << n << ' ' << x - step << ' ' << fit << ' ' << step << endl;
                    skip = 0;
                    break;
                }
                fit = fabs(x-step);
                n++;
                cout << setprecision(50) << n << ' ' << x-step << ' ' << fit << ' ' << step <<endl;
                fitb = fabs(x);
                if(fit < fitb){
                    tmp = fit;
                    x -= step;
                    
                }else{
                    step /= 2;
                    fit = fabs(x-step);
                    skip = 0;
                    n++;
                    cout << setprecision(50) << n << ' ' << x-step << ' ' << fit << ' ' << step <<endl;
                }
            }
            
            
            
        }
        //cout << "mmmmmmmm"<< endl;
        step /= 2;
        while(step != stepi/2){                                      //step回到初始//減速
            
            fitr = fabs(x + step);
            fitl = fabs(x - step);
            n ++;
            cout << setprecision(50) << n << ' ' << x + step << ' ' << fitr << ' ' << step << endl;
            n ++;
            cout << setprecision(50) << n << ' ' << x - step << ' ' << fitl << ' ' << step << endl;
            if(fitr < fitl){
                if(fitr < tmp){                  
                    tmp = fitr;
                    //cout << setprecision(50) << n << ' ' << x + step << ' ' << fit << ' ' << step << endl;
                    x += step;
                }   
                step /= 2;                    
            }else{
                if(fitl < tmp){                  
                    tmp = fitl;
                    //cout << setprecision(50) << n << ' ' << x - step << ' ' << fit << ' ' << step << endl;
                    x -= step;if(x + step > 100){
                    step /= 2;
                    fit = fabs(x+step);
                    n++;
                    cout << setprecision(50) << n << ' ' << x << ' ' << fit << ' ' << step << endl;
                    break;
                    }
                }
                step /= 2;
            }
            
        }
        //step /= 2;
        stepi /= 2;
        step = stepi;
    }
    system("pause");
}