#include "XButton.h"

XGraphics::XButton::XButton(HWND phwnd)
{
	setParentHwnd(phwnd);
	hWnd = CreateWindowEx(
		NULL, buttonClassName.c_str(), buttonName.c_str(), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | WS_TABSTOP,
		buttonCreatePoint.x, buttonCreatePoint.y, bsize.width, bsize.height,
		parentHwnd, hMenuDescriptor, (HINSTANCE)GetWindowLongPtr(parentHwnd, GWLP_HINSTANCE), NULL
	);

	if (!hWnd)
	{
		flogger.log(LogLevel::ERR, "Cannot create button");
		flogger.log(LogLevel::ERR, std::to_string(GetLastError()));
	}
}

void XGraphics::XButton::activate()
{
	hWnd = CreateWindowEx(
		NULL, buttonClassName.c_str(), buttonName.c_str(), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | WS_TABSTOP,
		buttonCreatePoint.x, buttonCreatePoint.y, bsize.width, bsize.height,
		parentHwnd, hMenuDescriptor, (HINSTANCE)GetWindowLongPtr(parentHwnd, GWLP_HINSTANCE), NULL
	);

	if (!hWnd)
	{
		flogger.log(LogLevel::ERR, "Cannot create button");
		flogger.log(LogLevel::ERR, std::to_string(GetLastError()));
	}
}

void XGraphics::XButton::setHmenuDescriptor(int id)
{
	hMenuDescriptor = reinterpret_cast<HMENU>(id);
}

int XGraphics::XButton::getHmenuDescriptor() const
{
	return reinterpret_cast<int>(hMenuDescriptor);
}

XGraphics::XButton::XButton(HWND hwndParent, std::wstring btnClassName, std::wstring name)
{
	setParentHwnd(hwndParent);
	buttonClassName = btnClassName;
	buttonName = name;

	hWnd = CreateWindowEx
	(
		NULL, buttonClassName.c_str(), buttonName.c_str(), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | WS_TABSTOP,
		buttonCreatePoint.x, buttonCreatePoint.y, bsize.width, bsize.height,
		parentHwnd, hMenuDescriptor, (HINSTANCE)GetWindowLongPtr(parentHwnd, GWLP_HINSTANCE), NULL
	);

	if (!hWnd)
	{
		flogger.log(LogLevel::ERR, "Cannot create button");
		flogger.log(LogLevel::ERR, std::to_string(GetLastError()));
	}
}

void XGraphics::XButton::setButtonSize(ButtonSize size)
{
	bsize = size;
}

void XGraphics::XButton::setButtonSize(unsigned short w, unsigned short h)
{
	bsize.width = w;
	bsize.height = h;
}

void XGraphics::XButton::setButtonCreatePoint(POINT& point)
{
	buttonCreatePoint = point;
}

void XGraphics::XButton::setButtonCreatePoint(unsigned short x, unsigned short y)
{
	buttonCreatePoint.x = x;
	buttonCreatePoint.y = y;
}

void XGraphics::XButton::setParentHwnd(HWND hwnd)
{
	parentHwnd = hwnd;
}

void XGraphics::XButton::setButtonName(std::wstring name)
{
	buttonName = name;
}

void XGraphics::XButton::setButtonClassName(std::wstring name)
{
	buttonClassName = name;
}
