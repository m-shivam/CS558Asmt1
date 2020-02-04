#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <iomanip>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <cstdio>
using namespace std;

char pwd[256];
string path="/home/shivam/";

void getpwd(){
	getcwd(pwd, 256);
}

void init_shell(bool shellpath=false)
{
	if(shellpath){
		string shell="\nShiRu@linux:~";
		getpwd();
		// (pwd+12) is address of string 
		shell = shell+(pwd+12)+"$ ";
		cout<<shell;
	}
	else cout<<"\nShiRu@linux:~$ ";
}

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

int main(int argc, char const *argv[])
{
	
	string cmd;
	vector<string> args;
	getline(cin, cmd);
	args = getArgs(cmd);
	init_shell(true);
	return 0;
}
