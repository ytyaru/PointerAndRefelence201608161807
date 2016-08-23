#include "A_PtrPtr.h"
#include <windows.h> // OutputDebugString
#include <iostream>  // cout
#include <sstream>  // cout
#include <string>  // cout
#include <stdio.h>

A_PtrPtr::A_PtrPtr(B* b) : m_b(b)
{
	printf("A_PtrPtr::A_PtrPtr(B* b)----------\n");
	printf("> b->value = %d\n", b->value);
	printf("> b = %X\n", b);
}


A_PtrPtr::~A_PtrPtr(void)
{
}
