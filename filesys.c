#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include "filesys.h"

int CreateDir(char* dir_name)
{
 return mkdir(dir_name, 0777);
}

int ChangeDir(char* dir_name)
{
 return chdir(dir_name);
}

int CreateFile(char* file_name , int permission)
{
 int fd_file =  creat(file_name, permission);
 if(fd_file ==0)
    fd_file = close(fd_file);
 return fd_file;
}

int AccessDir(char* dir_name)
{
    return access(dir_name, F_OK);
}