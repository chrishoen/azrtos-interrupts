/* This is a small demo of the high-performance ThreadX kernel.  It includes examples of eight
   threads of different priorities, using a message queue, semaphore, mutex, event flags group, 
   byte pool, and block pool.  */

#include   <stdio.h>
#include   "ProgramTime.h"
#include   "tx_api.h"

/* choen added this. */
extern BOOL sample_interrupt_start();
#define TICK_SCALE 4

#define     DEMO_STACK_SIZE         1024
#define     DEMO_BYTE_POOL_SIZE     9120
#define     DEMO_BLOCK_POOL_SIZE    100
#define     DEMO_QUEUE_SIZE         100


/* Define the ThreadX object control blocks...  */

TX_THREAD               thread_0;
TX_BYTE_POOL            byte_pool_0;
TX_BLOCK_POOL           block_pool_0;


/* Define the counters used in the demo application...  */

ULONG           thread_0_counter;


/* Define thread prototypes.  */

void    thread_0_entry(ULONG thread_input);

/* Define main entry point.  */

int main()
{
    /* Do this first. */
    initializeProgramTime();
    timeBeginPeriod(1);

    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();
}


/* Define what the initial system looks like.  */

void    tx_application_define(void *first_unused_memory)
{

CHAR    *pointer = TX_NULL;

    /* Create a byte memory pool from which to allocate the thread stacks.  */
    tx_byte_pool_create(&byte_pool_0, "byte pool 0", first_unused_memory, DEMO_BYTE_POOL_SIZE);

    /* Put system definition stuff in here, e.g. thread creates and other assorted
       create information.  */

    /* Allocate the stack for thread 0.  */
    tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, DEMO_STACK_SIZE, TX_NO_WAIT);

    /* Create the main thread.  */
    tx_thread_create(&thread_0, "thread 0", thread_0_entry, 0,  
            pointer, DEMO_STACK_SIZE, 
            1, 1, TX_NO_TIME_SLICE, TX_AUTO_START);

}



/* Define the test threads.  */

void    thread_0_entry(ULONG thread_input)
{   
    double tLastTime = getProgramTime();
    /* This thread simply sits in while-forever-sleep loop.  */
    while(1)
    {
        double tCurrentTime = getProgramTime();
        double tDeltaTime = tCurrentTime - tLastTime;
        tLastTime = tCurrentTime;

        /* Print results.  */
        printf("thread_0 ************* %d %.3f\n",
            thread_0_counter++, tDeltaTime);

        /* Sleep for 100 ticks.  */
        tx_thread_sleep(100);
    }
}
