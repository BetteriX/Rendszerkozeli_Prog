#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <unistd.h>
#include <dirent.h>

int main(){
    DIR *d;
    struct dirent *entry;
    struct stat inode;
    d = opendir(".");

    int tmp = 0;
    int count = 0;
    while((entry = readdir(d))!= NULL){
        tmp = stat((*entry).d_name,&inode);

        if(inode.st_mode&__S_IFREG){
            if(inode.st_size > 1024){
                count++;
            }

        }
    }

    printf("A fajlok, amelyek 1kB-nal nagyobbak: %d\n",count);

    closedir(d);
    return 0;
}