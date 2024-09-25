# Using qsort on arrays of sequential data

An introduction to a useful function



<!-- Article Starts -->

## Introduction

`qsort` is part of the C and C++ language.  It is a quick sort algorithm that 
is both fast and easy to implement.  It is a recursive algorithm, but it is 
surprising fast.  (30,000 items in about a fourth of a second on a PII-333 
machine.)

This 'How To' demonstrates the use of `qsort` on a `CArray`.  
However, it would work just as well on any other sequential data structure.  Static arrays, 
`CStringArray`, `CPtrArray` or something of your own creation.

The demo project is written in VC 5.0.  It has not been plagiarized from any other 
source.  There are no restrictions on the source.

## Sorting

Suppose you wanted to store and sort number of items of type `CArrayClass`, 
defined as follows:

```cpp
class CArrayClass  
{
public:
  CArrayClass();
  virtual ~CArrayClass();
  
  WORD    m_wMsgId;
  CString m_strMsgType;
};
```

Using the `CArray` template class we can store the `CArrayClass`
objects using the following array declaration

```cpp
typedef CArray<CArrayClass, CArrayClass&> Type_aCArrayClass;
Type_aCArrayClass m_aCArrayClass;
```

To use `qsort` you need to declare a callback function whose
address is known at compile time - meaning it must either be a global or
static function. The `qsort` callback function must be defined
as:

```cpp
int (__cdecl *compare )(const void *elem1, const void *elem2 )
```

Items *elem1* and *elem2* are pointers to two items in the
array, and must be cast to the appropriate type and compared. The return
value of the function is as follows:

| **Return Value** | **Description** |
| --- |:--- |
| &lt; 0 | *elem1* less than *elem2* |
| 0 | *elem1* equivalent to *elem2* |
| &gt; 0 | *elem1* greater than *elem2* |

In our case the callback function would look like the following:

```cpp
// This function can be global or it can be a static member of your class,
// but it's address must be know at compile time.
int CCArrayExampleDlg::SortTheArray(void* p1,void* p2)
{
  short n=0;
  CArrayClass* a1 = (CArrayClass*)p1;
  CArrayClass* a2 =  (CArrayClass*)p2; // If we were sorting a CPtrArray then we 
                                       // would have to do a second level 
                                       // of casting to get to the data keys that we 
                                       // would be sorting.
  
  if (a1->m_strMsgType  <a2->m_strMsgType)    //Ascending
      n = -1; 
  elseif (a1->m_strMsgType  >a2->m_strMsgType)
      n = 1; 
  elseif(a1->m_wMsgId  <a2->m_wMsgId)    //Ascending
      n = -1; 
  elseif(a1->m_wMsgId  >a2->m_wMsgId)
      n = 1;
  
  return n;
}
```

To use this sort callback we need to fill the array, call `qsort`
and then display the results.

```cpp
void CCArrayExampleDlg::OnSort() 
{ 
  // Fill the array m_aCArrayClass with items of type CArrayClass 
  ...
  
  // Sort the array 
  if(m_aCArrayClass.GetSize() >  0) 
  {
      qsort((void*)&m_aCArrayClass[0],
            (size_t)m_aCArrayClass.GetSize(), 
            sizeof(CArrayClass),
            (int(*)(const void*, const void*))CCArrayExampleDlg::SortTheArray);
  }
  
  // Display the newly sorted array
  ...
}
```
