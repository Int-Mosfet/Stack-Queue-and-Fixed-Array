# Stack-Queue-and-Fixed-Array
Custom templated stack, queue, and fixed array classes using aggregation and inheritance from a base array class.</br>

This was a class assignment (my favorite of the semester), I can still clean this up a bit more (I just published this to motivate me to clean it up :) ).  What I want to add is more try-catch blocks wherever possible and to clean up my driver file with cleaning tests.  No timeframe on when I do this, most likely when I'm free or feel like it.  It is very fun and relaxing implementing basic and fundamental data structures.

I don't aim for ultra performance with my designs, I aimed for tight memory usage and to cleanse memory when it was done being used (for security concerns).  Generally instead of moving a pointer and not cleaning memory, I would pop off an element and then shift everything, then wipe that memory and shrink the size of the data structure.

You can use MPC to create a makefile for the project, I may push a pre-made makefile eventually.
