#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;


vector<string> getArgs(string cmd){
	string tmp;
	vector<string> args;
	int i, ind, len;
	bool flag=false;
	tmp="";
	len = cmd.length();
	for(i=0; i<len; i++){
		if(cmd[i]==' ' && i<len && tmp!="")
		{
			//cout<<i<<" "<<tmp<<endl;
			args.push_back(tmp);
			tmp="";
			flag=false;
		}
		else{
			tmp = tmp + cmd[i];
			flag=false;
		}
		while(cmd[i]==' ' && cmd[i+1]==' ' && i<len){
			i++;
			flag=true;
		}
	}
	if(!flag && tmp!=""){
		//cout<<i<<" "<<tmp<<endl;
		args.push_back(tmp);
	}
	return args;
}


int shell_sort(vector<string> v, bool revflag=false){
	string tmp;
	vector<string> buf;

	int i=1, n = v.size();
	if(revflag)i=2;
	for (; i < n; ++i)
	{
		if(v[i]=="")continue;
		ifstream filevar(v[i]);
		if (filevar.is_open())
		{
			while ( getline (filevar,tmp) )
			{
				//cout<<tmp<<endl;
				buf.push_back(tmp);
			}
			filevar.close();
		}
	  else{
	  	cout << "Couldn't open file *"<< v[i] <<"*"<<endl;
	  	return 1;
	  } 
	}
  	n = buf.size();
  	sort(buf.begin(), buf.end());

  	if(revflag)for (i = n-1; i > 0; --i)cout<<buf[i]<<endl;
  	else for (i = 0; i < n; ++i)cout<<buf[i]<<endl;
  	return 0;
}


int main(){

	string cmd, tmp;
	getline(cin, cmd);
	vector<string> buf, v;
	v = getArgs(cmd);
	if(v[1]!="-r")shell_sort(v);
  	else shell_sort(v, true);

	return 0;
}