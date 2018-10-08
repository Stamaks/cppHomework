#include "NiceStack.h"
#include "NiceQueue.h"

int main (int /*argc*/, char* /*argv*/[])
{
	using namespace std;

    NiceStack<int> niceStack(20);

    niceStack.push(10);
    cout << (niceStack.getMinimum() == 10) << endl;

    niceStack.push(5);
    cout << (niceStack.getMinimum() == 5) << endl;
}
