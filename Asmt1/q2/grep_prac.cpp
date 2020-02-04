#include<bits/stdc++.h>
#include<string.h>
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
		args.push_back(tmp);
	}
	return args;
}

int substring(string line,string str,int flag)
{
    int count=0,len1=line.size(),len2=str.size(),x;
    if(flag==0){
        for(int i=0; i<=len1-len2; i++){
            x=0;
            while(x<str.size() && line[i+x] == str[x])x++;
            if(x == len2)count++;
        }
        return count;
    }else{
        for(int i=0; i<=len1-len2; i++){
            x=0;
            while(x<len2){
                if(line[i+x] == str[x])x++;
                else if((str[x]>='a' && str[x]<='z') && (line[i+x]>='A' && line[i+x]<='Z') && (str[x]-32 == line[i+x]))x++; 
                else if((str[x]>='A' && str[x]<='Z') && (line[i+x]>='a' && line[i+x]<='z') && (str[x]+32 == line[i+x]))x++;
                else{
                    x++;
                    break;
                }
            }
            if(x == len2)count++;
        }
    }
    return count;
}


void grep(vector<string> args, int ind)
{
    bool mulex=false;
    int fi=2,x=1, strlen=args.size();
   
    if(ind==0 && strlen>3)mulex=true;
    
    if(ind!=0){
        fi=3;
        x=2;
        if(strlen>4)mulex=true;
    }
    for (; fi < strlen; ++fi)
    {
        string line,str="";
        int flag = 0;
        int total = 0,linecount=0, c=0;
        int len = args[x].size();

        str=args[x].substr(1, len-2);
        // cout<<"without:"<<str<<endl;

        ifstream fp;
        fp.open(args[fi]);
        if (!fp.is_open()){
            cout<<"Cannot found specified file.\n";
            return;
        }
        
        if(ind==2)flag = 1;

        while(getline(fp,line)){
            
            c = substring(line,str,flag);
            //cout<<"\nc: "<<c<<endl;
            if(mulex && c)cout<<args[fi]<<":";
            if(c && ind==0){
                cout<<line<<endl;
            }else if(c && ind==1){
                total += c;
            }else if(c && ind==2){
                cout<<line<<endl;
            }else if(c && ind==3){
                cout<<linecount<<" "<<line<<endl;
            }
            linecount++;
        }
        if(total!=0)cout<<total<<endl;
    }
}

int main(){
    string s;
    getline(cin,s);
    vector<string> vs = getArgs(s);

    if(vs[1][0]!='-')grep(vs,0);
    else if(vs[1][1]=='c')grep(vs,1);
    else if(vs[1][1]=='i')grep(vs,2);
    else if(vs[1][1]=='n')grep(vs,3);
    else cout<<"Command not defined!"<<endl;


  /*  if(vs[0].compare("grep")==0){
        grep(vs,0);
    }else if((vs[0]+vs[1]).compare("grep-c")==0){
        grep(vs,1);
    }else if((vs[0]+vs[1]).compare("grep-i")==0){
        grep(vs,2);
        cout<<"2\n";
    }else if((vs[0]+vs[1]).compare("grep-n")==0){
        grep(vs,3);
    }*/
    return 0;
}