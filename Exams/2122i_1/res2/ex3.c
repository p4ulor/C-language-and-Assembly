#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

struct pinctrl_pin { uint32_t pinmux; uint32_t pincfg; };

struct pinctrl_state { struct pinctrl_pin *pins; uint8_t pin_cnt; };

struct pinctrl_config { uint8_t state_cnt; struct pinctrl_state *states[]; };

uint32_t get_pincfg(struct pinctrl_config *config, int state, int pin) {
    return config->states[state]->pins[pin].pincfg;
}

int main(){
    
}