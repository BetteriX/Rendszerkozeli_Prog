#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#if defined(linux) || defined(_linux) || defined(__linux__) || defined(__unix__)
#define O_BINARY 0
#endif
#if defined(_WIN32) || defined(_WINDOWS) || defined(__WINDOWS__)
#define S_IRGRP 0
#define S_IROTH 0
#endif

int WrapFile(char *argv[])
{
    int inpic, intxt, outpic;
    int i, Tsize, Psize;
    short BD;
    unsigned char *buffer, *text, *ptr;
    struct stat inode;

    // File to Wrap
    intxt = open(argv[2], O_RDONLY | O_BINARY);
    if (intxt < 0)
    {
        fprintf(stderr, "Input file opening error.\n");
        return 11;
    }
    stat(argv[2], &inode);
    Tsize = inode.st_size;
    text = (unsigned char *)malloc(Tsize);
    read(intxt, text, Tsize);
    close(intxt);

    // Image file
    inpic = open(argv[1], O_RDONLY | O_BINARY);
    if (inpic < 0)
    {
        fprintf(stderr, "Input image file opening error.\n");
        return 12;
    }
    stat(argv[1], &inode);
    Psize = inode.st_size;
    buffer = (unsigned char *)malloc(Psize);
    read(inpic, buffer, Psize);
    close(inpic);

    BD = *((short *)(buffer + 28));
    if ((buffer[0] != 'B' && buffer[1] != 'M') || BD != 24)
    {
        fprintf(stderr, "Not TrueColor BMP image.\n");
        return 13;
    }
    if (3 * Tsize > Psize - 54)
    {
        fprintf(stderr, "Too small image.\n");
        return 14;
    }

    // New image for wrapped text
    outpic = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (outpic < 0)
    {
        fprintf(stderr, "Output image opening error.\n");
        return 15;
    }

    // Encoding characters into pixels
    ptr = buffer + 42;
    *((int *)ptr) = Tsize;
    ptr = buffer + 54;
    for (i = 0; i < Tsize; i++)
    {
        ptr[3 * i] = (ptr[3 * i] & 0xfc) | ((text[i] >> 6) & 0x03);
        ptr[3 * i + 1] = (ptr[3 * i + 1] & 0xf8) | ((text[i] >> 3) & 0x07);
        ptr[3 * i + 2] = (ptr[3 * i + 2] & 0xf8) | ((text[i]) & 0x07);
    }

    write(outpic, buffer, Psize);
    close(outpic);
    free(buffer);
    free(text);
    printf("Encoding is ready.\n");
    return 0;
}

int UnfoldFile(char *argv[])
{
    int inpic, outtxt, outpic;
    int i, Tsize, Psize;
    short BD;
    unsigned char *buffer, *text, *ptr;
    struct stat inode;

    inpic = open(argv[1], O_RDONLY | O_BINARY);
    if (inpic < 0)
    {
        fprintf(stderr, "Input image file opening error.\n");
        return 21;
    }

    stat(argv[1], &inode);
    Psize = inode.st_size;
    buffer = (unsigned char *)malloc(Psize);
    read(inpic, buffer, Psize);
    close(inpic);
    BD = *((short *)(buffer + 28));
    if ((buffer[0] != 'B' && buffer[1] != 'M') || BD != 24)
    {
        fprintf(stderr, "Not TrueColor BMP image.\n");
        return 22;
    }

    outtxt = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, S_IRUSR | S_IWUSR);
    if (outtxt < 0)
    {
        fprintf(stderr, "Output file opening file error.\n");
        return 23;
    }

    ptr = buffer + 42;
    *((int *)ptr) = Tsize;
    text = (unsigned char *)malloc(Tsize);
    ptr = buffer + *((int *)(buffer + 10));
    for (i = 0; i < Tsize; i++)
    {
        text[i] = ((ptr[3 * i] & 0x03) << 6 | ((ptr[3 * i + 1] & 0x07) << 3) | (ptr[3 * i + 2] & 0x07));
    }

    write(outtxt, text, Tsize);
    close(outtxt);
    free(buffer);
    free(text);
    printf("Decoding is ready");
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        return WrapFile(argv);
    }
    if (argc == 3)
    {
        return UnfoldFile(argv);
    }
    fprintf(stderr, "Encoding:\n %s <pure_bmp_file> <file_to_wrap> <coded_bmp_file>\n", argv[0]);
    fprintf(stderr, "Decoding:\n %s <coded_bmp_file> <unfolded_file>\n", argv[0]);
}