/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN = 1;
const int LED = 0;


int main() {
  stdio_init_all();

  gpio_init(BTN);
  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);

  
  gpio_init(LED);
  gpio_set_dir(LED, GPIO_OUT);



  

  while (true) {
    if (!gpio_get(BTN)) {
      gpio_put(LED, 1);
      sleep_ms(300);
      gpio_put(LED, 0);
         
      
    }
    
     
    }
  }
