#pragma once
#include "MyFabricant.h"

ref class MyTomCoFabricant : public MyFabricant, IEquatable<MyTomCoFabricant^>
{
public:
	MyTomCoFabricant(void);

	virtual bool Equals( MyTomCoFabricant^ );
};

