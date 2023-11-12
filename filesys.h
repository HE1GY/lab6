#ifndef FILESYS_H
#define FILESYS_H

int CreateFile(char* file_name, int permission);
int ChangeDir(char* dir_name);
int CreateDir(char* dir_name);
int AccessDir(char* dir_name);

#endif