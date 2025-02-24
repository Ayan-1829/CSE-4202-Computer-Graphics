#include <stdio.h>
#include <graphics.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
float pi = acos(-1);

int window_x = 1000, window_y = 750;
int screen_x_min = 10, screen_x_max = window_x/2, screen_y_min = 10, screen_y_max = window_y - 10;

void print(vector<vector<float>> vc)
{
    for (auto it : vc)
    {
        for (auto jt : it)
        {
            cout << jt << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void my_putpixel(int x, int y)
{
    int val_x = x + window_x / 2;
    int val_y = window_y / 2 - y;

    if (val_x < screen_x_min || val_x > screen_x_max || val_y < screen_y_min || val_y > screen_y_max)
        return;

    putpixel(val_x, val_y, 7);
}

void draw_line(float x1, float y1, float x2, float y2)
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
        // delay(20);
        X += xi;
        Y += yi;
        if (i % 2 != 0)
            my_putpixel(X, Y);
    }
}

void draw_polygon(vector<pair<float, float>> points)
{
    int n = points.size();
    for (int i = 1; i <= n; i++)
    {
        draw_line(points[i % n].first, points[i % n].second, points[i - 1].first, points[i - 1].second);
    }
}

vector<vector<float>> multiplyMatrices(vector<vector<float>> A, vector<vector<float>> B)
{
    vector<vector<float>> C(A.size(), vector<float>(B[0].size(), 0));
    for (float i = 0; i < 3; i++)
    {
        for (float j = 0; j < 3; j++)
        {
            C[i][j] = 0;
            for (float k = 0; k < 3; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vector<vector<float>> transformation_matric(float sx, float sy, float tx, float ty, float theta)
{
    theta = theta * pi / 180.0;

    vector<vector<float>> T = {{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};
    vector<vector<float>> S = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
    vector<vector<float>> T_ = {{1, 0, -tx}, {0, 1, -ty}, {0, 0, 1}};
    vector<vector<float>> R = {{cos(theta), -sin(theta), 0}, {sin(theta), cos(theta), 0}, {0, 0, 1}};

    vector<vector<float>> mul = multiplyMatrices(T, S);
    mul = multiplyMatrices(mul, T_);
    mul = multiplyMatrices(mul, R);

    return mul;
}

vector<pair<float, float>> transform_points(vector<pair<float, float>> vc, float sx, float sy, float tx, float ty, float theta)
{
    vector<pair<float, float>> ans;
    for (auto it : vc)
    {
        vector<vector<float>> P = {{it.first}, {it.second}, {1}};
        vector<vector<float>> RT_ST = transformation_matric(sx, sy, tx, ty, theta);
        vector<vector<float>> mul = multiplyMatrices(RT_ST, P);
        ans.push_back({mul[0][0], mul[1][0]});
    }
    return ans;
}

signed main()
{

    initwindow(window_x, window_y, "Scaling and Rotating");

    // co-ordintates
    float x1 = 20, y1 = 100;
    float x2 = 100, y2 = 100;
    float x3 = 100, y3 = 10;
    float x4 = 20, y4 = 10;

    float sx1 = screen_x_min-window_x/2, sy1 = screen_y_min-window_y/2;
    float sx2 = screen_x_max-window_x/2, sy2 = screen_y_min-window_y/2;
    float sx3 = screen_x_max-window_x/2, sy3 = screen_y_max-window_y/2;
    float sx4 = screen_x_min-window_x/2, sy4 = screen_y_max-window_y/2;

    vector<pair<float, float>> points = {{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}};
    vector<pair<float, float>> screen = {{sx1, sy1}, {sx2, sy2}, {sx3, sy3}, {sx4, sy4}};

    draw_polygon(screen);
    draw_polygon(points);

    float theta = 10;
    auto x = points;

    while (1)
    {
        for (float scale = 1.1; scale <= 2.0; scale += 0.1)
        {
            auto s_x = transform_points(points, scale, scale, (x1 + x2) / 2.0, (y1 + y3) / 2.0, 0);
            x = transform_points(s_x, 1, 1, 0, 0, theta);

            delay(100);
            cleardevice();
            draw_polygon(screen);
            draw_polygon(x);
            theta += 10;
        }
        for (float scale = 1.9; scale >= 1.0; scale -= 0.1)
        {
            auto s_x = transform_points(points, scale, scale, (x1 + x2) / 2.0, (y1 + y3) / 2.0, 0);
            x = transform_points(s_x, 1, 1, 0, 0, theta);

            delay(100);
            cleardevice();
            draw_polygon(screen);
            draw_polygon(x);
            theta += 10;
        }
    }

    getch();
    return 0;
}