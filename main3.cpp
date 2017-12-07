#include <iostream>
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
	int **array=new int*[n];
	for(int i=0; i<n; i++)
		array[i]=new int[m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			array[i][j]=0;
	int y=1;
	int count;
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
		for(int i=z,j=t,k=0; k<count; k++) {
			if(j<(m-1)-t && i==0+z) {
				array[i][j++]=y++;
				continue;
			} else if(i<(n-1)-z && j==(m-1)-t) {
				array[i++][j]=y++;
				continue;
			} else if(j>t && i==(n-1)-z) {
				array[i][j--]=y++;
				continue;
			} else if(i>z && j==0+t) {
				array[i--][j]=y++;
				continue;
			} else if(i==j && count==1) {
				array[i][j++]=y++;
				continue;
			}
		}
		t++;
		z++;
		l-=2;
		f-=2;
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cout<<setw(5)<<array[i][j];
		cout<<endl;
	}


	return 0;
}
