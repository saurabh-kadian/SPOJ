#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

int main() {
	// your code goes here
	long long int t,i=0;
	cin >> t;
	while(t--){
		string str,e,r,t;
		char ch,ch1;
		cin >> e >> ch >> r >> ch1 >> t;
		str += e;
		str += ch;
		str += r;
		str += ch1;
		str += t;
		//cout << str << endl;
		bool plus = false,equal = false,blot = false;
		int cra = 0, crb = 0, crc = 0;
		for(long long int i=0;i<str.length();++i){
			if(str[i] == 'm' && plus == false)
				blot = true,cra = 1;
			else if(str[i] == 'm' && plus == true && equal == false)
				blot = true,crb = 1;
			else if(str[i] == 'm' && plus == true && equal == true)
				blot = true,crc = 1;
			if(blot)
				break;
			if(str[i] == '+')
				plus = true;
			if(str[i] == '=')
				equal = true;
		}
		//cout << cra << " " << crb << " " << crc << endl;
		if(cra == 1){
			long long int i=0;
			for(i=0;i<str.length();++i)
				if(str[i] == '+')
					break;
			long long int x,y,z;
			string partB = "",partC = "" ;
			for(i++;i<str.length();++i){
				if(str[i] == '=')
					break;
				partB += str[i];
			}
			for(i++;i<str.length();++i){
				partC += str[i];
			}
			if(partB[0] == ' ')
				partB.erase(partB.begin()+0);
			if(partB[partB.length()-1] == ' ')
				partB.erase(partB.begin()+partB.length()-1);
			if(partC[0] == ' ')
				partC.erase(partC.begin()+0);
			if(partC[partC.length()-1] == ' ')
				partC.erase(partC.begin()+partC.length()-1);
			stringstream ss(partB),ss1(partC);
			ss >> y;
			ss1 >> z;
			x = z - y;
			//cout << "partA" << " + " << partB << " = " << partC << endl;
			cout << x << " + " << y << " = " << z << endl;
		}
		else if(crb == 1){
            long long int i=0;
            string partA = "",partC = "" ;
			for(i=0;i<str.length();++i){
				if(str[i] == '+')
					break;
                partA += str[i];
			}
			long long int x,y,z;
			for(i++;i<str.length();++i){
				if(str[i] == '=')
					break;
			}
			for(i++;i<str.length();++i){
				partC += str[i];
			}
			if(partA[0] == ' ')
				partA.erase(partA.begin()+0);
			if(partA[partA.length()-1] == ' ')
				partA.erase(partA.begin()+partA.length()-1);
			if(partC[0] == ' ')
				partC.erase(partC.begin()+0);
			if(partC[partC.length()-1] == ' ')
				partC.erase(partC.begin()+partC.length()-1);
			stringstream ss(partA),ss1(partC);
			ss >> x;
			ss1 >> z;
			y = z - x;
			//cout << "partA" << " + " << partB << " = " << partC << endl;
			cout << x << " + " << y << " = " << z << endl;
		}
		else{
            long long int i=0;
            string partA = "",partB = "" ;
			for(i=0;i<str.length();++i){
				if(str[i] == '+')
					break;
                partA += str[i];
			}
			long long int x,y,z;
			for(i++;i<str.length();++i){
				if(str[i] == '=')
					break;
                partB += str[i];
			}
			for(i++;i<str.length();++i){
				continue;
			}
			if(partA[0] == ' ')
				partA.erase(partA.begin()+0);
			if(partA[partA.length()-1] == ' ')
				partA.erase(partA.begin()+partA.length()-1);
			if(partB[0] == ' ')
				partB.erase(partB.begin()+0);
			if(partB[partB.length()-1] == ' ')
				partB.erase(partB.begin()+partB.length()-1);
			stringstream ss(partA),ss1(partB);
			ss >> x;
			ss1 >> y;
			z = y + x;
			//cout << "partA" << " + " << partB << " = " << partC << endl;
			cout << x << " + " << y << " = " << z << endl;
		}
	}
	return 0;
}
