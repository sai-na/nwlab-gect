#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define bsize 100 //Bucket Size
#define out 20 //Output rate

int main()
{
    srand(time(NULL));
    int n, rem = bsize, used = 0;
    printf("Enter no of packets: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int size = rand() % 10 * 10; // random packet size (multiple of 10, below 100)
        printf("\n\nPacket %d size = %d\n", i + 1, size);

        if (size > rem)
        {
            printf("%d bytes discarded!!\n", size - rem);
            size = rem;
        }

        used += size;
        rem -= size;
        printf("\nBEFORE TRANSMISSION\n");
        printf("Bytes used from bucket = %d\n", used);
        printf("Bytes remaining in bucket = %d\n", rem);

        used -= out;
        rem += out;
        printf("\nAFTER TRANSMISSION\n");
        printf("Bytes used from bucket = %d\n", used);
        printf("Bytes remaining in bucket = %d\n", rem);
    }
}
