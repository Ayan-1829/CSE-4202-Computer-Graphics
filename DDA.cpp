#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int round(float x)
{
    return (int)x + 0.5;
}
int abs(int x)
{
    int out;
    if (x > 0)
        out = x;
    else
        out = x * (-1);
    return out;
}
void DDA(int x1, int y1, int x2, int y2)
{
    int dx, dy, steps, i;
    float X, Y, xi, yi;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xi = dx / (float)steps;
    yi = dy / (float)steps;
    X = x1;
    Y = y1;
    for (i = 0; i < steps; i++)
    {
        delay(20);
        X += xi;
        Y += yi;
        if (i % 2 != 0)
            
            putpixel(X, Y, WHITE);
    }
}
int main()
{
    int a, b, c, d;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    // printf("Enter the coordinates for start point\n");
    // scanf("%d%d", &a, &b);
    // printf("Enter the coordinates for the second point\n");
    // scanf("%d%d", &c, &d);
    // DDA(a, b, c, d);
    DDA(10, 10, 500, 300);
    getch();
    closegraph();
    return 0;
}