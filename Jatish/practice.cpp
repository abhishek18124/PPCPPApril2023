#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int h,b,p;
    cout<<"enter perpendicular , base , hypotenous respectively"<<endl;
    cin >> p >> b >> h; 
    bool ans;
    ans = ((h*h)==(p*p)+(b*b))? 1:0; 
    if(ans) cout<<"yes"<<endl;
    else cout<<"no"<<endl;


    
}