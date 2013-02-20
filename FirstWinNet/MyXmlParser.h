#pragma once

#include "MyCoupon.h"
#include "MyFabricant.h"

using namespace System;
using namespace System::Xml;
using namespace System::Collections::Generic;

ref class MyXmlParser
{
public:
	MyXmlParser(void);
	MyXmlParser(String^);
	~MyXmlParser();
	!MyXmlParser();  // finalizer
	int ParseFile();
	int ParseFabricant(List<MyFabricant^>^);
	String^ getLastSaveDate();
private:
	String^ PrintXmlNodeType(XmlNodeType);
	String^ lastSaveDate;
private:
	XmlTextReader^ xmlTextReader;
};

