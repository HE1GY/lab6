#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include "filesys.h"

int main() {

    if (AccessDir("level1") != 0 && CreateDir("level1") == -1) {
        perror("Error creating directory level1");
        exit(EXIT_FAILURE);
    }

    if (ChangeDir("level1") == -1) {
        perror("Error changing to directory level1");
        exit(EXIT_FAILURE);
    }

    if (AccessDir("level2") != 0 && CreateDir("level2") == -1) {
        perror("Error creating directory level2");
        exit(EXIT_FAILURE);
    }

    if (ChangeDir("level2") == -1) {
        perror("Error changing to directory level2");
        exit(EXIT_FAILURE);
    }

    // -rwsr-xr-x
    if (CreateFile("file1", S_IRWXU | S_ISUID | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1) {
        perror("Error creating file1");
        exit(EXIT_FAILURE);
    }

    // -rwsr-s---
    if (CreateFile("file2", S_IRWXU | S_ISUID | S_IRGRP | S_IXGRP | S_ISGID) == -1) {
        perror("Error creating file2");
        exit(EXIT_FAILURE);
    }

    printf("Directories and files created successfully.\n");

    return 0;
}
