#include "A_RefRef.h"
#include <stdio.h>

A_RefRef::A_RefRef(B& b) : m_b(b)
{
	printf("A_RefRef::A_RefRef(B& b)----------\n");
	printf("> b.value = %d\n", b.value);
	printf("> &b = %X\n", &b);
}


A_RefRef::~A_RefRef(void)
{
}
