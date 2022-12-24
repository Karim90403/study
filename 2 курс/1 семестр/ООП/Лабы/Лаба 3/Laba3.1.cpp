#include <windows.h> 
#include <tchar.h> 
#include <vector>
#include <list>
#include <cmath>

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");

#define MAX_LOADSTRING 100 

int APIENTRY WinMain(HINSTANCE This, HINSTANCE Prev, LPSTR cmd, int mode)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS wc;
    wc.hInstance = This;
    wc.lpszClassName = WinName;
    wc.lpfnWndProc = WndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszMenuName = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;

    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    if (!RegisterClass(&wc)) return 0;

    hWnd = CreateWindow(WinName, _T("Каркас Windows-приложения"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, HWND_DESKTOP, NULL, This, NULL);

    ShowWindow(hWnd, mode);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;


}

class Shape
{
public:
    Shape() {};
    virtual void Draw(HDC hdc) {};
    virtual ~Shape() {};
};

class Circle : public Shape {
    int startCoord, center, endCoord, radius;
public:
    Circle(int center, int radius)
    {
        startCoord = center - radius;
        endCoord = center + radius;
    }
    void Draw(HDC hdc)
    {
        Ellipse(hdc, startCoord, 0, endCoord, endCoord);
    }
};

class Rect : public Shape {
    int startCoord, width, height, rightCoord, bottomCoord;
public:
    Rect(int start, int width, int height)
    {
        startCoord = start;
        rightCoord = startCoord + width;
        bottomCoord = height;
    }
    void Draw(HDC hdc) {
        Rectangle(hdc, startCoord, 0, rightCoord, bottomCoord);
    }
};

vector<Shape*> Figures;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc; int x, y; static int startx, starty, step, lenght, sx, sy;
    switch (message)
    {
    case WM_CREATE:
    {
        Figures.push_back(new Circle(100, 100));
        Figures.push_back(new Rect(250, 150, 200));
        break;
    }
    case WM_SIZE:
        sx = LOWORD(wParam);
        sy = LOWORD(lParam);
        break;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        for (vector <Shape*>::iterator it = Figures.begin(); it != Figures.end(); ++it) {
            (*it)->Draw(hdc);
        }


        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:

        for (vector <Shape*>::iterator it = Figures.begin(); it != Figures.end(); ++it) {
            delete (*it);
        }
        Figures.clear();

        PostQuitMessage(0);
        break;
    default:return DefWindowProc(hWnd, message, wParam, lParam);

    }
    return 0;
}
