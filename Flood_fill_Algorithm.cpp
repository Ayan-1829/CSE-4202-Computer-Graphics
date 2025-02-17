#include <graphics.h>
#include <iostream>

using namespace std;
int window_x = 250, window_y = 250;

void _rectangle(int x1, int y1, int x2, int y2, int color)
{
    for (int i = x1; i < x2; i++)
    {
        putpixel(i, y1, color);
        // delay(1);
        putpixel(i, y2, color);
        // delay(1);
    }
    for (int i = y1; i < y2; i++)
    {
        putpixel(x1, i, color);
        // delay(1);
        putpixel(x2, i, color);
        // delay(1);
    }
    return;
}

void add_noise(int x, int y, int color)
{
    putpixel(x, y, color);
}

void BFA(int x, int y, int b_col, int f_col)
{
    // window check
    if (x >= window_x || x <= 0 || y >= window_y || y <= 0)
    {
        return;
    }
    if (getpixel(x, y) == b_col || getpixel(x, y) == f_col)
    {
        return;
    }
    putpixel(x, y, f_col);
    // delay(5);
    BFA(x + 1, y, b_col, f_col);
    BFA(x, y + 1, b_col, f_col);
    BFA(x - 1, y, b_col, f_col);
    BFA(x, y - 1, b_col, f_col);
}

int main()
{
    int gd = DETECT, gm;
    initwindow(window_x, window_y, "Boundary Fill Drawing Algorithm"); // Initialize graphics window

    int x1 = 50, x2 = window_x-50, y1 = 50, y2 = window_y-50;
    int boundary_color = 7;
    int fill_color = 3;
    int background_color = getpixel(x1, y1);

    _rectangle(x1, y1, x2, y2, boundary_color);

    int seed_x = (x1 + x2) / 2, seed_y = (y1 + y2) / 2;
    add_noise(seed_x, y2, background_color);

    BFA(seed_x, seed_y, boundary_color, fill_color);

    getch();      // Wait for a key press
    // closegraph(); // Close the graphics window

    return 0;
}