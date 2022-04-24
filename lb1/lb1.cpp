// lb1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lb1.h"
#include <math.h>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

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
    LoadStringW(hInstance, IDC_LB1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LB1));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LB1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LB1);
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
    case WM_COMMAND:
        {
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
            int line_x, line_y;
            POINT My_Massiv[3];
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            
           const int rows = 28, cols = 3;
           int arr_xy[rows][cols] = { {200, 200, 1}, {100, 200, 1}, {200, 200, 1}, {200, 300, 1}, {100, 200, 1}, {100, 300, 1}, {100, 300, 1}, {200, 300, 1}, {150, 200, 1}, {150, 210, 1}, {200, 250, 1}, {190, 250, 1}, {150, 300, 1}, {150, 290, 1}, {100, 250, 1}, {110, 250, 1}, {150, 250, 1}, {170, 230, 1}, {170, 230, 1}, {160, 245, 1}, {150, 250, 1}, {160, 245, 1}, {150, 250, 1}, {160, 265, 1}, {160, 265, 1}, {150, 255, 1}, {150, 255, 1}, {150, 250, 1} };
            
            for (int i = 0; i < rows; i += 2) {

                MoveToEx(hdc, arr_xy[i][0], arr_xy[i][1], NULL);
                LineTo(hdc, arr_xy[i + 1][0], arr_xy[i + 1][1]);

            }

            //Задание №1
            double x = 2.4;
            double y = 1.5;

            int afmat[3][3] = { {static_cast<int>(x), 0, 0}, {0, static_cast<int>(y), 0}, {0, 0, 1} };
           
            
            int** res = new int*[rows];
            for (int i = 0; i < rows; i++) {
                res[i] = new int[cols];
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    res[i][j] = 0;
                }
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        res[i][j] += arr_xy[i][k] * afmat[k][j];
                    }
                }
            }

            for (int i = 0; i < rows; i += 2) {

                MoveToEx(hdc, res[i][0], res[i][1], NULL);
                LineTo(hdc, res[i + 1][0], res[i + 1][1]);

            }

            //Задание №2
         

            int afmat1[3][3] = { {0, 1, 0}, {1, 0, 0}, {0, 0, 1} };


            int** res1 = new int* [rows];
            for (int i = 0; i < rows; i++) {
                res1[i] = new int[cols];
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    res1[i][j] = 0;
                }
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        res1[i][j] += arr_xy[i][k] * afmat1[k][j];
                    }
                }
            }

            for (int i = 0; i < rows; i += 2) {

                MoveToEx(hdc, res1[i][0], res1[i][1], NULL);
                LineTo(hdc, res1[i + 1][0], res1[i + 1][1]);

            }

            //Задание №3
            int t = 180;

            int afmat2[3][3] = { { static_cast<int>(cos(t)), static_cast<int>(sin(t)), 0}, { -static_cast<int>(sin(t)), static_cast<int>(cos(t)), 0}, {0, 0, 1} };


            int** res2 = new int* [rows];
            for (int i = 0; i < rows; i++) {
                res2[i] = new int[cols];
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    res2[i][j] = 0;
                }
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        res2[i][j] += arr_xy[i][k] * afmat2[k][j];
                    }
                }
            }

            for (int i = 0; i < rows; i += 2) {

                MoveToEx(hdc, res2[i][0], res2[i][1], NULL);
                LineTo(hdc, res2[i + 1][0], res2[i + 1][1]);

            }

            ValidateRect(hWnd, NULL);
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
