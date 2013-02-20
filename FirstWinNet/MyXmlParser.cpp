#include "StdAfx.h"
#include "MyXmlParser.h"

/*
 * Constructor
 */
MyXmlParser::MyXmlParser(void) {

	Diagnostics::Debug::WriteLine( "Class MyXmlParser created !" );
}
	
/*
 * Destructor
 */
MyXmlParser::~MyXmlParser() {
	this->!MyXmlParser();
}

/*
 * Destructor
 */
MyXmlParser::!MyXmlParser() {

	Diagnostics::Debug::WriteLine( "Class MyXmlParser destroyed !" );
	if ( xmlTextReader != nullptr ) {
		xmlTextReader->Close();
		//delete xmlTextReader;
	}
}

/*
 * Constructor
 */
MyXmlParser::MyXmlParser(String^ theXmlFileName) {

	Diagnostics::Debug::WriteLine( "Class MyXmlParser created !" );
	this->xmlTextReader = gcnew XmlTextReader( theXmlFileName );
	this->xmlTextReader->WhitespaceHandling = WhitespaceHandling::None;
}

/*
 * ParseFile
 */
int MyXmlParser::ParseFile() {

	while ( this->xmlTextReader->Read() ) {
		if ( this->xmlTextReader->HasAttributes ) {
			int count = this->xmlTextReader->AttributeCount;
			for ( int i=0; i < count; i++ ) {
				this->xmlTextReader->MoveToAttribute( i );
				Diagnostics::Debug::WriteLine( "Attr name: " + xmlTextReader->Name + "; Attr value: " + xmlTextReader->Value );
			}
		}
		this->xmlTextReader->MoveToElement ();
		Diagnostics::Debug::WriteLine("Name: " + xmlTextReader->Name + "; Type: " + PrintXmlNodeType( xmlTextReader->NodeType ) );
	}

	return 1;
}

/*
 * ParseFabricant
 */
int MyXmlParser::ParseFabricant(List<MyFabricant^>^ lpFabricantsList) {

	String^ alpFabricantCode;
	String^ alpFabricantNom;
	String^ alpCouponNom;
	String^ alpCouponCode;
	String^ alpCouponPrix;
	String^ alpCouponQuantite;
	String^ alpTag;
	MyFabricant^ lpNewFabricant;

	while ( this->xmlTextReader->Read() ) {
		if ( this->xmlTextReader->NodeType == XmlNodeType::Element ) {
			if ( this->xmlTextReader->Name->CompareTo( "Fabricant" ) == 0 ) {
				lpNewFabricant = nullptr;
				alpFabricantCode = alpFabricantNom = nullptr;
				Diagnostics::Debug::WriteLine( "Nouveau fabricant: " );
				if ( this->xmlTextReader->HasAttributes ) {
					int count = this->xmlTextReader->AttributeCount;
					for (int i = 0; i < count; i++) {
						this->xmlTextReader->MoveToAttribute( i );
						if ( this->xmlTextReader->Name->CompareTo( "nom" ) == 0 ) {
							alpFabricantNom = this->xmlTextReader->Value;
							Diagnostics::Debug::WriteLine( "\tnom: " + alpFabricantNom );
						} else if ( this->xmlTextReader->Name->CompareTo( "code" ) == 0 ) {
							alpFabricantCode = this->xmlTextReader->Value;
							Diagnostics::Debug::WriteLine( "\tcode: " + alpFabricantCode );
						}
					}
					if ( ( alpFabricantNom != nullptr ) && ( alpFabricantCode != nullptr ) ) {
						lpNewFabricant = gcnew MyFabricant(alpFabricantNom, alpFabricantCode);
					}
				}
				this->xmlTextReader->MoveToElement();
			} else if ( this->xmlTextReader->Name->CompareTo( "Coupon" ) == 0 ) {
				// nouveau coupon
				if ( lpNewFabricant != nullptr ) {
					alpCouponNom = alpCouponCode = alpCouponPrix = alpCouponQuantite = nullptr;
					if ( this->xmlTextReader->HasAttributes ) {
						int count = this->xmlTextReader->AttributeCount;
						for (int i = 0; i < count; i++) {
							this->xmlTextReader->MoveToAttribute( i );
							if ( this->xmlTextReader->Name->CompareTo( "nom" ) == 0 ) {
								alpCouponNom = this->xmlTextReader->Value;
								Diagnostics::Debug::WriteLine( "\tnom: " + alpCouponNom );
							} else if ( this->xmlTextReader->Name->CompareTo( "code" ) == 0 ) {
								alpCouponCode = this->xmlTextReader->Value;
								Diagnostics::Debug::WriteLine( "\tcode: " + alpCouponCode );
							} else if ( this->xmlTextReader->Name->CompareTo( "prix" ) == 0 ) {
								alpCouponPrix = this->xmlTextReader->Value;
								Diagnostics::Debug::WriteLine( "\tprix: " + alpCouponPrix );
							} else if ( this->xmlTextReader->Name->CompareTo( "quantite" ) == 0 ) {
								alpCouponQuantite = this->xmlTextReader->Value;
								Diagnostics::Debug::WriteLine( "\tquantite: " + alpCouponQuantite );
							} else if ( this->xmlTextReader->Name->CompareTo( "tag" ) == 0 ) {
								alpTag = this->xmlTextReader->Value;
								Diagnostics::Debug::WriteLine( "\ttag: " + alpTag );
							}
						}
						if ( ( alpCouponNom != nullptr ) && ( alpCouponCode != nullptr ) && ( alpCouponPrix != nullptr ) && ( alpCouponQuantite != nullptr ) && ( alpTag != nullptr ) ) {
							MyCoupon^ lpNewCoupon = gcnew MyCoupon(alpCouponNom, alpCouponCode, alpCouponPrix, alpCouponQuantite, alpTag );
							lpNewFabricant->addOneCoupon( lpNewCoupon );
						}
					}
					this->xmlTextReader->MoveToElement();
				}
			} else if ( this->xmlTextReader->Name->CompareTo( "Sauvegarde" ) == 0 ) {
				if ( this->xmlTextReader->HasAttributes ) {
						int count = this->xmlTextReader->AttributeCount;
						for (int i = 0; i < count; i++) {
							this->xmlTextReader->MoveToAttribute( i );
							if ( this->xmlTextReader->Name->CompareTo( "date" ) == 0 ) {
								this->lastSaveDate = this->xmlTextReader->Value;
							}
						}
				}
				this->xmlTextReader->MoveToElement();
			}
		} else if ( this->xmlTextReader->NodeType == XmlNodeType::EndElement ) {
			if ( this->xmlTextReader->Name->CompareTo("Fabricant") == 0 ) {
				// Maintenant, on peut sauvegarder le fournisseur
				if ( lpNewFabricant != nullptr ) {
					lpFabricantsList->Add(lpNewFabricant);
				}
			}
		}
	}

	return 1;
}

/*
 * PrintXmlNodeType
 */
String^ MyXmlParser::PrintXmlNodeType(XmlNodeType nodeType) {

	String^ ret = nullptr;

	switch (nodeType) {
	case XmlNodeType::Element:
		ret = "Element";
		break;
	case XmlNodeType::Comment:
		ret = "Comment";
		break;
	case XmlNodeType::EndElement:
		ret = "End Element";
		break;
	case XmlNodeType::DocumentType:
		ret = "Document Type";
		break;
	case XmlNodeType::XmlDeclaration:
		ret = "XML Declaration";
		break;
	case XmlNodeType::Text:
		ret = "Text";
		break;
	case XmlNodeType::EntityReference:
		ret = "Entity Reference";
		break;
	case XmlNodeType::CDATA:
		ret = "CDATA";
		break;
	default:
		ret = "not defined";
	}
	return ret;
}

/*
 * Getter method: getLastSaveDate
 */
String^ MyXmlParser::getLastSaveDate() {

	return this->lastSaveDate;
}