// Width of Line code in computer graphics
#include <stdio.h>
// Required Header File
#include <conio.h>
#include <graphics.h>
int main()
{

	// Configuring The Graphics File
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");

	// Normal Width Line
	setlinestyle(0, 0, 1);
	line(30, 40, 70, 40);

	// Width Line
	setlinestyle(0, 0, 10);
	line(30, 30, 100, 100);
	getch();

	// Closing The Graphics
	closegraph();
	return 0;
}
