#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
	int n=0;
	int k=0;
	int *z=NULL;
	string str;
	cin>>n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,str);
	for(int i=0; i<str.length(); i++) {
		if(str[i]>='0'&& str[i]<='9')
			;
		else k++;
	}
	k++;
	if(n!=k) {
		cout<<"An error has occurred while reading input data"<<endl;
	} else {
		z=new int[n];
		for(int i=0; i<n; i++)
			z[i]=0;
		int y=0;
		for(int i=0; i<str.length()+1; i++)
			if(str[i]>='0'&&str[i]<='9')
				z[y]=z[y]*10+str[i]-'0';
			else y++;

		for(int i=0; i<n/2; i++)
			swap(z[i],z[n-i-1]);

		for(int i=0; i<n; i++)
			cout<<z[i]<<" ";
	}

	return 0;
}
