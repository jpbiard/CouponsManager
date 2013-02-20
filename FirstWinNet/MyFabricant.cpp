#include "StdAfx.h"
#include "MyFabricant.h"


MyFabricant::MyFabricant( String^ lpNom, String^ lpCode ) {
	this->m_nom = lpNom;
	this->m_code = lpCode;
	this->m_couponsList = gcnew List<MyCoupon^>(20);
	this->m_isUnknown = false;
}

bool MyFabricant::Equals( MyFabricant^ lpFabricant ) {
	Diagnostics::Debug::WriteLine( "MyFabricant::Equals called !!!" );
	if ( this->m_nom->CompareTo( lpFabricant->m_nom ) != 0 )
		return false;
	if ( this->m_code->CompareTo( lpFabricant->m_code ) != 0 )
		return false;

	return true;
}

bool MyFabricant::compareTo( MyCodeBar^ lpCodeBar ) {

	if ( this->m_isUnknown )
		return false;

	if ( this->m_code->CompareTo( const_cast<String^>( lpCodeBar->codeFabricant ) ) == 0 ) {
		// les coupons de Tom&Co ont un code barre commencant par '999011'
		if ( const_cast<String^>( lpCodeBar->codeCountry )->CompareTo( TOMCO_COUNTRY_CODE ) ) {
			if ( this->m_nom->CompareTo( TOMCO_FABRICANT_NAME ) )
				return true;
			else
				return false;
		} else {
			return true;
		}
	}

	return false;
}

bool MyFabricant::compareToCode( MyCodeBar^ lpCodeBar ) {
	if ( this->m_code->CompareTo( const_cast<String^>( lpCodeBar->codeFabricant ) ) == 0 )
		return true;
	else
		return false;
}

void MyFabricant::addOneCoupon( MyCoupon^ lpCoupon ) {

	this->couponsList->Add( lpCoupon );
}

void MyFabricant::addOneCoupon( String^ lpNom, String^ lpCode, String^ lpMontant, String^ lpQuantite, String^ lpTag ) {

	MyCoupon^ lpNewCoupon = gcnew MyCoupon( lpNom, lpCode, lpMontant, lpQuantite, lpTag );
	this->couponsList->Add( lpNewCoupon );
}
