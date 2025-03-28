#ifndef XWINDOW_H
#define XWINDOW_H

#include <Windows.h>
#include <string>
#include <iostream>

#include "filelogger.h"

namespace XGraphics
{
	class XWindow
	{
	private:
		WNDCLASSEX windowClass{0}; // Window Class
		HWND hWnd{NULL}; // Window Descriptor
		HINSTANCE hInstance{ nullptr }; // Window object
		std::wstring windowName;
		std::wstring windowClassName;
		MSG msg{};
		unsigned short wth{1920};
		unsigned short hth{1080};
		FileLogger flogger{"log.txt"};
	public:
		XWindow() = default;
		XWindow(std::wstring wName) : windowName(wName) {};
		XWindow(const XWindow& other) = delete;
		XWindow(XWindow&& rvalue) = delete;

		void InitWindowClass(std::wstring wClassName, HINSTANCE hInst, WNDPROC windowProcess);
		void setWindowName(std::wstring wName);
		void setWindowHeight(int height);
		void setWindowWidth(int width);
		HWND getWindowHwnd() const;
		void create();
		void show() const;
		void update() const;
		void handler();

		LRESULT XWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}

#endif //XWINDOW_H

