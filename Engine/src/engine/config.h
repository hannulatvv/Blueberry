#pragma once

#include "input.h"
#include "types.h"

typedef struct config {
    u8 keybinds[5];
} Config_state;

void config_init(void);
void config_key_bind(Input_key key, const char *key_name);