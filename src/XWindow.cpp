#include "XWindow.h"

void XGraphics::XWindow::InitWindowClass(std::wstring wClassName, HINSTANCE hInst, WNDPROC windowProcess)
{
	flogger.log(LogLevel::DEBUG, "Initing window...");
	windowClassName = wClassName;
	hInstance = hInst;

	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcess;
	windowClass.hInstance = hInst;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	windowClass.lpszClassName = windowClassName.c_str();
	flogger.log(LogLevel::DEBUG, "Window inited!");
}

void XGraphics::XWindow::setWindowName(std::wstring wName)
{
	windowName = wName;
	flogger.log(LogLevel::DEBUG, "Setting window name...");
}

void XGraphics::XWindow::setWindowHeight(int height)
{
	hth = height;
	flogger.log(LogLevel::DEBUG, "Setting window height...");
}

void XGraphics::XWindow::setWindowWidth(int width)
{
	wth = width;
	flogger.log(LogLevel::DEBUG, "Setting window width...");
}

HWND XGraphics::XWindow::getWindowHwnd() const
{
	return hWnd;
}

void XGraphics::XWindow::create()
{
	flogger.log(LogLevel::DEBUG, "Creating window...");
	RegisterClassEx(&windowClass);
	hWnd = CreateWindowEx(
		NULL, windowClassName.c_str(), windowName.c_str(), WS_OVERLAPPEDWINDOW,
		0, 0, wth, hth,
		NULL, NULL, hInstance, NULL
	);
	flogger.log(LogLevel::DEBUG, "Window created!");
}

void XGraphics::XWindow::show() const
{
	ShowWindow(hWnd, SW_SHOW);
}

void XGraphics::XWindow::update() const
{
	UpdateWindow(hWnd);
}

void XGraphics::XWindow::handler()
{
	flogger.log(LogLevel::DEBUG, "Handler starting...");
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT XGraphics::XWindow::XWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

