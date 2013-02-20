#pragma once
ref class MyBeep
{
public:
	enum class MessageBeepType {
	Default = -1,
	Ok = 0x00000000,
	Error = 0x00000010,
	Question = 0x00000020,
	Warning = 0x00000030,
	Information = 0x00000040
	};

public:
	static void beep();
	static void beepWarn();
	static void beepSystem( MessageBeepType );

};

