#include <stdio.h>
#include <graphics.h>
int window_x = 500, window_y = 500;
void drawline(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0, dy = y1 - y0, x = x0, y = y0;
    int p = 2 * dy - dx;
    if (dy == 0)
    {
        for (int i = x0; i <= x1; i++)
        {
            putpixel(i, y, 7);
        }
        return;
    }
    else if (dx == 0)
    {
        for (int i = y0; i <= y1; i++)
        {
            putpixel(x, i, 7);
        }
        return;
    }
    while (x < x1)
    {
        // delay(20);
        if (p >= 0)
        {
            putpixel(x, y, 7);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, 7);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
}
int main()
{
    int gdriver = DETECT, gmode, error, x0, y0, x1, y1;
    initwindow(window_x, window_y, "Scaling and Rotating");
    // printf("Enter co-ordinates of first point: ");
    // scanf("%d%d", &x0, &y0);
    // printf("Enter co-ordinates of second point: ");
    // scanf("%d%d", &x1, &y1);
    // drawline(x0, y0, x1, y1);
    drawline(10, 10, 200, 10);
    getch();
    return 0;
}