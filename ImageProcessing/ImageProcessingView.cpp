﻿
// ImageProcessingView.cpp: CImageProcessingView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProcessing.h"
#endif

#include "ImageProcessingDoc.h"
#include "ImageProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessingView

IMPLEMENT_DYNCREATE(CImageProcessingView, CView)

BEGIN_MESSAGE_MAP(CImageProcessingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DOWN_SAMPLEING, &CImageProcessingView::OnDownSampleing)
	ON_COMMAND(ID_UP_SAMPLING, &CImageProcessingView::OnUpSampling)
	ON_COMMAND(ID_QUANTIZATION, &CImageProcessingView::OnQuantization)
	ON_COMMAND(ID_SUM_CONSTANT, &CImageProcessingView::OnSumConstant)
	ON_COMMAND(ID_SUB_CONSTANT, &CImageProcessingView::OnSubConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CImageProcessingView::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CImageProcessingView::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CImageProcessingView::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CImageProcessingView::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CImageProcessingView::OnXorOperate)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CImageProcessingView::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageProcessingView::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZAITON, &CImageProcessingView::OnBinarizaiton)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CImageProcessingView::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CImageProcessingView::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CImageProcessingView::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CImageProcessingView::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CImageProcessingView::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CImageProcessingView::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CImageProcessingView::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CImageProcessingView::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CImageProcessingView::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CImageProcessingView::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CImageProcessingView::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CImageProcessingView::OnLpfSharp)
END_MESSAGE_MAP()

// CImageProcessingView 생성/소멸

CImageProcessingView::CImageProcessingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProcessingView::~CImageProcessingView()
{
}

BOOL CImageProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageProcessingView 그리기

void CImageProcessingView::OnDraw(CDC* pDC)
{
	CImageProcessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	int i, j;
	unsigned char R, G, B;
	// 입력 영상 출력
	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = pDoc->m_InputImage[i * pDoc->m_width + j];
			G = B = R;
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}

	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}

}


// CImageProcessingView 인쇄

BOOL CImageProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImageProcessingView 진단

#ifdef _DEBUG
void CImageProcessingView::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessingDoc* CImageProcessingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessingDoc)));
	return (CImageProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessingView 메시지 처리기

void CImageProcessingView::OnDownSampleing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신

}

void CImageProcessingView::OnUpSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신

}

void CImageProcessingView::OnQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출

	Invalidate(TRUE); // 화면 갱신

}

void CImageProcessingView::OnSumConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSumConstant();

	Invalidate(TRUE);

}

void CImageProcessingView::OnSubConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSubConstant();

	Invalidate(TRUE);

}

void CImageProcessingView::OnMulConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnMulConstant();

	Invalidate(TRUE);

}

void CImageProcessingView::OnDivConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnDivConstant();

	Invalidate(TRUE);

}

void CImageProcessingView::OnAndOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAndOperate();

	Invalidate(TRUE);

}

void CImageProcessingView::OnOrOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOrOperate();

	Invalidate(TRUE);

}

void CImageProcessingView::OnXorOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);

}

void CImageProcessingView::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNegaTransform();

	Invalidate(TRUE);

}

void CImageProcessingView::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGammaCorrection();

	Invalidate(TRUE);

}

void CImageProcessingView::OnBinarizaiton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinarizaiton();

	Invalidate(TRUE);

}

void CImageProcessingView::OnStressTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnStressTransform();

	Invalidate(TRUE);

}

void CImageProcessingView::OnHistoStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoStretch();
	Invalidate(TRUE);
}

void CImageProcessingView::OnEndInSearch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnEndInSearch();
	Invalidate(TRUE);
}

void CImageProcessingView::OnHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistogram();
	Invalidate(TRUE);
}

void CImageProcessingView::OnHistoEqual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoEqual();
	Invalidate(TRUE);
}

void CImageProcessingView::OnHistoSpec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoSpec();
	Invalidate(TRUE);
}


void CImageProcessingView::OnEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnEmbossing();
	Invalidate(TRUE);
}

void CImageProcessingView::OnBlurr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBlurr();
	Invalidate(TRUE);
}

void CImageProcessingView::OnGaussianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGaussianFilter();
	Invalidate(TRUE);
}

void CImageProcessingView::OnSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnSharpening();
	Invalidate(TRUE);
}

void CImageProcessingView::OnHpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHpfSharp();
	Invalidate(TRUE);
}

void CImageProcessingView::OnLpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnLpfSharp();
	Invalidate(TRUE);
}