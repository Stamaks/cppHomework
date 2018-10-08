#include "NiceStack.h"
#include "NiceQueue.h"

int main (int /*argc*/, char* /*argv*/[])
{
	using namespace std;

    NiceQueue<int> niceQueue(20);

    niceQueue.enq(10);
    niceQueue.getMinimum();

    niceQueue.enq(5);
    niceQueue.getMinimum();
}
