#include <tchar.h>   // _T, _tprintf
#include <windows.h> // OutputDebugString
#include <stdlib.h>	// system()
#include <iostream>  // cout
#include <sstream>  // cout
#include <string>  // cout
#include <memory>	// smart pointer
#include "B.h"
#include "A_ValVal.h"
#include "A_RefRef.h"
#include "A_PtrPtr.h"

typedef std::basic_stringstream<TCHAR> tstringstream;
typedef std::basic_ostringstream<TCHAR> tostringstream;
typedef std::basic_istringstream<TCHAR> tistringstream;
#if defined(_UNICODE) || defined(UNICODE)
#  define tcout std::wcout
#else
#  define tcout std::cout
#endif

void g_fncPrmVal(int i);
void g_fncPrmRef(int& r);
void g_fncPrmPtr(int* p);

//int g_fncRetVal();
//int& g_fncRetRef();
//int* g_fncRetPtr();

int _tmain(int argc, _TCHAR* argv[])
{
	// -------------------------
	// ローカル変数 編
	// -------------------------
	int i = 100;
	int& r = i;		// 初期化でほかの変数を代入する必要がある。
	int* p = &i;	// NULLも代入できる

	tstringstream stream;
	stream << _T("> int i = 100;") << std::endl
		<< _T("> int& r = i;") << std::endl
		<< _T("> int* p = &i;") << std::endl
		<< _T("i = ") << i << std::endl
		<< _T("&i = ") << &i << std::endl
		<< _T("r = ") << r << std::endl
		<< _T("&r = ") << &r << std::endl
		<< _T("*p = ") << *p << std::endl
		<< _T("p = ") << p << std::endl
		;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());
	
	// -------------------------
	// グローバル関数 編
	// -------------------------
	//stream << _T("> g_fncPrmVal(i);") << std::endl;
	tcout << _T(">> g_fncPrmVal(i);") << std::endl;
	OutputDebugString(_T(">> g_fncPrmVal(i);\n"));
	g_fncPrmVal(i);
	stream.str(_T(""));
	stream.clear(std::stringstream::goodbit);
	stream << _T(">> i = ") << i << std::endl;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());
	
	tcout << _T(">> g_fncPrmRef(i);") << std::endl;
	OutputDebugString(_T(">> g_fncPrmRef(i);\n"));
	g_fncPrmRef(i);
	stream.str(_T(""));
	stream.clear(std::stringstream::goodbit);
	stream << _T(">> i = ") << i << std::endl;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());
	
	tcout << _T(">> g_fncPrmPtr(&i);") << std::endl;
	OutputDebugString(_T(">> g_fncPrmPtr(&i);\n"));
	g_fncPrmPtr(&i);
	stream.str(_T(""));
	stream.clear(std::stringstream::goodbit);
	stream << _T(">> i = ") << i << std::endl;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());

	i = 0;
	tcout << _T("> i = 0;") << std::endl;
	tcout << _T(">> g_fncPrmPtr(p);") << std::endl;
	OutputDebugString(_T("> i = 0;\n"));
	OutputDebugString(_T(">> g_fncPrmPtr(p);\n"));
	g_fncPrmPtr(p);
	stream.str(_T(""));
	stream.clear(std::stringstream::goodbit);
	stream << _T(">> *p = ") << *p << std::endl;
	stream << _T(">> p = ") << p << std::endl;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());
	
	// -------------------------
	// class 編
	// -------------------------
	B b;
	tcout << _T("> B b;") << std::endl;
	tcout << _T("&b = ") << &b << std::endl;
	tcout << _T("> A_ValVal avv(b);") << std::endl;
	A_ValVal avv(b);
	tcout << _T("> A_RefRef arr(b);") << std::endl;
	A_RefRef arr(b);
	tcout << _T("> A_PtrPtr app(&b);") << std::endl;
	A_PtrPtr app(&b);

	system("pause");
}

void g_fncPrmVal(int i)
{
	tstringstream stream;
	//i = 111;
	stream << _T("void g_fncPrmVal(int i)---------------") << std::endl
		//<< _T("> i = 111;") << std::endl
		<< _T("i = ") << i << std::endl
		<< _T("&i = ") << &i << std::endl
		;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());
	
	i = 123;
	stream.str(_T(""));
	stream.clear(std::stringstream::goodbit);
	stream << _T("> i = 123;") << std::endl
		<< _T("i = ") << i << std::endl
		<< _T("&i = ") << &i << std::endl
		<< _T("---------------") << std::endl
	;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());
}
void g_fncPrmRef(int& r)
{
	tstringstream stream;
	stream << _T("void g_fncPrmRef(int& r)---------------") << std::endl
		<< _T("r = ") << r << std::endl
		<< _T("&r = ") << &r << std::endl
		;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());

	r = 234;
	stream.str(_T(""));
	stream.clear(std::stringstream::goodbit);
	stream << _T("> r = 234;") << std::endl
		<< _T("r = ") << r << std::endl
		<< _T("&r = ") << &r << std::endl
		<< _T("---------------") << std::endl
	;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());
}
void g_fncPrmPtr(int* p)
{
	tstringstream stream;
	stream << _T("void g_fncPrmPtr(int* p)---------------") << std::endl
		<< _T("*p = ") << *p << std::endl
		<< _T("p = ") << p << std::endl
		;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());
	
	*p = 345;
	stream.str(_T(""));
	stream.clear(std::stringstream::goodbit);
	stream << _T("> *p = 345;") << std::endl
		<< _T("*p = ") << *p << std::endl
		<< _T("p = ") << p << std::endl
		<< _T("---------------") << std::endl
	;
	tcout << stream.str();
	OutputDebugString(stream.str().c_str());
}

//int g_fncRetVal()
//{
//	int i;
//	return i;
//}
//int& g_fncRetRef()
//{
//	int i;
//	return i;
//}
//int* g_fncRetPtr()
//{
//	int* i = 0;
//	return i;
//}
//
