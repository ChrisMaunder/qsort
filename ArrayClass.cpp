// ArrayClass.cpp: implementation of the CArrayClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CArrayExample.h"
#include "ArrayClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//You could just define a simple C structure, it does not have to be a class.
//If your class inherits from CObject, be sure to provide a copy constructor.
CArrayClass::CArrayClass()
{
	m_wMsgId = -1;
	m_strMsgType = "default";
}

CArrayClass::~CArrayClass()
{

}
