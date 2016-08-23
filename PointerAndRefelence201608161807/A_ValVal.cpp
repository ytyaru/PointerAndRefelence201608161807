#include "A_ValVal.h"
#include <stdio.h>


A_ValVal::A_ValVal(B b) : m_b(b)
{
	printf("A_ValVal::A_ValVal(B b)----------\n");
	printf("> b.value = %d\n", b.value);
	printf("> &b = %X\n", &b);
}


A_ValVal::~A_ValVal(void)
{
}
