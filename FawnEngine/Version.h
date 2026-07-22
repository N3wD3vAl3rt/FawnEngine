#pragma once

#include <string>

#define FAWN_ENGINE_VERSION_MAJOR 0
#define FAWN_ENGINE_VERSION_MINOR 10
#define FAWN_ENGINE_VERSION_PATCH 1

#define FAWN_ENGINE_VERSION_STRING "0.10.1"

namespace Version
{
    inline std::string GetVersion()
    {
        return FAWN_ENGINE_VERSION_STRING;
    }

    inline std::wstring GetVersionW()
    {
        return L"0.10.1";
    }

    inline std::wstring GetWindowTitle()
    {
        return L"Fawn Engine v" + GetVersionW();
    }
}