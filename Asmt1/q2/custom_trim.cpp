
#include <iostream> 
#include <string>
#include <algorithm>
using namespace std; 

void removeSpaces(string &str) 
{ 
	bool sf=false;
	int n = str.length(), i = 0, j = -1;   
	while (++j < n && str[j] == ' '); 
	while (j < n) 
	{ 
		if (str[j] != ' ') 
		{ 
			if ((str[j] == '.' || str[j] == ',' || str[j] == '?') && i - 1 >= 0 && str[i - 1] == ' ') 
				str[i - 1] = str[j++]; 

			else 
				str[i++] = str[j++];  
			sf = false; 
		} 
		else if (str[j++] == ' ') 
		{  
			if (!sf) 
			{ 
				str[i++] = ' '; 
				sf = true; 
			} 
		} 
	}  
	if (i <= 1) str.erase(str.begin() + i, str.end()); 
	else str.erase(str.begin() + i - 1, str.end()); 
} 

string delSpaces(string str){
	int len=str.length(), i, j;
	string ans ="";
	int it=0;
	cout<<len<<endl;
	while(str[it]==' ')++it;
	for( ; it<len-1; it++){

		if(str[it]=='-' && str[it+1]==' '){
			ans=ans+'-';
			++it;
			while(str[it]==' '){
				it++;
			}
			//
		}
		else if(str[it]==' ' && str[it+1]==' '){
			while(str[it+1]==' '){
				it++;
			}
			//ans=ans+' ';
		}
		ans=ans+str[it];
	}
	len = ans.length();
	if()
	return ans;
}

int main() 
{ 
	string str, tmp;// = " Hello Geeks . Welcome to   GeeksforGeeks . "; 
	getline(cin, str);
	cout<<"\nString is " << str<<endl;
	tmp = delSpaces(str); 

	cout<<"\nString is *" << tmp<<"* with length "<<tmp.length()<<endl; 

	return 0; 
} 
