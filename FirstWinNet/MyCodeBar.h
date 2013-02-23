#pragma once

using namespace System;
using namespace System::Text;

public ref class MyCodeBar
{
public:
	MyCodeBar( String^ );

	property String^ codeCountry {
		String^ get() {
			return m_codeCountry;
		}
	}

	property String^ codeFabricant {
		String^ get() {
			return m_codeFabricant;
		}
	}

	property String^ codeCoupon {
		String^ get() {
			return m_codeCoupon;
		}
	}

	property String^ codeBarTag {
		String^ get() {
			StringBuilder^ alpTemp = gcnew StringBuilder( m_codeFabricant );
			alpTemp->Append( m_codeCoupon );
			alpTemp->Append( m_montantCoupon );
			return alpTemp->ToString();
		}
	}

	property String^ montantCoupon {
		String^ get() {
			return m_montantCoupon;
		}
		void set( String^ newTxt ) {
			m_montantCoupon = newTxt;
		}
	}

	property Decimal^ montantDecimalCoupon {
		Decimal^ get() {
			return Decimal::Parse( this->m_montantCoupon ) / 100;
		}
	}

private:
	String^ m_codeBar;
	String^ m_codeCountry;
	String^ m_codeFabricant;
	String^ m_codeCoupon;
	String^ m_montantCoupon; // le prix peut etre inclu dans le barre code ou specifie par la suite
	
	System::String^ validateBarCode(String^);
};

