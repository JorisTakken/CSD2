#include "Stopwatch.h"


Stopwatch sw;


int main(){
// Record start  time
    sw.Start();

    // Portion of code to be timed
    ...

    // Record end time
    sw.Stop();

    std::cout << "Elapsed time: " << sw.ElapsedMilliseconds() << " ms\n";
}
