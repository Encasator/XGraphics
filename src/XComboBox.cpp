#include "XComboBox.h"

void XGraphics::XComboBox::setParentHwnd(HWND phwnd)
{
	hwndParent = phwnd;
}

void XGraphics::XComboBox::addItem(std::wstring item)
{
	itemList.push_back(item);
}

void XGraphics::XComboBox::deleteItem(std::wstring item)
{
    itemList.erase(
        std::remove(itemList.begin(), itemList.end(), item),
        itemList.end()
    );
}

void XGraphics::XComboBox::setComboName(std::wstring name)
{
    comboBoxName = name;
}

void XGraphics::XComboBox::activate()
{
    hWnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,                              // Extended window style
        L"WC_COMBOBOX",                                   // Class name
        comboBoxName.c_str(),                          // Window name
        CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD |     // Window styles
        WS_OVERLAPPED | WS_VISIBLE,
        0,                                            // X position
        0,                                            // Y position
        200,                                          // Width
        30,                                           // Height
        hwndParent,                                   // Parent window
        NULL,                                         // Menu/control ID
        NULL,                                         // Instance handle
        NULL                                          // Additional parameters
    );
}