#include "lv_lib_100ask.h"
#include "test/lv_100ask_2048_test/simple_test.h"
#include <unistd.h>
#include <stdio.h>
#include "lv_conf.h"
#include "lv_drivers/wayland/wayland.h"
#include <time.h>
#include <stdlib.h>

#define H_RES (500)
#define V_RES (500)
lv_disp_t * disp;


int main(void)
{    
    lv_init();
    lv_wayland_init();
    printf("[DEMO]: wayland initialized\n");

    disp = lv_wayland_create_window(H_RES, V_RES, "Window Title", NULL);
    printf("[DEMO]: window created\n");
    lv_disp_set_default(disp);
    lv_group_t * g = lv_group_create();
    lv_group_set_default(g);
    lv_indev_set_group(lv_wayland_get_keyboard(disp), g);
    printf("[DEMO]: set default\n");
    lv_100ask_2048_simple_test();
    //lv_demo_music();
    printf("[DEMO]: demo started\n");
    while(lv_wayland_window_is_open(disp)){
        usleep(1000 * lv_wayland_timer_handler());                 //! run lv task at the max speed
    }
    lv_wayland_deinit();
    return 0;
}