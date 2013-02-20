// FirstWinNet.cpp : main project file.

#include "stdafx.h"
#include <windows.h>
#include "Form1.h"
#include "StartDialog.h"

#pragma comment(lib, "user32.lib")

using namespace FirstWinNet;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	bool aUseMnemonics = true;

	SystemParametersInfo(
	  SPI_SETKEYBOARDCUES,
	  0,
	  &aUseMnemonics,
	  0);

	// Create the main window and run it
	Application::Run( gcnew StartDialog() );
//	Application::Run(gcnew Form1());
	return 0;
}
