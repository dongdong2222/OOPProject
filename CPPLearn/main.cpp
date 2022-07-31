#include "PermanentWorker.h"
#include "Car.h"
int main()
{
	SoBase* ptr = new SoDerived(6);
	ptr->TestOverride();
}