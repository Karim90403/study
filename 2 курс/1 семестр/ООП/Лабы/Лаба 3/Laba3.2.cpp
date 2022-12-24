#include <windows.h>
#include <tchar.h>
#include <cmath>
#include <vector>

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
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
	} return 0;
}

class Vector2D {
public:
	POINT p;
	int r = 50;
	void Paint(HDC hdc) {
		Ellipse(hdc, p.x - r, p.y - r, p.x + r, p.y + r);
	}
	Vector2D(POINT p0)
	{
		p = p0;
	}
	void sd(POINT p1) {
		p.x += p1.x;
		p.y += p1.y;
	}
	Vector2D& operator=(const Vector2D& D2)
	{
		p = D2.p;
		return *this;
	}
	~Vector2D() {}
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	int x, y;
	static int sx, sy;
	POINT p0 = { 100,0 };
	POINT p1[9];
	vector<Vector2D> db;
	for (int i = 0; i < 9; i++)
	{
		db.push_back(p0);
	}
	for (int i = 0; i < 3; i++) {
		p1[i].x = i * 150;
		p1[i].y = 150;
	}
	for (int i = 3; i < 6; i++) {
		p1[i].x = (i - 3) * 150;
		p1[i].y = 300;
	}
	for (int i = 6; i < 9; i++) {
		p1[i].x = (i - 6) * 150;
		p1[i].y = 450;
	}
	for (int i = 0; i < 9; i++)
	{
		db[i].sd(p1[i]);
	}
	switch (message) {
	case WM_SIZE:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		for (int i = 0; i < 9; i++)
		{
			db[i].Paint(hdc);
		}
		EndPaint(hWnd, &ps);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
