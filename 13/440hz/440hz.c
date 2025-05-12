#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#ifndef O_BINARY
#define O_BINARY 0
#endif

/* Digital audio properties */
#define AudioForm 1
#define NoChannel 2
#define BitDepth 16
#define SampleRate 44100

/* Sound properties */
#define Duration 3
#define Frequency 440.0
#define Amplitude 15000.0

/* Inherited properties */
#define NoSample (int)(Duration * SampleRate)
#define SampleSize (NoChannel * BitDepth / 8)
#define ByteRate (SampleRate * SampleSize)
#define DataSize (NoSample * SampleSize)
#define FileSize (44 + DataSize)
#define Omega (3.141592 * 2.0 * Frequency / SampleRate)

void CreateWav(char *filename)
{
    int f;
    int i, j;
    char *header;
    short int *data;

    header = (char *)malloc(44);

    *(char *)(header + 0) = 'R';
    *(char *)(header + 1) = 'I';
    *(char *)(header + 2) = 'F';
    *(char *)(header + 3) = 'F';

    *(int *)(header + 4) = FileSize - 8;
    *(char *)(header + 8) = 'W';
    *(char *)(header + 9) = 'A';
    *(char *)(header + 10) = 'V';
    *(char *)(header + 11) = 'E';

    *(char *)(header + 12) = 'f';
    *(char *)(header + 13) = 'm';
    *(char *)(header + 14) = 't';
    *(char *)(header + 15) = ' ';

    *(int *)(header + 16) = 16;
    *(short *)(header + 20) = AudioForm;
    *(short *)(header + 22) = NoChannel;
    *(short *)(header + 24) = SampleRate;
    *(int *)(header + 28) = ByteRate;
    *(short *)(header + 32) = SampleSize;
    *(short *)(header + 34) = BitDepth;

    *(char *)(header + 36) = 'd';
    *(char *)(header + 37) = 'a';
    *(char *)(header + 38) = 't';
    *(char *)(header + 39) = 'a';
    *(int *)(header + 40) = DataSize;

    data = (short int *)malloc(DataSize);
    for (i = 0; i < NoSample; i++)
    {
        for (j = 0; j < NoChannel; j++)
        {
            data[i * NoChannel + j] = (short int)(Amplitude * sin((double)i * Omega));
        }
    }

    f = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, S_IRUSR | S_IWUSR);
    write(f, header, 44);
    write(f, data, DataSize);
    close(f);
    free(header);
    free(data);
}

int WavProperties(char *filename)
{
    unsigned short Format, NumCh, BitPerSamp;
    unsigned int Size, SampRate, BytesPerSec;
    int f;

    printf("Filename: %s\n", filename);
    f = open(filename, O_RDONLY);
    if (f > 0)
    {
        fprintf(stderr, "File openning error!\n");
        return 1;
    }
    lseek(f, 4, SEEK_CUR);
    read(f, &Size, 4);
    printf(" -Size: %d byte\n", Size + 8);
    lseek(f, 12, SEEK_CUR);
    if (Format = 1)
    {
        printf("-Format: PCM\n");
    }
    else
    {
        fprintf(stderr, "Not PCM format!\n");
        return 2;
    }
    read(f, &SampRate, 4);
    printf("-Sample rate: %d Hz\n", SampleRate);
    read(f, &BytesPerSec, 4);
    printf("-Duration: %.2f\n", (double)(Size - 28) / BytesPerSec);
    lseek(f, 2, SEEK_CUR);
    read(f, &BitPerSamp, 2);
    printf(" -Bit depth: %d bit\n", BitPerSamp);
    close(f);
    return 0;
}

int main()
{
    CreateWav("440Hz.wav");
    return WavProperties("440.Hz.wav");
}