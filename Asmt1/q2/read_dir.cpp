#include <iostream>
#include<dirent.h>
#include<string.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

char path[256];

int ls(bool hid=true){
	DIR *dirptr=NULL;
	struct dirent* dirdata;
	//char path[]="/home/shivam/College/Sem2/HPC/";
	getcwd(path, 256);
	struct stat isfolder;
	dirptr = opendir(path);
	

	if(dirptr == NULL){
		cout<<"Cannot open specified dir";
		return 1;
	}
	while(dirdata = readdir(dirptr)){
		if(strcmp(dirdata->d_name, ".") && strcmp(dirdata->d_name, "..")){
			if(dirdata->d_name[0]=='.' && hid)continue;
			stat(dirdata->d_name,&isfolder);
			if(S_ISDIR(isfolder.st_mode))cout<<"\'"<<dirdata->d_name<<"\'"<<endl;
			else cout<<dirdata->d_name<<endl;
		}
	}
	closedir(dirptr);
	return 0;
}

int main(int argc, char const *argv[])
{
	ls(false);

	return 0;
}