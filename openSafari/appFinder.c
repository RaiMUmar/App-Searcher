#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

void findFile(const char *directory, char fileName [], char filePath []);
void openFile(char filePath []);

int main(int argc, char * argv[]){
    char filePath[1024]; // If 1024 is too small, adjust to your needs
    const char *firstDirectory = "/";

    findFile(firstDirectory, argv[1], filePath);
    printf("\n\nFile found, path: %s\n", filePath);

    openFile(filePath);

    return 0;
}

void findFile(const char *directory, char fileName[], char filePath[]){
    char subDir[1024];
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL){
        return;
    }

    while ((entry = readdir(dp)) != NULL){

        if (entry->d_type == DT_DIR){ // The following folders and files are not opened. Remove any you want to open. 
            if (strcmp(entry->d_name, ".") != 0 
            && (strcmp(entry->d_name, "..")) != 0
            && (strcmp(entry->d_name, "Volumes")) != 0
            && (strcmp(entry->d_name, "Library")) != 0
            && (strcmp(entry->d_name, "System")) != 0
            && (strcmp(entry->d_name, "bin")) != 0
            && (strcmp(entry->d_name, "cores")) != 0
            && (strcmp(entry->d_name, "dev")) != 0
            && (strcmp(entry->d_name, "etc")) != 0
            && (strcmp(entry->d_name, "home")) != 0
            && (strcmp(entry->d_name, "opt")) != 0
            && (strcmp(entry->d_name, "private")) != 0
            && (strcmp(entry->d_name, "sbin")) != 0
            && (strcmp(entry->d_name, "tmp")) != 0
            && (strcmp(entry->d_name, "usr")) != 0
            && (strcmp(entry->d_name, "var")) != 0
            && (strcmp(entry->d_name, "Movies")) != 0
            && (strcmp(entry->d_name, "Library")) != 0
            && (strcmp(entry->d_name, "Music")) != 0
            && (strcmp(entry->d_name, "Pictures")) != 0
            && (strcmp(entry->d_name, "Public")) != 0
            ){
                printf("Current file: %s\n", entry->d_name); // Remove this line if you don't want to clutter your terminal
                if (strcmp(directory, "/") != 0){
                    strcpy(subDir, directory);
                    strcat(subDir, "/");
                    strcat(subDir, entry->d_name);
                } else {
                    strcpy(subDir, directory);
                    strcat(subDir, entry->d_name);
                }

                findFile(subDir, fileName, filePath);
            }
        } else if (strcmp(entry->d_name, fileName) == 0){
            strcpy(filePath, directory);
            strcat(filePath, "/");
            strcat(filePath, entry->d_name);
        }
    }
    closedir(dp);
}

/* This function attempts to executive the file once found, remove it if you don't want to do that */
void openFile(char filePath []){ 
    char command[1024] = "open ";
    strcat(command, filePath);

    if (access(filePath, X_OK) == 0){
        printf("Executing File\n");
        system(command);
    } else {
        printf("File is not executable\n");
    }
}