#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;;


time_t get_mtime(const char *path)
{
    struct stat statbuf;
    if ( stat(path, &statbuf) == -1 ) {
        perror(path);
        exit(1);
    }
    return statbuf.st_mtime;
}

int main(int argc, char const *argv[])
{
	char *path="/home/shivam/Desktop/a2.txt";
	cout<<"time: "<<get_mtime(path)<<endl;;
	return 0;
}