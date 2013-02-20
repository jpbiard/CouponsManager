#include "StdAfx.h"
#include "MyXmlWriter.h"

/*
 * Constructor
 */
MyXmlWriter::MyXmlWriter(void) {
}

/*
 * SaveFabricantsList
 */
void MyXmlWriter::SaveFabricantsList(List<MyFabricant^>^ lpFabricantsList, Stream^ lpFileStream) {

	XmlTextWriter^ lpXmlTextWriter = gcnew XmlTextWriter(lpFileStream, Encoding::UTF8 );
	lpXmlTextWriter->Formatting = Formatting::Indented;
	lpXmlTextWriter->WriteStartDocument();
	lpXmlTextWriter->WriteStartElement( "Coupons" );

	lpXmlTextWriter->WriteStartElement( "Sauvegarde" );
	lpXmlTextWriter->WriteAttributeString( "date", ( DateTime::Now ).ToString() );
	lpXmlTextWriter->WriteEndElement(); // Sauvegarde

	for each ( MyFabricant^ s in lpFabricantsList ) {
		lpXmlTextWriter->WriteStartElement( "Fabricant" );
		lpXmlTextWriter->WriteAttributeString( "nom", s->nom );
		lpXmlTextWriter->WriteAttributeString( "code", s->code );

		List<MyCoupon^>^ lpCouponsList = s->couponsList;
		for each ( MyCoupon^ t in lpCouponsList ) {
			lpXmlTextWriter->WriteStartElement( "Coupon" );
			lpXmlTextWriter->WriteAttributeString( "nom", t->nom );
			lpXmlTextWriter->WriteAttributeString( "code", t->code );
			lpXmlTextWriter->WriteAttributeString( "prix", t->montantRaw );
			lpXmlTextWriter->WriteAttributeString( "quantite", t->quantite );
			lpXmlTextWriter->WriteAttributeString( "tag", t->tag );
			lpXmlTextWriter->WriteEndElement(); // Coupon
		}
		lpXmlTextWriter->WriteEndElement(); // Fabricant
	}
	lpXmlTextWriter->WriteEndElement(); // Coupons

	lpXmlTextWriter->Flush();
	lpXmlTextWriter->Close();
}

/*
 * SaveFabricantsList
 */
void MyXmlWriter::SaveFabricantsList(Stream^ lpFileStream) {

	XmlTextWriter^ lpXmlTextWriter = gcnew XmlTextWriter(lpFileStream, Encoding::UTF8 );
	lpXmlTextWriter->Formatting = Formatting::Indented;
	lpXmlTextWriter->WriteStartDocument();
	lpXmlTextWriter->WriteStartElement( "Coupons" );

	lpXmlTextWriter->WriteStartElement( "Sauvegarde" );
	lpXmlTextWriter->WriteAttributeString( "date", ( DateTime::Now ).ToString() );
	lpXmlTextWriter->WriteEndElement(); // Sauvegarde

	lpXmlTextWriter->WriteEndElement(); // Coupons

	lpXmlTextWriter->Flush();
	lpXmlTextWriter->Close();
}
