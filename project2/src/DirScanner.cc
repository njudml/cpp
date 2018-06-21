#include "DirScanner.h"
#include <string.h>
DirScanner::DirScanner(const string& dir)
{
    DIR* mydir;
    struct dirent* ptr;
    char base[200];
    if((mydir=opendir(dir.c_str()))==NULL)
    {
    
        perror("Open dir error");
        exit(1);
    }
    while((ptr=readdir(mydir))!=NULL)
    {
        if(strcmp(ptr->d_name,".")==0||strcmp(ptr->d_name,"..")==0)
            continue;
        else{
            bzero(base,sizeof(base));
            sprintf(base,"%s/%s",dir.c_str(),ptr->d_name);
            _vecFilesfiles.insert(base);
        }
    }
    closedir(mydir);
}
