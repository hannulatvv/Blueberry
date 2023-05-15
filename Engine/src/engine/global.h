#pragma once

#include "render.h"
#include "config.h"
#include "input.h"
#include "time.h"

typedef struct global {
    Render_State render;
    Config_state config;
    Input_state input;
    Time_state time;
} Global;

extern Global global;