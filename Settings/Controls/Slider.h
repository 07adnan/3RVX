// Copyright (c) 2015, Matthew Malensek.
// Distributed under the BSD 2-Clause License (see LICENSE.txt for details)

#pragma once

#include <Windows.h>
#include <CommCtrl.h>

#include "Control.h"

class Slider : public Control {
public:
    Slider(int id, Dialog &parent) :
    Control(id, parent, false) {

    }

    void Buddy(Control *buddy, bool bottomOrRight = true);

    int Position();
    void Position(int position);

    /// <summary>Sets the range (min, max) for the slider control.</summary>
    /// <param name="lo">Lower bound for the slider.</param>
    /// <param name="hi">Upper bound for the slider.</param>
    void Range(int lo, int hi);

    virtual BOOL Scroll(bool horizontal, WORD request, WORD position);

private:
    HWND _buddyWnd;

public:
    /* Event Handlers */
    std::function<bool()> OnSlide;

};