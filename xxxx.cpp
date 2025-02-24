#include <graphics.h>
#include <cmath>

#define PI 3.14159265
int window_x = 1000, window_y = 800;

void my_putpixel(int x, int y, int color) {
    int screen_width = getmaxx();
    int screen_height = getmaxy();
    int new_x = screen_width / 2 + x;
    int new_y = screen_height / 2 - y;
    putpixel(new_x, new_y, 7);
}

void drawLine(int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = std::max(dx, dy);
    float x_inc = (float)(x2 - x1) / steps;
    float y_inc = (float)(y2 - y1) / steps;
    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        my_putpixel(round(x), round(y), color);
        x += x_inc;
        y += y_inc;
    }
}

void drawRotatedRectangle(int x1, int y1, int x2, int y2, double angle, double scale) {
    double rad = angle * PI / 180.0;

    int cx = 0;
    int cy = 0;

    int corners[4][2] = {
        {x1, y1},
        {x2, y1},
        {x2, y2},
        {x1, y2}
    };

    int rotatedCorners[4][2];

    for (int i = 0; i < 4; i++) {
        int x = corners[i][0] - cx;
        int y = corners[i][1] - cy;

        x *= scale;
        y *= scale;

        rotatedCorners[i][0] = cx + (x * cos(rad) - y * sin(rad));
        rotatedCorners[i][1] = cy + (x * sin(rad) + y * cos(rad));
    }

    drawLine(rotatedCorners[0][0], rotatedCorners[0][1], rotatedCorners[1][0], rotatedCorners[1][1], RED);
    drawLine(rotatedCorners[1][0], rotatedCorners[1][1], rotatedCorners[2][0], rotatedCorners[2][1], RED);
    drawLine(rotatedCorners[2][0], rotatedCorners[2][1], rotatedCorners[3][0], rotatedCorners[3][1], RED);
    drawLine(rotatedCorners[3][0], rotatedCorners[3][1], rotatedCorners[0][0], rotatedCorners[0][1], RED);
}

int main() {
    int gd = DETECT, gm;
    initwindow(window_x, window_y, "Scaling and Rotating");

    // for (int x = -getmaxx() / 2; x < getmaxx() / 2; x++) {
    //     my_putpixel(x, 0, WHITE);
    // }
    // for (int y = -getmaxy() / 2; y < getmaxy() / 2; y++) {
    //     my_putpixel(0, y, WHITE);
    // }

    int x1 = 0, y1 = 100, x2 = 100, y2 = 200;

    double scale = 1.0;
    bool reverse = false;

    for (double angle = 0; angle < 720; angle += 10) {
        cleardevice();

        // for (int x = -getmaxx() / 2; x < getmaxx() / 2; x++) {
        //     my_putpixel(x, 0, WHITE);
        // }
        // for (int y = -getmaxy() / 2; y < getmaxy() / 2; y++) {
        //     my_putpixel(0, y, WHITE);
        // }

        drawRotatedRectangle(x1, y1, x2, y2, angle, scale);

        if (!reverse) {
            scale += 0.1;
            if (scale >= 2.0) reverse = true;
        } else {
            scale -= 0.1;
            if (scale <= 1.0) reverse = false;
        }

        delay(75);
    }

    getch();
    closegraph();
    return 0;
}