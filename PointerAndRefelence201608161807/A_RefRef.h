#pragma once
#include "B.h"

class A_RefRef
{
public:
	explicit A_RefRef(B& b);
	~A_RefRef(void);
private:
	B& m_b; // ‰Šú‰»‚¹‚¸‚ÉéŒ¾‚Å‚«‚éI
};
