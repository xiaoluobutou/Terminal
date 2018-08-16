/*++
Copyright (c) Microsoft Corporation

Module Name:
- utils.hpp

Abstract:
- This moduile contains utility math functions that help perform calculations elsewhere in the console

Author(s):
- Paul Campbell (PaulCam)     2014
- Michael Niksa (MiNiksa)     2014
--*/
#pragma once

#include "conapi.h"
#include "server.h"

#include "..\server\ObjectHandle.h"

#define RECT_WIDTH(x) ((x)->right - (x)->left)
#define RECT_HEIGHT(x) ((x)->bottom - (x)->top)

short CalcWindowSizeX(const SMALL_RECT& rect) noexcept;
short CalcWindowSizeY(const SMALL_RECT& rect) noexcept;
short CalcCursorYOffsetInPixels(const short sFontSizeY, const ULONG ulSize) noexcept;
WORD ConvertStringToDec(_In_ PCWSTR pwchToConvert, _Out_opt_ PCWSTR * const ppwchEnd) noexcept;

class Utils
{
public:
    static void s_IncrementCoordinate(const COORD bufferSize, COORD& coord) noexcept;
    static void s_DecrementCoordinate(const COORD bufferSize, COORD& coord) noexcept;

    static bool s_DoDecrementScreenCoordinate(const SMALL_RECT srectEdges, COORD& coordScreen) noexcept;
    static bool s_DoIncrementScreenCoordinate(const SMALL_RECT srectEdges, COORD& coordScreen) noexcept;

    static int s_CompareCoords(const COORD bufferSize, const COORD first, const COORD second) noexcept;
    static int s_CompareCoords(const COORD coordFirst, const COORD coordSecond) noexcept;

    static COORD s_GetOppositeCorner(const SMALL_RECT srRectangle, const COORD coordCorner) noexcept;
    static bool s_AddToPosition(const SMALL_RECT srectEdges, const int iAdd, COORD& coordPosition) noexcept;

    static SMALL_RECT s_GetCurrentBufferEdges() noexcept;
};
