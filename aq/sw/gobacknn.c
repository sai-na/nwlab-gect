#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define wsize 4
#define nframes 8

int main()
{
    srand(time(0));
    int count = 0, start = 0;

    while (count < nframes)
    {
        printf("\nSending frames: ");
        for (int i = start; i < start + wsize && i < nframes; i++)
        {
            printf("%d ", i + 1);
        }
        printf("\n");
        if (rand() % 2 == 0)
        {
            printf("Error in Frame %d. Retransmitting window..\n", count + 1);
        }
        else
        {
            printf("frame %d acknowledged\n", count + 1);
            count++;
            start++;
        }
    }
}

// output

// Sending frames: 1 2 3 4
// frame 1 acknowledged

// Sending frames: 2 3 4 5
// Error in Frame 2. Retransmitting window..

// Sending frames: 2 3 4 5
// frame 2 acknowledged

// Sending frames: 3 4 5 6
// Error in Frame 3. Retransmitting window..

// Sending frames: 3 4 5 6
// frame 3 acknowledged

// Sending frames: 4 5 6 7
// Error in Frame 4. Retransmitting window..

// Sending frames: 4 5 6 7
// frame 4 acknowledged

// Sending frames: 5 6 7 8
// Error in Frame 5. Retransmitting window..

// Sending frames: 5 6 7 8
// Error in Frame 5. Retransmitting window..

// Sending frames: 5 6 7 8
// frame 5 acknowledged

// Sending frames: 6 7 8
// frame 6 acknowledged

// Sending frames: 7 8
// Error in Frame 7. Retransmitting window..

// Sending frames: 7 8
// frame 7 acknowledged

// Sending frames: 8
// frame 8 acknowledged