#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int getCodeFromCmd(string cmd)
{	
	int code, i, len, exist, ind;
	string st, realcmd;
	map <string, int> cmd2code;
	cmd2code.insert({ "ls", 1 });
	cmd2code.insert({ "ls -a", 2 });
	cmd2code.insert({ "cd", 3 });
	cmd2code.insert({ "cat", 4 });
	cmd2code.insert({ "cat -n", 5 });
	cmd2code.insert({ "mkdir", 6 });
	cmd2code.insert({ "mkdir -m", 7 });
	cmd2code.insert({ "cp", 8 });
	cmd2code.insert({ "cp -u", 9 });
	cmd2code.insert({ "sort", 10 });
	cmd2code.insert({ "sort -r", 11 });
	cmd2code.insert({ "grep", 12 });
	cmd2code.insert({ "grep -n", 13 });

	string cmd_ar[] = {"ls", "cat", "mkdir", "cp", "sort", "grep", "cd"};
	string flags[]={" -a", " -n", " -m", " -u", " -r", " -n"};
	len = (int)sizeof(cmd_ar)/sizeof(cmd_ar[0]);
	for(i=0; i<len; i++){
		exist = cmd.find(cmd_ar[i]);
		if(!exist)break;
	}

	ind=cmd_ar[i].length();
	if(i<6){
		if(cmd[ind]!=' ' || cmd[ind+1]!='-' || cmd[ind+2]!=flags[i][2])return 0;
	}
	else if(i==6 && cmd[ind]!=' ')return 0;

	if(i<6)realcmd = cmd_ar[i] + flags[i];
	exist = cmd.find(realcmd);
	if(exist)realcmd = cmd_ar[i];
	code = cmd2code[realcmd];
	return code;
}

int main()
{
	//cp is taking two arg, validate it 
	
	string cmd;
	getline(cin, cmd);
	cout<<getCodeFromCmd(cmd)<<endl;

	return 0;
}