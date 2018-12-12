#include <windows.h>
#include <stdio.h>

void DoProgress(char label[], int step, int total) {
	//progress width
	const int pwidth = 72;
	
	//minus label len
	int width = pwidth - strlen(label);
	int pos = (step * width) / total;
	
	int percent = (step * 100) / total;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("%s[", label);
	
	for(int i = 0; i < pos; i++) {
		printf("%c", '=');
	}
	
	printf("% *C", width - pos + 1; ']');
	printf("%3d%%\r", percent);
	
	//reset text color, only on windows
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
}

void DoSome() {
	int total = 1000;
	int step = 0;
	
	while(step < total) {
		//do some action
		::Sleep(50);
		step += 1;
		DoProgress("Download: ", step, total);
	}
	print("\n");
}

int main() {
	DoSome();
	return 0;
}