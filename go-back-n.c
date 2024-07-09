

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_FRAMES 15

int main()
{
    srand(time(0)); // Seed the random number generator

    int wsize, nframes, nerrors;

    printf("Enter window size: ");
    scanf("%d", &wsize);

    printf("Enter the number of frames to transmit (max %d): ", MAX_FRAMES);
    scanf("%d", &nframes);
    if (nframes > MAX_FRAMES)
    {
        nframes = MAX_FRAMES;
        printf("nframes limited to: %d\n", nframes);
    }

    int error[nframes];
    int count = 0, start = 0;
    nerrors = rand() % 3 + 2; // Random number of errors (2-4)

    // Initialize the error array with 0s
    for (int i = 0; i < nframes; i++)
    {
        error[i] = 0;
    }

    // Introduce errors randomly
    for (int i = 0; i < nerrors; i++)
    {
        int e = rand() % nframes; // Choose a random frame for error
        error[e] = 1;
    }

    printf("\nError pattern: ");
    for (int i = 0; i < nframes; i++)
    {
        printf("%d ", error[i]);
    }
    printf("\n");
    // Simulate the sliding window protocol
    while (count < nframes)
    {
        printf("\nSending frames: ");
        for (int i = start; i < start + wsize && i < nframes; i++)
        {
            printf("%d ", i + 1);
        }
        printf("\n");

        // Check for errors in the current window
        for (int i = start; i < start + wsize && i < nframes; i++)
        {
            if (error[i])
            {
                printf("Error in frame %d, retransmitting window\n", i + 1);
                error[i] = 0;  // Reset the error flag after retransmission
                start = count; // Move the window back to the frame with the error
                break;         // Exit the inner loop
            }
        }

        count++; // Move to the next frame
        if (!error[count - 1])
        {                  // If the previous frame was successfully sent
            start = count; // Slide the window forward
        }
    }
}
