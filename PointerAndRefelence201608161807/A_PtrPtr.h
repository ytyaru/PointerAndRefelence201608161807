#pragma once
#include "B.h"

class A_PtrPtr
{
public:
	explicit A_PtrPtr(B* b);
	~A_PtrPtr(void);
private:
	B* m_b;
};
