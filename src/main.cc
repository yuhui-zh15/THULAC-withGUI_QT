#include <iostream>
#include <cstdio>
#include "thulac.h"
using namespace std;

int main()
{
	THULAC *thc = new THULAC();
	thc->IOtoTHULAC("models/", false, false, false, false, '_');
	return 0;
}