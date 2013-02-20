#pragma once

using namespace System;
using namespace System::Collections::Generic;

ref class MyPriceComboBoxItem {

public:
	MyPriceComboBoxItem(const String^, const String^);

private:
	const String^ m_count;
	const String^ m_value;

public:
	property const String^ value {
		const String^ get() {
			return m_value;
		}
	}

public:
	virtual String^ ToString() override;

	static int CompareItemsByCount( MyPriceComboBoxItem^, MyPriceComboBoxItem^ );

};

