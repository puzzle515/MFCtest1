
// MFCtest1View.cpp: CMFCtest1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCtest1.h"
#endif

#include "MFCtest1Doc.h"
#include "MFCtest1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtest1View

IMPLEMENT_DYNCREATE(CMFCtest1View, CFormView)

BEGIN_MESSAGE_MAP(CMFCtest1View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCtest1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCtest1View::OnEnChangeEdit1)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCtest1View::OnBnClickedButton2)
	ON_STN_CLICKED(IDC_MetaFile, &CMFCtest1View::OnStnClickedMetafile)
END_MESSAGE_MAP()

// CMFCtest1View 생성/소멸

CMFCtest1View::CMFCtest1View() noexcept
	: CFormView(IDD_MFCTEST1_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCtest1View::~CMFCtest1View()
{
}

void CMFCtest1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CHARS, m_listctrl);
	DDX_Control(pDX, IDC_MetaFile, m_book);
}

BOOL CMFCtest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMFCtest1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMFCtest1View 인쇄


void CMFCtest1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCtest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCtest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCtest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFCtest1View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}

void CMFCtest1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtest1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtest1View 진단

#ifdef _DEBUG
void CMFCtest1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCtest1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCtest1Doc* CMFCtest1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtest1Doc)));
	return (CMFCtest1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtest1View 메시지 처리기


void CMFCtest1View::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


int CMFCtest1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_listctrl.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT,
		CRect(640,520,790,690),this, IDC_LIST_CHARS);

	m_listctrl.InsertColumn(0, _T("장"), LVCFMT_LEFT, 50, 0);
	m_listctrl.InsertColumn(1, _T("행"), LVCFMT_LEFT, 50, 1);
	m_listctrl.InsertColumn(0, _T("번"), LVCFMT_LEFT, 50, 2);

	return 0;
}


void CMFCtest1View::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRect rect;//픽쳐 컨트롤의 크기를 저장할 CRect 객체
	m_book.GetWindowRect(rect);//GetWindowRect를 사용해서 픽쳐 컨트롤의 크기를 받는다.
	CDC* dc; //픽쳐 컨트롤의 DC를 가져올  CDC 포인터
	dc = m_book.GetDC(); //픽쳐 컨트롤의 DC를 얻는다.
	CImage image;//불러오고 싶은 이미지를 로드할 CImage 
	image.Load(_T("001.jpg"));//이미지 로드

	image.StretchBlt(dc->m_hDC, 0, 0, 700, 494, SRCCOPY);//이미지를 픽쳐 컨트롤 크기로 조정
	ReleaseDC(dc);//DC 해제
}


void CMFCtest1View::OnStnClickedMetafile()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
