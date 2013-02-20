#include "stdafx.h"
#include "MyPriceComboBoxItem.h"

using namespace System::Text;
using namespace System::Globalization;

MyPriceComboBoxItem::MyPriceComboBoxItem(const String^ lpCount, const String^ lpValue) {
	m_count = lpCount;
	m_value = lpValue;
}

String^ MyPriceComboBoxItem::ToString() {
	// Generates the text shown in the combo box
	Decimal aPrice = Decimal::Parse( const_cast<String^>( m_value ) );
	aPrice = Decimal::Divide( aPrice, 100 );

	StringBuilder^ lpStrTemp = gcnew StringBuilder( aPrice.ToString( gcnew CultureInfo("fr-FR") ) );
	lpStrTemp->Append( " [" );
	lpStrTemp->Append( const_cast<String^>( m_count ) );
	lpStrTemp->Append( "]" );
	return lpStrTemp->ToString( );
}

int MyPriceComboBoxItem::CompareItemsByCount( MyPriceComboBoxItem^ lpItem1, MyPriceComboBoxItem^ lpItem2) {
	// return 0 for equal
	// return -1 if item2 is greater
	// return 1 if item1 is greater
	if ( lpItem1 == nullptr ) {
		if ( lpItem2 == nullptr ) {
			return 0;
		} else {
			return -1;
		}
	} else {
		if (lpItem2 == nullptr) {
			return 1;
		} else {
			// ...and y is not null, compare the count
			int countItem1 = Int32::Parse( const_cast<String^>( lpItem1->m_count ) );
			int countItem2 = Int32::Parse( const_cast<String^>( lpItem2->m_count ) );

			if ( countItem1 == countItem2 )
				return 0;
			if ( countItem1 > countItem2 )
				return 1;
			return -1;
		}
	}

}

