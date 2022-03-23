#include "HelperFunctions.h"


COORD getConsoleSize()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(handle, &consoleInfo);
	
	short x = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	short y = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	return COORD{ x, y };
}

COORD getConsoleFont()
{
	HANDLE handl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO info;
	GetCurrentConsoleFont(handl, false, &info);
	return info.dwFontSize;
}