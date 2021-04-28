Max Franz
11/3/20
smallsh

My code acts strange, it will either do 1 of 2 things.

The first thing it may do is print "Terminated by signal 'x'" on every other line while also completing the testing script.

The second thing it may do is perform the last half of the testing script twice. It will just repeat starting around the
": pkill -signal SIGTERM sleep (10 points for pid of killed process, 10 points for signal)" phase of the script.

I couldn't figure out how to fix this.


To compile my code, type 'make'. 
