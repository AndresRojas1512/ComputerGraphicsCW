#ifndef COLORCONFIG_HPP
#define COLORCONFIG_HPP

struct Color
{
    int r, g, b;
    Color(int r_, int g_, int b_) : r(r_), g(g_), b(b_) {}

    static const Color GREEN;
    static const Color DARK_GREEN;

    static const Color SILVER;
    static const Color GRAY;
    static const Color DIM_GRAY;

    static const Color YELLOW;
    static const Color OLIVE;

    static const Color BLUE;
    static const Color DARK_BLUE;

    static const Color KHAKI;
    static const Color DARK_KHAKI;

    static const Color LIGHT_SILVER;
    static const Color DARK_LIGHT_SILVER;

    static const Color LIGHT_BLUE;
    static const Color DARK_LIGHT_BLUE;

    static const Color RED;
    static const Color DARK_RED;

    static const Color DARK_GRAY;
    static const Color DARK_DARK_GRAY;
};

#endif // COLORCONFIG_HPP
