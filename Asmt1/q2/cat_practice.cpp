#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int cat(char path[], bool show_lines=false){
	int lines=0;
	ifstream fp;
	string text;
	fp.open(path);
	if (!fp.is_open()){
		cout<<"Cannot found specified file.\n";
		return 0;
	}

	if(show_lines)while(getline(fp, text))cout<<setfill(' ')<<setw(6)<<++lines<<" "<<text<<endl;
	else while(getline(fp, text))cout<<text<<endl;
	return 0;
}

int main(int argc, char const *argv[])
{
	char pa[] = "/home/shivam/College/Sem2/HPC/code\ files/gproftest.c";
	cat(pa, true);
	return 0;
}
