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
cin>>count;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin,str1);
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
for(int i=0;i<k/2;i++)
  swap(str2[i],str2[k-i-1]);
str1="";
for(int i=0;i<k;i++)
  str1=str1+str2[i]+" ";
  cout<<str1<<endl;
}
else
 cerr<<"An error has occurred while reading input data"<<endl;

return 0;	
}
