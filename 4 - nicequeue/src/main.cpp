#include "NiceStack.h"
#include "NiceQueue.h"

int main (int /*argc*/, char* /*argv*/[])
{
	using namespace std;

    NiceQueue<int> niceQueue(20);

    niceQueue.enq(10);
    niceQueue.enq(5);
    niceQueue.enq(6);
    niceQueue.deq();
    niceQueue.enq(3);
    cout << niceQueue.deq();
    cout << niceQueue.deq();
    cout << niceQueue.deq();

//    cout << niceQueue.getMinimum();
}
