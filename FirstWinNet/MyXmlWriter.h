#pragma once

#include "MyFabricant.h"

using namespace System::Xml;
using namespace System::IO;
using namespace System::Text;

ref class MyXmlWriter {
public:
	MyXmlWriter(void);
	void SaveFabricantsList( List<MyFabricant^>^, Stream^ );
	void SaveFabricantsList( Stream^ );
};

