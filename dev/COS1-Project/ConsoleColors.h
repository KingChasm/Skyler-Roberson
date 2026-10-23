#pragma once

#include <iostream>
#include <windows.h>

namespace ConsoleColors
{
    // Standard console colors
    constexpr WORD White = 7;
    constexpr WORD Green = 10;
    constexpr WORD Cyan = 11;
    constexpr WORD Red = 12;
    constexpr WORD Purple = 13;
    constexpr WORD Yellow = 14;
    constexpr WORD Orange = 6;

    // Changes the console text color.
    inline void SetColor(WORD color)
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

        if (console != INVALID_HANDLE_VALUE &&
            console != nullptr)
        {
            SetConsoleTextAttribute(console, color);
        }
    }

    // Restores the default text color.
    inline void ResetColor()
    {
        SetColor(White);
    }
}