//CPP 
#include <bits/stdc++.h> 
using namespace std;
unsigned long long thuong_so(unsigned long long x){
	unsigned long long thuongso=x/10;
	return thuongso;
}
int so_du(long long x){
	int sodu=x%10;
	return sodu;
}


int main() 
{ 
unsigned long long a, b;
cin>>a>>b;
unsigned long long a1=thuong_so(a);
int a2=so_du(a);

unsigned long long b1=thuong_so(b);
int b2= so_du(b);

if(a+b<10){
	cout<<a+b;
	return 0;
}
int c2=a2+b2;
if(c2<10){
	unsigned long long sum=a1+b1;
	cout<<sum<<c2;
	return 0;
}else{
	unsigned long long sum=a1+b1+1;
	cout<<sum<<c2%10;
	return 0;
}
}
