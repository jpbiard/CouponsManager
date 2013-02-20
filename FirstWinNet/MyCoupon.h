#pragma once

using namespace System;

ref class MyCoupon
{
public:
	MyCoupon( String^, String^, String^, String^, String^ );

	property String^ code {
		String^ get() {
			return m_code;
		}
	}

	property String^ nom {
		String^ get() {
			return m_nom;
		}
	}

	property String^ montant {
		String^ get() {
			return this->m_montant;
		}
	}

	property String^ montantRaw {
		String^ get() {
			return this->m_montantRaw;
		}
	}

	property String^ quantite {
		String^ get() {
			return m_quantite;
		}
	}

	property String^ tag {
		String^ get() {
			return m_tag;
		}
		void set(String^ value) {
			m_tag = value;
		}
	}

	property const UInt32 quantiteInt {
		const UInt32 get() {
			return UInt32::Parse( const_cast<String^>( this->m_quantite ) );
		}
	}

	property const Decimal total {
		const Decimal get() {
			return Decimal::Parse( const_cast<String^>( this->m_montant ) ) * Decimal::Parse( const_cast<String^>( this->m_quantite ) );
		}
	}

	void addToQuantite(const Int32);

private:
	String^ m_code;
	String^ m_nom;
	String^ m_montant;
	String^ m_montantRaw;
	String^ m_quantite;
	String^ m_tag;
};

