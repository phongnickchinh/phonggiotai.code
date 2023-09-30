#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){

    double a, b, c;
    scanf("%lf%lf%lf",&a, &b, &c);

   if(a==0&&b==0) cout<<"NO SOLUTION"; 
    else {if(a==0&&b!=0) printf("%.2lf", -c/b );
    else {
        double delta=b*b-4*a*c;
        if(delta<0) cout<<"NO SOLUTION"; 
        if(delta==0) printf("%.2lf", -b/(2*a));
        if(delta>0) printf("%.2lf %.2lf", (-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a));
    }
    }
    return 0;


}
