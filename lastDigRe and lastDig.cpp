#include <iostream>
#include <string>
#define q if
#define X return
using namespace std;int pow(int a,long long int b){q(a==0&&b==0)X 0;
q(b==0||a==1)X 1;q(a==5||a==6||a==0||b==1)X a;q(a==2){q(b%4==1)X 2;q(b%4==2)X 4;q(b%4==3)X 8;else X 6;}q(a==3){q(b%4==1)X 3;q(b%4==2)X 9;q(b%4==3)X 7;else X 1;}q(a==4){q(b%2==1)X 4;else X 6;}q(a==7){q(b%4==1)X 7;q(b%4==2)X 9;q(b%4==3)X 3;else X 1;}q(a==8){q(b%4==1)X 8;q(b%4==2)X 4;q(b%4==3)X 2;else X 6;}q(a==9){q(b%2==1)X 9;else X 1;}}
int main(){long long int t;cin >> t;while(t--){long long int b;string a;cin>>a>>b;cout<<pow((int)a[a.length()-1]-48,b)<<endl;}X 0;}
