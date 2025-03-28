#ifndef XBUTTON_H
#define XBUTTON_H

#include <Windows.h>
#include <string>

#include "filelogger.h"

namespace XGraphics
{
	struct ButtonSize
	{
		unsigned int width;
		unsigned int height;
	};

	class XButton
	{
	private:
		HWND hWnd{NULL}; // descriptor
		HWND parentHwnd{NULL};// parent window descriptor
		HMENU hMenuDescriptor{NULL};
		std::wstring buttonClassName{L"BUTTON"};
		std::wstring buttonName;
		POINT buttonCreatePoint{0, 0};
		ButtonSize bsize{10, 10};
		FileLogger flogger{ "log.txt" };
	public:
		XButton() = default;
		XButton(HWND hwndParent);
		XButton(HWND hwndParent, std::wstring btnClassName, std::wstring name);

		void activate();
		void setHmenuDescriptor(int id);
		int getHmenuDescriptor() const;
		void setButtonSize(ButtonSize size);
		void setButtonSize(unsigned short w, unsigned short h);
		void setButtonCreatePoint(POINT &point);
		void setButtonCreatePoint(unsigned short x, unsigned short y);
		void setParentHwnd(HWND hwnd);
		void setButtonName(std::wstring name);
		void setButtonClassName(std::wstring name);
	};
}

#endif //XBUTTON_H

