#include "StdAfx.h"
#include "MyCodeBar.h"
#include "MyBeep.h"

/*
 * Constructor
 */
MyCodeBar::MyCodeBar( String^ theCodeBar ) {

	String^ lpReturn = this->validateBarCode( theCodeBar );
	if (lpReturn != nullptr) {
		MyBeep::beep();
		throw gcnew Exception( "Le Code Bar entré est invalide; raison:\r\n" + lpReturn );
	}
	this->m_codeBar = theCodeBar;
	this->m_codeCountry = theCodeBar->Substring( 0, 3 );
	this->m_codeCoupon = theCodeBar->Substring( 6, 3 );
	this->m_codeFabricant = theCodeBar->Substring( 3, 3 );
	this->m_montantCoupon = theCodeBar->Substring( 9, 3 );
}

/*
 * validateBarCode
 */
System::String^ MyCodeBar::validateBarCode( String^ lpCodeBar ) {

	// check bar code text length
	if (lpCodeBar->Length != 13)
		return "Ne contient pas 13 chiffres";

	// Coupon must start with '982'
	if ( ( ! lpCodeBar->StartsWith( "982" ) ) && ( ! lpCodeBar->StartsWith( "999" ) ) )
		return "Un coupon doit commencer par le code: '982' ou '999' !";

	// check digit
	/*
	 * numeroter les digits dans l'autre sens (le dernier devient le premier
	 * step 1: sommer les digits impairs et multiplier par 3
	 * step 2: sommer les digits pairs
	 * step 3: additionner 1 et 2
	 * Step 4: step 3 - le nombre dizaine supérieur
	 */
	UInt32 aStep1 = ( UInt32::Parse( lpCodeBar->Substring( 11, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 9, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 7, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 5, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 3, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 1, 1 ) ) ) * 3;

	UInt32 aStep2 = UInt32::Parse( lpCodeBar->Substring( 10, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 8, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 6, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 4, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 2, 1 ) ) +
		UInt32::Parse( lpCodeBar->Substring( 0, 1 ) );

	UInt32 aStep3 = aStep1 + aStep2;

	UInt32 aCheckDigit = Decimal::ToUInt32( Decimal::Floor( Decimal::Divide( Decimal( aStep3 + 10 ), (Decimal) 10 ) ) * (Decimal)10 ) - aStep3;

	if ( aCheckDigit == 10 )
		aCheckDigit = 0;

	if (UInt32::Parse( lpCodeBar->Substring( 12, 1 ) ).CompareTo( aCheckDigit ) != 0 )
		return "Le checksum n'est pas correct";

	return nullptr;
}
