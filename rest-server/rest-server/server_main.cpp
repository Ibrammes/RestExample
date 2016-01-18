#include <iostream>
#include "MyListener.h"


int main()
{
	MyListener listener(L"http://localhost:8080/restdemo");  
	listener.start();

	getchar();
	return 0;
}