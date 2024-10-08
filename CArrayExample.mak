# Microsoft Developer Studio Generated NMAKE File, Based on CArrayExample.dsp
!IF "$(CFG)" == ""
CFG=CArrayExample - Win32 Debug
!MESSAGE No configuration specified. Defaulting to CArrayExample - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CArrayExample - Win32 Release" && "$(CFG)" !=\
 "CArrayExample - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CArrayExample.mak" CFG="CArrayExample - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CArrayExample - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CArrayExample - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CArrayExample - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\CArrayExample.exe"

!ELSE 

ALL : "$(OUTDIR)\CArrayExample.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ArrayClass.obj"
	-@erase "$(INTDIR)\CArrayExample.obj"
	-@erase "$(INTDIR)\CArrayExample.pch"
	-@erase "$(INTDIR)\CArrayExample.res"
	-@erase "$(INTDIR)\CArrayExampleDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\CArrayExample.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\CArrayExample.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CArrayExample.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CArrayExample.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\CArrayExample.pdb" /machine:I386\
 /out:"$(OUTDIR)\CArrayExample.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ArrayClass.obj" \
	"$(INTDIR)\CArrayExample.obj" \
	"$(INTDIR)\CArrayExample.res" \
	"$(INTDIR)\CArrayExampleDlg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CArrayExample.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CArrayExample - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\CArrayExample.exe"

!ELSE 

ALL : "$(OUTDIR)\CArrayExample.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ArrayClass.obj"
	-@erase "$(INTDIR)\CArrayExample.obj"
	-@erase "$(INTDIR)\CArrayExample.pch"
	-@erase "$(INTDIR)\CArrayExample.res"
	-@erase "$(INTDIR)\CArrayExampleDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\CArrayExample.exe"
	-@erase "$(OUTDIR)\CArrayExample.ilk"
	-@erase "$(OUTDIR)\CArrayExample.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /Fp"$(INTDIR)\CArrayExample.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CArrayExample.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CArrayExample.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\CArrayExample.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\CArrayExample.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ArrayClass.obj" \
	"$(INTDIR)\CArrayExample.obj" \
	"$(INTDIR)\CArrayExample.res" \
	"$(INTDIR)\CArrayExampleDlg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CArrayExample.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "CArrayExample - Win32 Release" || "$(CFG)" ==\
 "CArrayExample - Win32 Debug"
SOURCE=.\ArrayClass.cpp

!IF  "$(CFG)" == "CArrayExample - Win32 Release"

DEP_CPP_ARRAY=\
	".\ArrayClass.h"\
	".\CArrayExample.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ArrayClass.obj" : $(SOURCE) $(DEP_CPP_ARRAY) "$(INTDIR)"\
 "$(INTDIR)\CArrayExample.pch"


!ELSEIF  "$(CFG)" == "CArrayExample - Win32 Debug"

DEP_CPP_ARRAY=\
	".\ArrayClass.h"\
	".\CArrayExample.h"\
	

"$(INTDIR)\ArrayClass.obj" : $(SOURCE) $(DEP_CPP_ARRAY) "$(INTDIR)"\
 "$(INTDIR)\CArrayExample.pch"


!ENDIF 

SOURCE=.\CArrayExample.cpp

!IF  "$(CFG)" == "CArrayExample - Win32 Release"

DEP_CPP_CARRA=\
	".\ArrayClass.h"\
	".\CArrayExample.h"\
	".\CArrayExampleDlg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CArrayExample.obj" : $(SOURCE) $(DEP_CPP_CARRA) "$(INTDIR)"\
 "$(INTDIR)\CArrayExample.pch"


!ELSEIF  "$(CFG)" == "CArrayExample - Win32 Debug"

DEP_CPP_CARRA=\
	".\ArrayClass.h"\
	".\CArrayExample.h"\
	".\CArrayExampleDlg.h"\
	

"$(INTDIR)\CArrayExample.obj" : $(SOURCE) $(DEP_CPP_CARRA) "$(INTDIR)"\
 "$(INTDIR)\CArrayExample.pch"


!ENDIF 

SOURCE=.\CArrayExample.rc
DEP_RSC_CARRAY=\
	".\res\CArrayExample.ico"\
	".\res\CArrayExample.rc2"\
	

"$(INTDIR)\CArrayExample.res" : $(SOURCE) $(DEP_RSC_CARRAY) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\CArrayExampleDlg.cpp

!IF  "$(CFG)" == "CArrayExample - Win32 Release"

DEP_CPP_CARRAYE=\
	".\ArrayClass.h"\
	".\CArrayExample.h"\
	".\CArrayExampleDlg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CArrayExampleDlg.obj" : $(SOURCE) $(DEP_CPP_CARRAYE) "$(INTDIR)"\
 "$(INTDIR)\CArrayExample.pch"


!ELSEIF  "$(CFG)" == "CArrayExample - Win32 Debug"

DEP_CPP_CARRAYE=\
	".\ArrayClass.h"\
	".\CArrayExample.h"\
	".\CArrayExampleDlg.h"\
	

"$(INTDIR)\CArrayExampleDlg.obj" : $(SOURCE) $(DEP_CPP_CARRAYE) "$(INTDIR)"\
 "$(INTDIR)\CArrayExample.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "CArrayExample - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\CArrayExample.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CArrayExample.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CArrayExample - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CArrayExample.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CArrayExample.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

