#include "stdafx.h"
#include "MyBeep.h"

using namespace System;
using namespace System::Threading;
using namespace System::Runtime::InteropServices;

// Implicit DLLImport specifying calling convention
extern "C" int __stdcall MessageBeep(int);

void MyBeep::beep() {

	for ( int i = 0; i < 3; i++ ) {
		Console::Beep(500, 200);
		Thread::Sleep(10);
	}
}

void MyBeep::beepWarn() {

	for ( int i = 0; i < 2; i++ ) {
		Console::Beep(500, 150);
		Thread::Sleep(5);
	}
}

void MyBeep::beepSystem(MessageBeepType beepType) {
	MessageBeep( static_cast<int>( beepType ) );
}

