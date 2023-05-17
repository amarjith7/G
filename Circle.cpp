#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

class bresen
{
    float x, y, a, b, r, p;

public:
    void get();
    void cal();
};

int main()
{
    bresen b;
    b.get();
    b.cal();
    getch();
}

void bresen::get()
{
    std::cout << "ENTER CENTER AND RADIUS\n";
    std::cout << "ENTER (a, b): ";
    std::cin >> a >> b;
    std::cout << "ENTER r: ";
    std::cin >> r;
}

void bresen::cal()
{
    int gdriver = DETECT, gmode, errorcode;
    int midx, midy, i;

    initgraph(&gdriver, &gmode, "");

    errorcode = graphresult();
    if (errorcode != grOk)
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);
    }

    x = 0;
    y = r;

    putpixel(a, b + r, RED);
    putpixel(a, b - r, RED);
    putpixel(a - r, b, RED);
    putpixel(a + r, b, RED);

    p = 5 / 4 - r;
    while (x <= y)
    {
        if (p < 0)
        {
            p += (4 * x) + 6;
        }
        else
        {
            p += (2 * (x - y)) + 5;
            y--;
        }
        x++;

        putpixel(a + x, b + y, RED);
        putpixel(a - x, b + y, RED);
        putpixel(a + x, b - y, RED);
        putpixel(a - x, b - y, RED);
        putpixel(a + y, b + x, RED);
        putpixel(a - y, b + x, RED);
        putpixel(a + y, b - x, RED);
        putpixel(a - y, b - x, RED);
    }

    closegraph();
}
