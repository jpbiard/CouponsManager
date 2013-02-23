#pragma once

#include "MyCoupon.h"
#include "MyCodeBar.h"

#define TOMCO_FABRICANT_NAME "Tom&Co"
#define TOMCO_FABRICANT_CODE "011"
#define TOMCO_COUNTRY_CODE "999"

using namespace System;
using namespace System::Collections::Generic;

public ref class MyFabricant : public IEquatable<MyFabricant^>
{
public:
	MyFabricant( String^, String^ );
	void addOneCoupon( MyCoupon^ );
	void addOneCoupon( String^, String^, String^, String^, String^ );

	bool compareTo( MyCodeBar^ );
	bool compareToCode( MyCodeBar^ );

	virtual bool Equals( MyFabricant^ );

	property String^ code {
		String^ get() {
			return m_code;
		}
	}

	property String^ nom {
		String^ get() {
			return m_nom;
		}
		void set( String^ value ) {
			m_nom = value;
		}
	}

	property List<MyCoupon^>^ couponsList {
		List<MyCoupon^>^ get() {
			return m_couponsList;
		}
	}

	property bool isUnknown {
		bool get() {
			return m_isUnknown;
		}
		void set( bool value ) {
			m_isUnknown = value;
		}
	}

protected:
	String^ m_nom;
	String^ m_code;
	List<MyCoupon^>^ m_couponsList;
	bool m_isUnknown;
};

