#pragma once

#include <string>

#define GENERR  0x100
#define SKINERR 0x200
#define SYSERR  0x400

#define GENERR_NOTFOUND            GENERR + 1
#define GENERR_SETTINGSFILE        GENERR + 2
#define GENERR_MISSING_XML         GENERR + 3

#define SKINERR_INVALID_SKIN       SKINERR + 1
#define SKINERR_INVALID_OSD        SKINERR + 2
#define SKINERR_INVALID_METER      SKINERR + 3
#define SKINERR_INVALID_SLIDER     SKINERR + 4
#define SKINERR_INVALID_BG         SKINERR + 5
#define SKINERR_INVALID_SLIDERTYPE SKINERR + 7
#define SKINERR_NOTFOUND           SKINERR + 8
#define SKINERR_MISSING_XML        SKINERR + 9
#define SKINERR_READERR            SKINERR + 10

#define SYSERR_REGISTERCLASS       SYSERR + 1
#define SYSERR_CREATEWINDOW        SYSERR + 2

class Error {
public:
    static void ErrorMessage(unsigned int error, std::wstring detail = L"") {
        std::wstring msg(L"");

        msg = msg + L"Unknown error occurred: " + std::to_wstring(error);
        if (detail != L"") {
            msg = msg + L"\n" + detail;
        }

        MessageBox(NULL, msg.c_str(), Error::ErrorType(error), MB_ICONERROR);
    }

    static void ErrorMessageDie(unsigned int error, std::wstring detail = L"") {
        ErrorMessage(error, detail);
        exit(EXIT_FAILURE);
    }

private:
    static wchar_t *ErrorType(unsigned int error) {
        if (error & GENERR) {
            return L"3RVX Error";
        } else if (error & SKINERR) {
            return L"Skin Error";
        } else if (error & SYSERR) {
            return L"System Error";
        }

        return L"Error";
    }
};