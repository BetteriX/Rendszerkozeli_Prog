#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>
#include <string.h>

int numFiles = 0;
int numDirs = 0;

typedef struct node
{
    long int data;
    struct node *large;
    struct node *small;
} Node;
Node *root = NULL;

int Insert(Node **N, long int data)
{
    if ((*N) == NULL)
    {
        (*N) = (Node *)malloc(sizeof(Node));
        (**N).large = NULL;
        (**N).small = NULL;
        (**N).data = data;
        return 1;
    }

    if ((**N).data = data)
    {
        return 0;
    }

    if ((**N).data < data)
    {
        return Insert(&((**N).large), data);
    }
    else
    {
        return Insert(&((**N).small), data);
    }
}

long int dirTree(char *dirname, int level)
{
    int i;
    long int size = 0l;
    DIR *d;
    struct dirent *de;
    struct stat inode;
    chdir(dirname);
    d = opendir(".");
    while ((de = readdir(d)) != NULL)
    {
        if (strcmp((*de).d_name, ".") == 0 || strcmp(((*de).d_name), "..") == 0)
        {
            continue;
        }
        if (stat((*de).d_name, &inode) < 0)
        {
            continue;
        }
        if (Insert(&root, inode.st_ino) == 0)
        {
            continue;
        }
        for (int i = 0; i < level; i++)
        {
            printf("  ");
        }
        if ((inode.st_mode & S_IFMT) == S_IFDIR)
        {
            printf("+ %s (%ld)\n", (*de).d_name, inode.st_size);
            numDirs++;
            size += dirTree((*de).d_name, level + 1);
        }
        else
        {
            printf("- %s (%ld)\n", (*de).d_name, inode.st_size);
            numFiles++;
        }
        size += inode.st_size;
    }
    closedir(d);
    chdir("..");
    return size;
}
int main(int argc, char *argv[])
{
    long int size;
    if (argc > 1)
    {
        chdir(argv[1]);
    }
    printf("Tree of \'%s\' directory:\n", getenv("PWD"));
    size = dirTree(".", 1);
    printf("Total size: %ld bytes.\n", size);
    printf("Number of Files: %d\n", numFiles);
    printf("Number of Directories: %d\n", numDirs);
    return 0;
}