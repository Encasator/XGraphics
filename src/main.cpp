#include <iostream>
#include <Windows.h>

#include "XWindow.h"
#include "XButton.h"
#include "XComboBox.h"

XGraphics::XWindow window;
XGraphics::XComboBox cbox;
XGraphics::XButton testButton1;
XGraphics::XButton testButton2;
XGraphics::XButton testButton3;
XGraphics::XButton testButton4;

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	window.InitWindowClass(L"Class Name", hInstance, WndProc);
	window.setWindowName(L"Window Name");
	window.setWindowWidth(800);
	window.setWindowHeight(600);

	window.create();
	window.show();

    cbox.setComboName(L"Name");
    cbox.setParentHwnd(window.getWindowHwnd());


    testButton1.setHmenuDescriptor(1);
    testButton1.setButtonName(L"TEST1");
    testButton1.setButtonSize(80, 30);
    testButton1.setParentHwnd(window.getWindowHwnd());

    testButton2.setHmenuDescriptor(2);
    testButton2.setButtonCreatePoint(80, 0);
    testButton2.setButtonName(L"TEST2");
    testButton2.setButtonSize(80, 30);
    testButton2.setParentHwnd(window.getWindowHwnd());

    testButton3.setHmenuDescriptor(3);
    testButton3.setButtonCreatePoint(160, 0);
    testButton3.setButtonName(L"TEST3");
    testButton3.setButtonSize(80, 30);
    testButton3.setParentHwnd(window.getWindowHwnd());

    testButton4.setHmenuDescriptor(4);
    testButton4.setButtonCreatePoint(240, 0);
    testButton4.setButtonName(L"TEST4");
    testButton4.setButtonSize(80, 30);
    testButton4.setParentHwnd(window.getWindowHwnd());

    testButton1.activate();
    testButton2.activate();
    testButton3.activate();
    testButton4.activate();

    cbox.activate();

	
	window.update();

	window.handler();
}

LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        }
        return 0;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

