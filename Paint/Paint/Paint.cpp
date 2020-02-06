// Paint.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Paint.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

int PosX, PosY, PosXold, PosYold;
bool fDraw;
bool isLine;
bool isEllipse;
bool isCleaner;

struct Color
{
	int R;
	int G;
	int B;
};

Color color;

HWND button_Red;
HWND button_Orange;
HWND button_Yellow;
HWND button_Green;
HWND button_Aqua;
HWND button_Blue;
HWND button_Purple;
HWND button_Black;
HWND button_Line;
HWND button_Ellipse;
HWND button_Cleaner;
HWND button_CleanAll;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PAINT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PAINT));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PAINT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PAINT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		{
			button_Red = CreateWindow(L"BUTTON", L"Red", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 180, 100, 20, hWnd, NULL, NULL, NULL);
			button_Orange = CreateWindow(L"BUTTON", L"Orange", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 200, 100, 20, hWnd, NULL, NULL, NULL);
			button_Yellow = CreateWindow(L"BUTTON", L"Yellow", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 220, 100, 20, hWnd, NULL, NULL, NULL);
			button_Green = CreateWindow(L"BUTTON", L"Green", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 240, 100, 20, hWnd, NULL, NULL, NULL);
			button_Aqua = CreateWindow(L"BUTTON", L"Aqua", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 260, 100, 20, hWnd, NULL, NULL, NULL);
			button_Blue = CreateWindow(L"BUTTON", L"Blue", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 280, 100, 20, hWnd, NULL, NULL, NULL);
			button_Purple = CreateWindow(L"BUTTON", L"Purple", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 300, 100, 20, hWnd, NULL, NULL, NULL);
			button_Black = CreateWindow(L"BUTTON", L"Black", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 320, 100, 20, hWnd, NULL, NULL, NULL);
			button_Line = CreateWindow(L"BUTTON", L"Line", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 80, 100, 20, hWnd, NULL, NULL, NULL);
			button_Ellipse = CreateWindow(L"BUTTON", L"Ellipse", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 100, 100, 20, hWnd, NULL, NULL, NULL);
			button_Cleaner = CreateWindow(L"BUTTON", L"Cleaner", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 120, 100, 20, hWnd, NULL, NULL, NULL);
			button_CleanAll = CreateWindow(L"BUTTON", L"Clean All", WS_VISIBLE | WS_CHILD | WS_BORDER, 1075, 140, 100, 20, hWnd, NULL, NULL, NULL);

			color.R = 0;
			color.B = 0;
			color.G = 0;

			isLine = true;
			isEllipse = false;
			isCleaner = false;
		}
		break;
	case WM_LBUTTONUP:
		{
			fDraw = false;
		}
		break;
	case WM_LBUTTONDOWN:
		{
			fDraw = true;
			PosX = LOWORD(lParam);
			PosY = HIWORD(lParam);
			PosXold = LOWORD(lParam);
			PosYold = HIWORD(lParam);
		}
		break;
	case WM_MOUSEMOVE:
		if (fDraw && LOWORD(lParam)<1074)
		{
			HDC hdc = GetDC(hWnd);

			if (isEllipse == true)
			{
				HBRUSH hBrush;
				hBrush = CreateSolidBrush(RGB(255, 255, 255));
				SelectObject(hdc, hBrush);
				Ellipse(hdc, PosX, PosY, PosXold, PosYold);
				HPEN hPen = CreatePen(PS_DASHDOT, 1, RGB(255, 255, 255));
				SelectObject(hdc, hPen);
				Ellipse(hdc, PosX, PosY, PosXold, PosYold);
				hBrush = CreateSolidBrush(RGB(color.R, color.G, color.B));
				SelectObject(hdc, hBrush);
				Ellipse(hdc, PosX, PosY, LOWORD(lParam), HIWORD(lParam));
				PosXold = LOWORD(lParam);
				PosYold = HIWORD(lParam);
			}

			if (isLine == true)
			{
				HPEN hPen = CreatePen(PS_DASHDOT, 5, RGB(color.R, color.G, color.B));
				SelectObject(hdc, hPen);
				MoveToEx(hdc, PosX, PosY, NULL);
				LineTo
				(
					hdc,
					PosX = LOWORD(lParam),
					PosY = HIWORD(lParam)
				);
			}
			if (isCleaner == true)
			{
				HPEN Cleaner = CreatePen(PS_DASHDOT, 30, RGB(255, 255, 255));
				SelectObject(hdc, Cleaner);
				MoveToEx(hdc, PosX, PosY, NULL);
				LineTo
				(
					hdc,
					PosX = LOWORD(lParam),
					PosY = HIWORD(lParam)
				);
			}

			ReleaseDC(hWnd, hdc);
		}
		break;
    case WM_COMMAND:
        {
			if (lParam == (LPARAM)button_Red)
			{
				color.R = 255;
				color.G = 0;
				color.B = 0;
			}
			else
			{
				if (lParam == (LPARAM)button_Orange)
				{
					color.R = 255;
					color.G = 69;
					color.B = 0;
				}
				else
				{
					if (lParam == (LPARAM)button_Yellow)
					{
						color.R = 255;
						color.G = 255;
						color.B = 0;
					}
					else
					{
						if (lParam == (LPARAM)button_Green)
						{
							color.R = 0;
							color.G = 255;
							color.B = 0;
						}
						else
						{
							if (lParam == (LPARAM)button_Aqua)
							{
								color.R = 0;
								color.G = 255;
								color.B = 255;
							}
							else
							{
								if (lParam == (LPARAM)button_Blue)
								{
									color.R = 0;
									color.G = 0;
									color.B = 255;
								}
								else
								{
									if (lParam == (LPARAM)button_Purple)
									{
										color.R = 199;
										color.G = 21;
										color.B = 133;
									}
									else
									{
										if (lParam == (LPARAM)button_Black)
										{
											color.R = 0;
											color.G = 0;
											color.B = 0;
										}
										else
										{
											if (lParam == (LPARAM)button_Cleaner)
											{
												isCleaner = true;
												isLine = false;
												isEllipse = false;
											}
											else
											{
												if (lParam == (LPARAM)button_Line)
												{
													isCleaner = false;
													isLine = true;
													isEllipse = false;
												}
												else
												{
													if (lParam == (LPARAM)button_Ellipse)
													{
														isCleaner = false;
														isLine = false;
														isEllipse = true;
													}
													else
													{
														if (lParam == (LPARAM)button_CleanAll)
														{
															HDC hdc = GetDC(hWnd);
															HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
															SelectObject(hdc, hBrush);
															Rectangle(hdc, 0, 0, 1075, 1000);
															HPEN hPen = CreatePen(PS_DASHDOT, 1, RGB(255, 255, 255));
															SelectObject(hdc, hPen);
															Rectangle(hdc, 0, 0, 1075, 1000);
															ReleaseDC(hWnd, hdc);
														}

													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}

			int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
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

// Обработчик сообщений для окна "О программе".
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
