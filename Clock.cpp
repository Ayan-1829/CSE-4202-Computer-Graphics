#include <graphics.h>
#include <math.h>

int radius = 200;
int center_x, center_y;
int r_sec = radius - 20;
int r_min = radius - 50;

void boundary()
{

    // circle(center_x, center_y, radius);

    for (int i = -180; i <= 180; i += 6)
    {
        circle(center_x + radius * cos(i * acos(-1) / 180.0), center_y + radius * sin(i * acos(-1) / 180.0), 2);
    }

    int font = 6, direction = 0, font_size = 5;
    settextstyle(font, direction, font_size);
    outtextxy(center_x + r_sec, center_y - 20, "3");
    outtextxy(center_x - 16, center_y + r_sec, "6");
    outtextxy(center_x - r_sec - 40, center_y - 20, "9");
    outtextxy(center_x - 32, center_y - r_sec - 38, "12");
}

void second(int x, int y)
{
    line(center_x, center_y, center_x + x, center_y + y);
}
void minute(int x, int y)
{
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(center_x, center_y, center_x + x, center_y + y);
    // line(center_x-1, center_y-1, center_x + x, center_y + y);
    // line(center_x+1, center_y+1, center_x + x, center_y + y);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
}

void clock()
{
    int x_min = 0, y_min = r_sec;
    double angle_min = -90;
    double pi = acos(-1);

    for (int j = 0; j < 60; j++, angle_min += 6)
    {

        x_min = r_min * cos(angle_min * pi / 180.0);
        y_min = r_min * sin(angle_min * pi / 180.0);
        // minute(x_min, y_min);

        int x_sec = 0, y_sec = r_sec - 20;
        double angle_sec = -90;
        for (int k = 0; k < 60; k++, angle_sec += 6)
        {
            boundary();
            x_sec = r_sec * cos(angle_sec * pi / 180.0);
            y_sec = r_sec * sin(angle_sec * pi / 180.0);

            minute(x_min, y_min);
            second(x_sec, y_sec);
            delay(100);
            cleardevice();
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    center_x = getmaxx() / 2;
    center_y = getmaxy() / 2;

    clock();

    getch();
    closegraph();
    return 0;
}