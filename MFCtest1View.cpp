﻿
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
#include "MainFrm.h"
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
    //   ON_STN_CLICKED(IDC_MetaFile, &CMFCtest1View::OnStnClickedMetafile)
    ON_WM_MOUSEMOVE()
    ON_BN_CLICKED(IDC_BUTTON3, &CMFCtest1View::OnBnClickedButton3)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONDOWN()
    ON_WM_VSCROLL()
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
    DDX_Control(pDX, IDC_K_NUM, m_k_num);
    DDX_Control(pDX, IDC_K_KIND, m_k_knd);
    DDX_Control(pDX, IDC_K_P_NUM, m_kpnum);
    DDX_Control(pDX, IDC_PAGE_CNUM, m_Pcnum);
    DDX_Control(pDX, IDC_PAGE_KIND, m_PCkind);
    DDX_Control(pDX, IDC_PAGE_PRINT, m_Pprintnum);


    DDX_Control(pDX, IDC_SPIN_SHEET, m_spin);
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
    m_spin.SetRange(1, 3);
    m_spin.SetPos(1);
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
    m_listctrl.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT,
        CRect(640, 520, 790, 690), this, IDC_LIST_CHARS);

    m_listctrl.InsertColumn(0, _T("장"), LVCFMT_LEFT, 50, 0);
    m_listctrl.InsertColumn(1, _T("행"), LVCFMT_LEFT, 50, 1);
    m_listctrl.InsertColumn(0, _T("번"), LVCFMT_LEFT, 50, 2);

    return 0;
}

CStringArray CCount, TCount;

void CMFCtest1View::OnBnClickedButton2()
{

    int size = 352;
    CString Sm_Data;
    // 중복 체크용
    CString C_temp, T_temp;
    int hwal = 352;
    int i = 0;
    int p = 0;
    int t = 0;
    int o = 0;
    int j = 0;
    int y = 0;
    int cake = 0;
    int p_nchar = 0;
    int p_nkind = 0;
    int p_nprint = 0;




    for (int i = 0; i < TypeDB.m_Chars.GetSize(); i++)
    {
        SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);


        if (NULL == pSCharInfo)
            continue;
        delete pSCharInfo;

        pSCharInfo = NULL;
    }

    int data = 0;

    CString strFilePath = _T("");
    strFilePath.Format("C:\\Users\\qmqal\\Desktop\\typeDB.csv");
    //strFilePath.Format("C:\\Users\\Ruin\\Desktop\\응프텀프\\월인천강지곡 권상\\typeDB.csv");
    //strFilePath.Format("C:\\typeDB.csv");
    FILE* fp = NULL;
    fopen_s(&fp, strFilePath, "r");

    if (fp)
    {
        char szContent[2048] = { 0, }; // 배열의 맨 앞을 NULL 로
        memset(szContent, NULL, 2048);

        while (fgets(szContent, 2048, fp))
        {
            CString strContent;
            strContent.Format(_T("%s"), szContent);
            memset(szContent, NULL, 2048);
            if (strContent.Find(_T("#")) >= 0) continue;
            strContent.Remove(_T('\r'));
            strContent.Remove(_T('\n'));

            SCharInfo* pSCharInfo = new SCharInfo;

            CString rString;
            int nSubString = 0;


            while (AfxExtractSubString(rString, strContent, nSubString++, ','))
            {
                switch (nSubString)
                {
                case 1: pSCharInfo->m_char = _T(rString);
                    CCount.Add(rString);
                    break;
                case 2: data = _ttoi(rString);
                    pSCharInfo->m_type = data;
                    TCount.Add(rString);
                    break;
                case 3: data = _ttoi(rString);
                    pSCharInfo->m_sheet = data;
                    break;
                case 4: data = _ttoi(rString);
                    pSCharInfo->m_sx = data;
                    break;
                case 5: data = _ttoi(rString);
                    pSCharInfo->m_sy = data;
                    break;
                case 6: data = _ttoi(rString);
                    pSCharInfo->m_line = data;
                    break;
                case 7: data = _ttoi(rString);
                    pSCharInfo->m_order = data;
                    break;
                case 8: data = _ttoi(rString);
                    pSCharInfo->m_width = data;
                    break;
                case 9: data = _ttoi(rString);
                    pSCharInfo->m_height = data;
                    break;


                }
            }
            TypeDB.m_Chars.Add(pSCharInfo);
        }


        fclose(fp);

    }
    //CString temp;

    int count = 0;
    int tcount = 0;
    CString Tcount;
    CString Scount;

    for (i = 1; i < TypeDB.m_Chars.GetCount(); i++) // page 1
    {
        SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);


        if (page == pSCharInfo->m_sheet) // page = 1  // 92 8
        {
            p_nchar++;
        }
    }



    for (i = 1; i < TypeDB.m_Chars.GetCount(); i++)
    {
        SCharInfo* p2SCharInfo = TypeDB.m_Chars.GetAt(i);

        if (p2SCharInfo->m_sheet == page)
        {
            p = 0;
            // = p - (o);

            while (p < i && CCount.GetAt(p) != CCount.GetAt(i)) p++;
            if (p == i) {
                p_nkind++;
            }
            o++;
        }

    }
    //   p_nkind = p_nchar - p_nkind;




    p_nprint = p_nchar;

    for (o = 1; o < TypeDB.m_Chars.GetCount(); o++)
    {
        p = o + 1;
        SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(o);
        while (p < TypeDB.m_Chars.GetCount())
        {

            if (CCount.GetAt(o) == CCount.GetAt(p) && TCount.GetAt(o) == TCount.GetAt(p))
            {

                if (pSCharInfo->m_sheet == page) p_nprint--;
            }
            p++;

        }
    }
    
            // page  데이터 출력
            Sm_Data.Format(_T("한글 글자수\t\t     %d 개"), p_nchar);
            m_Pcnum.SetWindowTextA(Sm_Data);
            Scount.Format(_T("한글 글자 종류\t\t       %d 종"), p_nkind);
            m_PCkind.SetWindowTextA(Scount);
            Tcount.Format(_T("한글 활자수\t\t     %d 개"), p_nprint);
            m_Pprintnum.SetWindowTextA(Tcount);
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        for (i = 1; i < (TypeDB.m_Chars.GetCount() - 1); i++)
        {
            p = 0;
            while (p < i && CCount.GetAt(p) != CCount.GetAt(i)) p++;
            if (p == i) {
                count++;
            }

        }
        for (i = 1; i < 352; i++)
        {

            t = 0;
            while (t < i && TCount.GetAt(t) != TCount.GetAt(i)) t++;
            if (t == i) {
                tcount++;
            }

        }
        hwal = count;
        for (i = 1; i < 352; i++)
        {
            p = i + 1;
            while (p < size)
            {

                if (CCount.GetAt(i) == CCount.GetAt(p) && TCount.GetAt(i) == TCount.GetAt(p))
                {
                    hwal = hwal - 1;
                    size--;
                }
                p++;

            }
        }


    
    TypeDB.m_nChar = (TypeDB.m_Chars.GetCount() - 1);
    Sm_Data.Format(_T("한글 글자수\t\t\t%d 개"), TypeDB.m_nChar);
    m_k_num.SetWindowTextA(Sm_Data);

    Scount.Format(_T("한글 글자 종류\t\t\t%d 종"), count);
    m_k_knd.SetWindowTextA(Scount);
    Tcount.Format(_T("한글 활자수\t\t\t%d 개"), size);
    m_kpnum.SetWindowTextA(Tcount);





    
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





void CMFCtest1View::OnMouseMove(UINT nFlags, CPoint point)
{
    CString str;
    str.Format(_T("(%4d,%4d)"), point.x, point.y);
    selx = point.x;
    sely = point.y;
    CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
    pMainFrame->m_wndStatusBar.SetPaneText(1, str);

    CFormView::OnMouseMove(nFlags, point);
}

//2022-05-31 jihun
//글자에 네모치기[김지훈] [오후 8:40] 


void CMFCtest1View::OnBnClickedButton3()
{
    //시트값 찾아서
    CClientDC dc(this);
    CPen Gpen, Rpen;
    CBrush brush, rbrush;
    brush.CreateStockObject(NULL_BRUSH);
    rbrush.CreateStockObject(NULL_BRUSH);

    Rpen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    Gpen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
    old_p = 1;
    for (int i = 1; i < 353; i++)
    {

        SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
        CPen* pOldPen = dc.SelectObject(&Gpen);
        CBrush* pOldBrush = dc.SelectObject(&brush);
        if (page == pSCharInfo->m_sheet) {
            double realsx = ((pSCharInfo->m_sx / 14.17) + 33);
            double realsy = ((pSCharInfo->m_sy / 14.2) + 229);
            double realwidth = ((pSCharInfo->m_width / 14.17));
            double realheight = ((pSCharInfo->m_height / 14.2));
            double endwidth = (realsx + realwidth);
            double endheight = (realsy + realheight);
            dc.Rectangle(realsx, realsy, endwidth, endheight);
            dc.SelectObject(pOldPen);
            dc.SelectObject(pOldBrush);
            DeleteObject(Gpen);
            DeleteObject(brush);

        }


    }

    {
        SCharInfo* poldSCharInfo = TypeDB.m_Chars.GetAt(old_p);
        if (page == poldSCharInfo->m_sheet) {

            CPen* prOldPen = dc.SelectObject(&Rpen);
            CBrush* prOldBrush = dc.SelectObject(&rbrush);
            double realsx = ((poldSCharInfo->m_sx / 14.17) + 33);
            double realsy = ((poldSCharInfo->m_sy / 14.2) + 229);
            double realwidth = ((poldSCharInfo->m_width / 14.17));
            double realheight = ((poldSCharInfo->m_height / 14.2));
            double endwidth = (realsx + realwidth);
            double endheight = (realsy + realheight);
            dc.Rectangle(realsx, realsy, endwidth, endheight);
            dc.SelectObject(prOldPen);
            dc.SelectObject(prOldBrush);

            DeleteObject(Rpen);
            DeleteObject(rbrush);
        }
    }
}// 할일 , 네모 칸 내부 투명, 초록색으로 바꾸기, 인식못한 글자들 이유 찾기





void CMFCtest1View::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    

    for (int i = 0; i < TypeDB.m_Chars.GetCount(); i++)
    {
        SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
        if (pSCharInfo->m_sheet == page)
        {
            if (
                ((pSCharInfo->m_sx / 14.17) + 33) < selx && selx < ((pSCharInfo->m_sx / 14.17) + 33) + ((pSCharInfo->m_width / 14.17))
                && ((pSCharInfo->m_sy / 14.2) + 229) < sely && sely < ((pSCharInfo->m_sy / 14.2) + 229) + ((pSCharInfo->m_height / 14.2))
                )

            {
                old_p = i;
            }
        }
    }
    
    //시트값 찾아서
    CClientDC dc(this);
    CPen Gpen, Rpen;
    CBrush brush, rbrush;
    brush.CreateStockObject(NULL_BRUSH);
    rbrush.CreateStockObject(NULL_BRUSH);

    Rpen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    Gpen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
    for (int i = 1; i < 353; i++)
    {

        SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
        CPen* pOldPen = dc.SelectObject(&Gpen);
        CBrush* pOldBrush = dc.SelectObject(&brush);
        if (page == pSCharInfo->m_sheet) {
            double realsx = ((pSCharInfo->m_sx / 14.17) + 33);
            double realsy = ((pSCharInfo->m_sy / 14.2) + 229);
            double realwidth = ((pSCharInfo->m_width / 14.17));
            double realheight = ((pSCharInfo->m_height / 14.2));
            double endwidth = (realsx + realwidth);
            double endheight = (realsy + realheight);
            dc.Rectangle(realsx, realsy, endwidth, endheight);
            dc.SelectObject(pOldPen);
            dc.SelectObject(pOldBrush);
            DeleteObject(Gpen);
            DeleteObject(brush);

        }


    }

    {
        SCharInfo* poldSCharInfo = TypeDB.m_Chars.GetAt(old_p);
        if (page  == poldSCharInfo->m_sheet) {

            CPen* prOldPen = dc.SelectObject(&Rpen);
            CBrush* prOldBrush = dc.SelectObject(&rbrush);
            double realsx = ((poldSCharInfo->m_sx / 14.17) + 33);
            double realsy = ((poldSCharInfo->m_sy / 14.2) + 229);
            double realwidth = ((poldSCharInfo->m_width / 14.17));
            double realheight = ((poldSCharInfo->m_height / 14.2));
            double endwidth = (realsx + realwidth);
            double endheight = (realsy + realheight);
            dc.Rectangle(realsx, realsy, endwidth, endheight);
            dc.SelectObject(prOldPen);
            dc.SelectObject(prOldBrush);

            DeleteObject(Rpen);
            DeleteObject(rbrush);
        }
    }

    CFormView::OnLButtonDown(nFlags, point);
}


void CMFCtest1View::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    if (pScrollBar->GetSafeHwnd() == m_spin.GetSafeHwnd())
    {
        int size = 352;
        CString Sm_Data;
        // 중복 체크용
        CString Scount, Tcount;
        int hwal = 352;
        int i = 0;
        int p = 0;
        int t = 0;
        int o = 0;
        int j = 0;
        int y = 0;
        int cake = 0;
        int p_nchar = 0;
        int p_nkind = 0;
        int p_nprint = 0;
        CString str;
        str.Format(_T(" %d"), nPos);
        page = nPos;
   


     
        

            for (i = 1; i < TypeDB.m_Chars.GetCount(); i++) // page 1
            {
                SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);


                if (page == pSCharInfo->m_sheet) // page = 1  // 92 8
                {
                    p_nchar++;
                }
            }

           

            for (i = 1; i < TypeDB.m_Chars.GetCount(); i++)
            {
                SCharInfo* p2SCharInfo = TypeDB.m_Chars.GetAt(i);

                if (p2SCharInfo->m_sheet == page)
                {
                    p = i;
                    p = p - (o);

                    while (p < i && CCount.GetAt(p) != CCount.GetAt(i)) p++;
                    if (p == i) {
                        p_nkind++;
                    }
                    o++;
                }

            }
            //   p_nkind = p_nchar - p_nkind;




            p_nprint = p_nchar;

            for (o = 1; o < TypeDB.m_Chars.GetCount(); o++)
            {
                p = o + 1;
                SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(o);
                while (p < TypeDB.m_Chars.GetCount())
                {

                    if (CCount.GetAt(o) == CCount.GetAt(p) && TCount.GetAt(o) == TCount.GetAt(p))
                    {

                        if (pSCharInfo->m_sheet == page) p_nprint--;
                    }
                    p++;

                }
            }







            // page  데이터 출력
            Sm_Data.Format(_T("한글 글자수\t\t     %d 개"), p_nchar);
            m_Pcnum.SetWindowTextA(Sm_Data);
            Scount.Format(_T("한글 글자 종류\t\t       %d 종"), p_nkind);
            m_PCkind.SetWindowTextA(Scount);
            Tcount.Format(_T("한글 활자수\t\t     %d 개"), p_nprint);
            m_Pprintnum.SetWindowTextA(Tcount);

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       

            CRect rect;//픽쳐 컨트롤의 크기를 저장할 CRect 객체
            m_book.GetWindowRect(rect);//GetWindowRect를 사용해서 픽쳐 컨트롤의 크기를 받는다.
            CDC* dc; //픽쳐 컨트롤의 DC를 가져올  CDC 포인터
            dc = m_book.GetDC(); //픽쳐 컨트롤의 DC를 얻는다.
            CImage image;//불러오고 싶은 이미지를 로드할 CImage 
            switch (page)
            {
            case 1:
                image.Load(_T("001.jpg"));//이미지 로드
                image.StretchBlt(dc->m_hDC, 0, 0, 700, 494, SRCCOPY);//이미지를 픽쳐 컨트롤 크기로 조정
                ReleaseDC(dc);//DC 해제
                break;
            case 2:
                image.Load(_T("002.jpg"));//이미지 로드
                image.StretchBlt(dc->m_hDC, 0, 0, 700, 494, SRCCOPY);//이미지를 픽쳐 컨트롤 크기로 조정
                ReleaseDC(dc);//DC 해제
                break;
            case 3:
                image.Load(_T("003.jpg"));//이미지 로드
                image.StretchBlt(dc->m_hDC, 0, 0, 700, 494, SRCCOPY);//이미지를 픽쳐 컨트롤 크기로 조정
                ReleaseDC(dc);//DC 해제
                break;
            default:
                break;
            }
            
           
            return;
        }

        CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
 }
