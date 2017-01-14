#include <windows.h>

int main()
{
	LoadLibrary("msvcrt.dll");
	system("command.com");
	return 0;
}