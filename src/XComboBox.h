#pragma once

#include <windows.h>
#include <vector>
#include <string>

namespace XGraphics
{
	class XComboBox
	{
	private:
		HWND hWnd{ NULL }; // ComboBox descriptor
		HWND hwndParent{ NULL }; // Parent window descriptor
		std::wstring comboBoxName;
		std::vector <std::wstring> itemList;
	public:
		XComboBox() = default;
		XComboBox(HWND phwnd) : hwndParent(phwnd) {};
		XComboBox(std::wstring comboName) : comboBoxName(comboName) {};
		XComboBox(HWND phwnd, std::wstring comboName) : hwndParent(phwnd), comboBoxName(comboName) {};

		void setParentHwnd(HWND phwnd);
		void addItem(std::wstring item);
		void deleteItem(std::wstring item);
		void setComboName(std::wstring name);
		void activate();

	};
}

