#include <iostream> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include<vector>
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

// this function converts string argument to mode_t type.
mode_t getMode(string mode){
	mode_t ans=0, modar[]={0400, 0200, 0100, 0040, 0020, 0010, 0004, 0002, 0001};
	int rwx=0, bitval=0, ind=8;
	for(rwx=3; rwx>0; rwx--){
		bitval = mode[rwx]-'0';
		//cout<<ind<<" "<<mode[rwx]<<" "<<bitval<<endl;
		while(bitval>0){
			if(bitval%2)ans += modar[ind];
			bitval /= 2;
			ind--;
		}
		bitval=0;
	}
//cout<<"mode:*"<<ans<<"*\n";
return ans;
}

int makedir(vector<string> arg, bool modeflag=false){

	int i=1, len = arg.size();
	mode_t mode=0755;
	if(modeflag){
		i=3;
		mode = getMode(arg[2]);
	}
	for (; i < len; ++i)
			if(mkdir ( arg[i].c_str(), mode))
				cout << "Error : Check path or folder name\n";
}




int main() 

{ 
	vector<string> arg;
	string cmd;
	getline(cin, cmd);
	arg = getArgs(cmd);
	
	if(arg[0]=="mkdir"){
				if(arg[1]!="-m")makedir(arg);
				else makedir(arg, true);
	}
	else cout<<"Command "<<arg[0]<<" not found."<<endl;
	
	 
	return 0;
} 

// int main() 

// { 
// 	vector<string> arg;
// 	string cmd;
// 	int len;
// 	mode_t arw=0755, arwx=;
// 	getline(cin, cmd);
// 	arg = getArgs(cmd);
// 	len = arg.size();
// 	if(arg[0]=="mkdir"){
// 		for (int i = 1; i < len; ++i)
// 			if(mkdir ( arg[i].c_str(), rwx))
// 				cout << "Error : Check path or folder name\n";		
// 	}
// 	else cout<<"Command "<<arg[0]<<" not found."<<endl;
	
	 
// 	return 0;
// } 
