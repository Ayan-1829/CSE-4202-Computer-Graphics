#include <graphics.h>
#include <iostream>

using namespace std;

// Function to draw a circle using Midpoint algorithm
void drawCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 1 - r;

    int cnt = 0;

    while (x <= y)
    {
        delay(20);
        cnt += 1;
        // Plot the points in all octants
        putpixel(xc + x, yc + y, 2);
        putpixel(xc - x, yc + y, 3);
        putpixel(xc + x, yc - y, 4);
        putpixel(xc - x, yc - y, 5);
        putpixel(xc + y, yc + x, 6);
        putpixel(xc - y, yc + x, 7);
        putpixel(xc + y, yc - x, 8);
        putpixel(xc - y, yc - x, 9);

        // Update the decision parameter
        if (d <= 0)
        {
            d = d + 2 * x + 3;
        }
        else
        {
            d = d + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    cout << cnt << endl;
}

int main()
{
    int gd = DETECT, gm;
    initwindow(800, 600, "Mid point Circle Drawing Algorithm"); // Initialize graphics window

    int xc = 400, yc = 300, r = 200;

    // cout << "Enter the center coordinates (xc, yc): ";
    // cin >> xc >> yc;

    // cout << "Enter the radius of the circle: ";
    // cin >> r;

    // Draw the circle using Bresenham's algorithm
    drawCircle(xc, yc, r);

    getch();      // Wait for a key press
    closegraph(); // Close the graphics window

    return 0;
}