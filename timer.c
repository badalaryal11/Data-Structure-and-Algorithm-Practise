/* stopwatch_timer.c */
#include<pthread.h>
#include<time.h>
#include<stdio.h> 
//#include<stopwatch_timer.h>
 
/* prototypes */
int* g_start_timer(void *secs);
 
static clock_t _current_time = 0;
 
/* create the thread */
void start_timer(int seconds)
{
    pthread_t thread_id;
    int rc = 0;
 
    rc = pthread_create(&thread_id, NULL, g_start_timer, (void*) seconds);
 
    if(rc)
    {
    printf("=== Error Creating thread\n");
    }
}
 
/* start the timing in another thread */
int* g_start_timer(void *secs)
{
    printf("Starting thread\n");
    int seconds = (int) secs;
    printf("g_start_timer: %d\n", (int) seconds);
   
  _current_time = clock() + seconds * CLOCKS_PER_SEC;
 
    /* loop until the 10 seconds has reached */
    while(clock() < _current_time){}
 
    pthread_exit(NULL);
}
 
/* get the current time of work */
int current_time()
{
    return (int) _current_time / CLOCKS_PER_SEC;
}
