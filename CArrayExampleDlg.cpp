// CArrayExampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CArrayExample.h"
#include "CArrayExampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCArrayExampleDlg dialog

CCArrayExampleDlg::CCArrayExampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCArrayExampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCArrayExampleDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCArrayExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCArrayExampleDlg)
	DDX_Control(pDX, IDC_SORTTIME, m_lblSortTime);
	DDX_Control(pDX, IDC_LIST1, m_lstList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCArrayExampleDlg, CDialog)
	//{{AFX_MSG_MAP(CCArrayExampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDLOAD, OnLoad)
	ON_BN_CLICKED(IDSORT, OnSort)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCArrayExampleDlg message handlers

BOOL CCArrayExampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCArrayExampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCArrayExampleDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCArrayExampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCArrayExampleDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void
CCArrayExampleDlg::CopyTheArrayToTheListBox()
{//Load the list box with the elements in the array.

	CArrayClass* pClass = NULL;
	CString strTemp;

//List boxes tend to flicker when loaded with a large number of items.
//Set the redraw off so that it redraws just once.
	GetDlgItem(IDC_LIST1)->SetRedraw(FALSE);
	m_lstList.ResetContent(); //Remove all items from list box.
	m_lstList.InitStorage(m_aCArrayClass.GetSize(),100);//This seems to have no impact on speed.

	for(long lCount = 0; lCount < m_aCArrayClass.GetSize(); lCount++) {
		//You can use CArray like a static array with the [n].
		//Or you can use the GetAt() and SetAt() methods.
		//I like to use a pointer to the element, because it is easier to view in the debugger.
		pClass = &m_aCArrayClass[lCount];
		strTemp.Format("%d %s",pClass->m_wMsgId, pClass->m_strMsgType);
		m_lstList.AddString(strTemp);
	}
	//Turn the redraw back on and force the list box to be redrawn.
	GetDlgItem(IDC_LIST1)->SetRedraw();
	GetDlgItem(IDC_LIST1)->Invalidate();
}//CopyTheArrayToTheListBox()

void 
CCArrayExampleDlg::OnLoad() 
{//Put a bunch of elements in the array so we have something to sort.

	CArrayClass A_Class_Instance_not_an_array;
	m_aCArrayClass.SetSize(0,1000);
	m_aCArrayClass.RemoveAll();
	m_lblSortTime.SetWindowText("");
	BeginWaitCursor();


	for(WORD wIndex = 0; wIndex < 10000; wIndex++) {
		A_Class_Instance_not_an_array.m_wMsgId = wIndex;
		A_Class_Instance_not_an_array.m_strMsgType = "REPORT";
		m_aCArrayClass.Add(A_Class_Instance_not_an_array);
		A_Class_Instance_not_an_array.m_wMsgId = wIndex;
		A_Class_Instance_not_an_array.m_strMsgType = "PERSON";
		m_aCArrayClass.Add(A_Class_Instance_not_an_array);
		A_Class_Instance_not_an_array.m_wMsgId = wIndex;
		A_Class_Instance_not_an_array.m_strMsgType = "TROUT";
		m_aCArrayClass.Add(A_Class_Instance_not_an_array);
	}

	CopyTheArrayToTheListBox();
	EndWaitCursor();
		
}//OnLoad()

//This function can be global or it can be a static member of your class,
//but it's address must be know at compile time.
int
CCArrayExampleDlg::SortTheArray(void* p1,void* p2)
{
	short n=0;
	CArrayClass* a1 = (CArrayClass*)p1;
	CArrayClass* a2 = (CArrayClass*)p2; 

	//It we were sorting a CPtrArray then we would have to do a second level of casting to get to 
	//the data keys that we would be sorting.

	if(a1->m_strMsgType < a2->m_strMsgType) //Ascending
		n=-1;
	else if(a1->m_strMsgType > a2->m_strMsgType)
		n=1;
	else if(a1->m_wMsgId < a2->m_wMsgId)//Ascending
		n=-1;
	else if(a1->m_wMsgId > a2->m_wMsgId)
		n=1;

	return n;
}//SortTheArray

void
CCArrayExampleDlg::OnSort() 
{//Sort the array
	CString strDuration;
	clock_t Start,End;                    
	double duration; 
	Start = clock();

	
	if(m_aCArrayClass.GetSize() > 0) {
		qsort((void*)&m_aCArrayClass[0],(size_t)m_aCArrayClass.GetSize(),sizeof(CArrayClass),
			(int(*)(const void*,const void*))CCArrayExampleDlg::SortTheArray);
	}

	End = clock();
	duration = (double)(End - Start)/CLOCKS_PER_SEC;
	strDuration.Format("QSort took [%3lf] Seconds  for [%d] Rows.\n",duration, m_aCArrayClass.GetSize());

	m_lblSortTime.SetWindowText(strDuration);

	CopyTheArrayToTheListBox();
	
}//CCArrayExampleDlg()

