#include<iostream>
#include <cmath>
using namespace std;

int main(){
    int a;
    cin>>a;
    int l=a;
    int c = 0;
    int r=0;
    int n=0;
    while(a){
        c=c+1;
        a=a/10;
    }
    cout<<"size of no. is"<<c<<endl;
     c=c-1;
    while(l){
        r=l%10;
        n=n+(r*(pow(10,c)));
        c=c-1;
        l=l/10;
        cout<<"r"<<r<<endl;
        cout<<"n"<<n<<endl;

    }
cout<<"reverse of no. is"<< n<<endl;












//     int a,b,c;
//     cin>>a>>b>>c;
//     if(a>b&&a>c){
//         cout<<a<<endl;
//     }
    
//     if(b>c){cout<<b<<endl;}
//     else{cout<<c<<endl;}
}