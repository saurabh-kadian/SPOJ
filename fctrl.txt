#include<iostream>
using namespace std;
int main (){
 long long int t;
 cin >> t;
 while(t--){
   long long int n,tot =0;
   cin >>n;
   long long int five =5;
   while(n/five !=0){
     tot+=n/five;
     five*=5;
}
cout << tot << endl;
}
}
