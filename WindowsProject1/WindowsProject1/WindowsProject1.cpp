﻿// WindowsProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND _hWnd;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void setWindowSize(int x, int y, int width, int height);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   _hWnd = hWnd;
   setWindowSize(400, 100, 1000, 400);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc, 0, 0, L"박상현 : 과제 시작", lstrlen(L"박상현 : 과제 시작"));
            TextOut(hdc, 20, 20, L"민용식 : 과제?", lstrlen(L"민용식 : 과제?"));
            TextOut(hdc, 40, 40, L"김성의 : 상점마렵네", lstrlen(L"김성의 : 상점마렵네"));
            TextOut(hdc, 60, 60, L"정성진 : 1945 뜯는거 확인해봐", lstrlen(L"정성진 : 1945 뜯는거 확인해봐"));
            TextOut(hdc, 80, 80, L"박상현 : 오늘 수업한 내용도 보내줘", lstrlen(L"박상현 : 오늘 수업한 내용도 보내줘"));
            TextOut(hdc, 100, 100, L"민용식 : 안 뜯겨", lstrlen(L"민용식 : 안 뜯겨"));
            TextOut(hdc, 120, 120, L"김성의 : 나도", lstrlen(L"김성의 : 나도"));
            TextOut(hdc, 140, 140, L"정성진 : 나도 그래", lstrlen(L"정성진 : 나도 그래"));
            TextOut(hdc, 160, 160, L"박상현 : 오늘 다 할 때까지 못간다", lstrlen(L"박상현 : 오늘 다 할 때까지 못간다"));
            TextOut(hdc, 180, 180, L"민용식: 우웩", lstrlen(L"민용식: 우웩"));
            TextOut(hdc, 200, 200, L"김성의: 넹", lstrlen(L"김성의: 넹"));
            TextOut(hdc, 220, 220, L"정성진 : 넹 그렇습니다", lstrlen(L"정성진 : 넹 그렇습니다"));
            TextOut(hdc, 240, 240, L"박상현 : 다음에 또 자습실 자리 없으면 어떡하지?", lstrlen(L"박상현 : 다음에 또 자습실 자리 없으면 어떡하지?"));
            TextOut(hdc, 260, 260, L"민용식 : 카페", lstrlen(L"민용식 : 카페"));
            TextOut(hdc, 280, 280, L"김성의 : 근데 우리 전부 선헤이븐 해본적없으니까 팀명 일단박조 어떰", lstrlen(L"김성의 : 근데 우리 전부 선헤이븐 해본적없으니까 팀명 일단박조 어떰"));
            TextOut(hdc, 300, 300, L"정성진 : 일단박조..?", lstrlen(L"정성진 : 일단박조..?"));
            TextOut(hdc, 320, 320, L"민용식 : 덤프트럭", lstrlen(L"민용식 : 덤프트럭"));
            TextOut(hdc, 340, 340, L"박상현 : ㅋㅋㅋㅋ 후보에 추가해 놓을게 과제 2번은 마지막 하나 남음", lstrlen(L"박상현 : ㅋㅋㅋㅋ 후보에 추가해 놓을게 과제 2번은 마지막 하나 남음"));
            TextOut(hdc, 360, 360, L"김성의 : 일단 스트라이커 뜯기 드래곤언팩커로 시도중", lstrlen(L"김성의 : 일단 스트라이커 뜯기 드래곤언팩커로 시도중"));
            TextOut(hdc, 360, 0, L"정성진 : 태양을 피하는 방법", lstrlen(L"정성진 : 태양을 피하는 방법"));
            TextOut(hdc, 340, 20, L"박상현 : 과제 2 다했는데 테스트해보고 공유할게", lstrlen(L"박상현 : 과제 2 다했는데 테스트해보고 공유할게"));
            TextOut(hdc, 320, 40, L"민용식 : 리소스 뜯기면 그것도 톡방에 올려서 공유하자", lstrlen(L"민용식 : 리소스 뜯기면 그것도 톡방에 올려서 공유하자"));
            TextOut(hdc, 300, 60, L"김성의 : ㅇㅋㄷㅋ 아직시도중", lstrlen(L"김성의 : ㅇㅋㄷㅋ 아직시도중"));
            TextOut(hdc, 280, 80, L"정성진 : 깃허브 용량 제한이 안풀린다ㅠㅠㅠ", lstrlen(L"정성진 : 깃허브 용량 제한이 안풀린다ㅠㅠㅠ"));
            TextOut(hdc, 260, 100, L"박상현 : 과제2 완 배포한다. 이해 안되면 물어봐", lstrlen(L"박상현 : 과제2 완 배포한다. 이해 안되면 물어봐"));
            TextOut(hdc, 240, 120, L"민용식 : 굿 근데 우리 저녁도 먹고 가?", lstrlen(L"민용식 : 굿 근데 우리 저녁도 먹고 가?"));
            TextOut(hdc, 220, 140, L"김성의 : 엄준식먹고싶다", lstrlen(L"김성의 : 엄준식먹고싶다"));
            TextOut(hdc, 200, 160, L"정성진 : 아직도 안된다", lstrlen(L"정성진 : 아직도 안된다"));
            TextOut(hdc, 180, 180, L"박상현 : 저녁 어떻게 할래?", lstrlen(L"박상현 : 저녁 어떻게 할래?"));
            TextOut(hdc, 160, 200, L"민용식: 각자 해산하면 집에서 먹기?", lstrlen(L"민용식: 각자 해산하면 집에서 먹기?"));
            TextOut(hdc, 140, 220, L"김성의: 스윗마이홈~", lstrlen(L"김성의: 스윗마이홈~"));
            TextOut(hdc, 120, 240, L"정성진 : 리소스 추출도 안된다", lstrlen(L"정성진 : 리소스 추출도 안된다"));
            TextOut(hdc, 100, 260, L"박상현 : 왜 안되지", lstrlen(L"박상현 : 왜 안되지"));
            TextOut(hdc, 80, 280, L"민용식 : 어렵다 어려워", lstrlen(L"민용식 : 어렵다 어려워"));
            TextOut(hdc, 60, 300, L"김성의 : ㅠㅠㅠㅠㅠㅠ", lstrlen(L"김성의 : ㅠㅠㅠㅠㅠㅠ"));
            TextOut(hdc, 40, 320, L"정성진 : 할게 너무 많습니다", lstrlen(L"정성진 : 할게 너무 많습니다"));
            TextOut(hdc, 20, 340, L"박상현 : 하나만 더", lstrlen(L"박상현 : 하나만 더"));
            TextOut(hdc, 0, 360, L"민용식 : 끝났다", lstrlen(L"민용식 : 끝났다"));

            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void setWindowSize(int x, int y, int width, int height)
{
    RECT rc = { 0, 0, width, height };

    // 실제 윈도우 크기 조정
    // AdjustWindowRect(): RECT 구조체, 윈도우 스타일, 메뉴 여부 ?
    AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, false);

    // 얻어온 렉트의 정보로 윈도우 사이즈 세팅
    SetWindowPos(_hWnd, NULL, x, y,
        (rc.right - rc.left),
        (rc.bottom - rc.top),
        SWP_NOZORDER | SWP_NOMOVE);
}
