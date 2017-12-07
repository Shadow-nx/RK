#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
	string matrix_size;
	getline(cin,matrix_size);
	cin.clear();
	int n=0;
	int m=0;
	n=atoi(matrix_size.c_str());
	if(matrix_size.find(',')!=string::npos)
		matrix_size.erase(0,matrix_size.find(',')+1);
	if(matrix_size.find('.')!=string::npos)
		matrix_size.erase(0,matrix_size.find('.')+1);
	m=atoi(matrix_size.c_str());
	if(n==0 || m==0) {
		cout<<"An error has occurred while reading input data"<<endl;
		return 1;
	}
	string *str=new string[n];
	for(int i=0; i<n; i++) {
		getline(cin,str[i]);
		if(str[i]=="") {
			cout<<"An error has occurred while reading input data"<<endl;
			return 1;
		}
		cin.clear();
	}

	int *str_m=new int[n*m];

	for(int i=0; i<n*m; i++)
		str_m[i]=0;

	int size_count=0;
	string numbers;
	for(int i=0; i<n; i++)
		numbers=numbers+str[i]+" ";

	string number;
	for(int i=0; i<numbers.length(); i++) {
		while(numbers[i]>='0' && numbers[i]<='9') {
			number=numbers[i];
			str_m[size_count]=str_m[size_count]*10+atoi(number.c_str());
			i++;
		}
		size_count++;
	}
	if(size_count<n*m) {
		cout<<"An error has occurred while reading input data"<<endl;
		return 1;
	}
	int **array=new int*[n];
	for(int i=0; i<n; i++)
		array[i]=new int[m];
	for(int i=0,u=0; i<n; i++)
		for(int j=0; j<m; j++)
			array[i][j]=str_m[u++];

	int y=0;
	int count=0;
	cin>>y;
	int g=0;
	int h=0;
	int t=0;
	int z=0;
	int l=n;
	int f=m;
	while(l>0 && f>0) {
		if((((l+f)*2)-4)>0 && l>1 && f>1)
			count=(((l+f)*2)-4);
		else if((((l+f)*2)-4)>0 && l==1)
			count=f;
		else if((((l+f)*2)-4)>0 && f==1)
			count=l;
		else if((((l+f)*2)-4)==0)
			count=1;
		for(int p=0; p<y; p++) {
			for(int i=z,j=t,k=0; k<count; k++) {
				if(j<(m-1)-t && i==0+z) {
					swap(array[g][h],array[i][j++]);
					continue;
				} else if(i<(n-1)-z && j==(m-1)-t) {
					swap(array[g][h],array[i++][j]);
					continue;
				} else if(j>t && i==(n-1)-z) {
					swap(array[g][h],array[i][j--]);
					continue;
				} else if(i>z && j==0+t) {
					swap(array[g][h],array[i--][j]);
					continue;
				}
			}
		}
		t++;
		z++;
		l-=2;
		f-=2;
		g++;
		h++;
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cout<<setw(5)<<array[i][j];
		cout<<endl;
	}
	return 0;
}
