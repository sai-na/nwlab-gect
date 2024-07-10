#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define wsize 4
#define nframes 8

int main()
{
    srand(time(0));
    int count = 0, start = 0, completed = 0;

    while (count < nframes)
    {
        completed = 0;
        printf("\nSending frames: ");
        for (int i = start; i < start + wsize && i < nframes; i++)
        {
            printf("%d ", i + 1);
        }
        printf("\n");
    repeat:
        if(count >= nframes){
            break;
        }
        if (rand() % 2 == 0)
        {
            printf("Error in Frame %d. Retransmitting frame..\n", count + 1);
            goto repeat;
        }
        else
        {
            printf("frame %d acknowledged\n", count + 1);
            completed++;
            count++;
            if(completed < wsize){
                goto repeat;
            }
            else{
                start += wsize;
            }
        }
    }
}