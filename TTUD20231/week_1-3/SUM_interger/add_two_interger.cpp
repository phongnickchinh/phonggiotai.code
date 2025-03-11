#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a, b;
    
    cin >> a >> b;
    unsigned long long a1, a2, b1, b2,c,d;
    a2 = a % 10;
    b2 = b % 10;
    a1 = (a - a2)/10;
    b1 = (b - b2)/10;
    c = (a2 + b2) % 10;
    d = a1 + b1;
    if ((a2+b2) >= 10) d++;
    if (d!=0) cout << d << c;
    else printf("%lld", c);
    return 0;

}