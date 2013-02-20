#include "stdafx.h"
#include "MyTomCoFabricant.h"


MyTomCoFabricant::MyTomCoFabricant(void) : MyFabricant ( TOMCO_FABRICANT_NAME, TOMCO_FABRICANT_CODE ) {
}

bool MyTomCoFabricant::Equals( MyTomCoFabricant^ lpFabricant ) {
	Diagnostics::Debug::WriteLine( "MyTomCoFabricant::Equals called !!!" );
	if ( this->m_nom->CompareTo( lpFabricant->m_nom ) != 0 )
		return false;
	if ( this->m_code->CompareTo( lpFabricant->m_code ) != 0 )
		return false;

	return true;
}
