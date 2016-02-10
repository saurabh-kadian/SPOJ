#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    unsigned long long int t;
    cin >> t;
    while(t--)
    {
        unsigned long long int a,b,i,j,k,l;
        cin >> a;
        cin >> b;
        char a_str[80],b_str[80],a_rev[80],b_rev[80],a_fin[80],a_fin1[80];
        sprintf(a_str,"%llu",a);
        sprintf(b_str,"%llu",b);
        i=strlen(a_str);
        j=strlen(b_str);
        --i;--j;
        for(k=0,l=i;k<=i;++k,--l)
            a_rev[k]=a_str[l];
        a_rev[k]='\0';
        for(k=0,l=j;k<=j;++k,--l)
            b_rev[k]=b_str[l];
        b_rev[k]='\0';
        sscanf(a_rev,"%llu",&a);
        sscanf(b_rev,"%llu",&b);
        a+=b;
        sprintf(a_fin1,"%llu",a);
        i=strlen(a_fin1);
        --i;
        for(k=0,l=i;k<=i;++k,--l)
            a_fin[k]=a_fin1[l];
        a_fin[k]='\0';
        sscanf(a_fin,"%llu",&a);
        cout << a << endl;
    }
    return 0;
}

