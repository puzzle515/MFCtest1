
// MFCtest1View.h: CMFCtest1View 클래스의 인터페이스
//

#pragma once
#define IDC_LIST_CHARS 100

class CMFCtest1View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMFCtest1View() noexcept;
	DECLARE_DYNCREATE(CMFCtest1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCTEST1_FORM };
#endif

// 특성입니다.
public:
	CMFCtest1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCtest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CListCtrl m_listctrl;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedButton2();
	CStatic m_book;
	afx_msg void OnStnClickedMetafile();
};

#ifndef _DEBUG  // MFCtest1View.cpp의 디버그 버전
inline CMFCtest1Doc* CMFCtest1View::GetDocument() const
   { return reinterpret_cast<CMFCtest1Doc*>(m_pDocument); }
#endif

