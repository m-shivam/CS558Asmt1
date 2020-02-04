#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
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

time_t get_mtime(string path)
{
    struct stat statbuf;
    if ( stat(path.c_str(), &statbuf) == -1 ) {
        return -1;
    }
    return statbuf.st_mtime;
}

string getfilename(string topath){
    string tmp;
    tmp = topath.substr(topath.find_last_of('\//') + 1);
    cout<<"file to be copied: *"<<tmp<<"*"<<endl;
    return tmp;
}

int copy(vector<string> args, bool updateflag=false){
    string from, to, tmp;
    int toind, fromind, veclen = args.size(), iter=1;
    to = args[veclen-1];
    if(args[1]=="-u")iter=2;
 
    for (; iter < veclen-1; ++iter)
    {

        from = args[iter];

        if(to[to.length()-1]=='/')to=to+getfilename(from);
        else to=to+"/"+getfilename(from);

        cout<<"from: *"<<from<<"*\nto: *"<<to<<"*"<<endl;

        if(updateflag && (get_mtime(to)!=-1) && get_mtime(to)>get_mtime(from) ){
            //cout<<"to: "<<get_mtime(to)<<"\nfrom:"<<get_mtime(from)<<endl;
            cout<<"option -u condition violated!\n";
            return 1;
        }

        ifstream in{from};
        remove(const_cast<char*>(to.c_str()));
        ofstream out{to};
        if (!out) {
            cerr << "Could not copy file to " << to << '\n';
            return 1;
        }
        static constexpr size_t buffsize{1024};
        char buffer[buffsize];
        while (in.read(buffer, buffsize)) {
            out.write(buffer, buffsize);
        }
        out.write(buffer, in.gcount());
        to = args[veclen-1];
    }
     

return 0;
}

int main() {
    string from, to, tmp, cmd;
    int toind, fromind;
    vector<string> v;
    getline(cin, cmd);
    v = getArgs(cmd);
    cout<<"*"<<cmd<<"*"<<endl;
    if(v[1]=="-u")copy(v, true);
    else copy(v);


    return 0;
}