#include <iostream>
#include <string>
#include <cstring>
#include <limits>

using namespace std;

int main()
{
string count;	
string str1;
string *str2=nullptr;                                                                           
int k=0;
int z=0;
cin>>count;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin,str1);
cin>>z;
	for(int i=0; i<str1.length(); i++) {
		if(str1[i]>='0'&& str1[i]<='9')
			;
		else k++;
	}
	k++;
if(atoi(count.c_str())==k){
str2=new string[k];
for(int i=0,j=0;i<str1.length();i++)
  if(str1[i]>='0' && str1[i]<='9')
   str2[j]=str2[j]+str1[i];
  else 
    j++;
for(int i=k-z;i<k;i++)
cout<<str2[i]<<" ";
for(int i=0;i<k-z;i++)
cout<<str2[i]<<" ";

}
else
 cerr<<"An error has occurred while reading input data"<<endl;

return 0;	
}
