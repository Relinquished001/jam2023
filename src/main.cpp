#include <cstdio>
#include <cstdint>
#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>
#include <memory>
#include <stdexcept>
#include <vector>

#include "test.hpp"
#include "vec3.hpp"
#include "vec.hpp"

/*
void render() {
  gl_context_begin();
} // */


// define some colors
constexpr uint32_t
BAKCGROUND = 0x1166ccFF;



// store the three sprites composing the logo
constexpr size_t LOGO_PARTS = 3;
static sprite_t*logo[LOGO_PARTS];


// count the amount of frame elapsed since game started
static volatile size_t frame_counter = 0u;


int main(void)
{
    // highest resolution,
    // shortest depth
    // two buffers
    // no gamma
    // no antialiasing
    display_init(RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);

    dfs_init(DFS_DEFAULT_LOCATION);

    rdp_init();

    controller_init();

    timer_init();

    // read the sprites composing the logo
    const char*const logo_path [LOGO_PARTS] = {"/logo1.sprite", "/logo2.sprite", "/logo3.sprite" };
    int dfs_id;
    for (size_t i = 0; i < LOGO_PARTS; ++i) {

        // open a file, get its size and allocate memory
        dfs_id = dfs_open(logo_path[i]);
        const size_t data_size = dfs_size(dfs_id);
        sprite_t*const sprite = (sprite_t*) malloc(data_size);

        // read the content of the file then close it
        dfs_read(sprite, 1, data_size, dfs_id);
        dfs_close(dfs_id);
        logo[i] = sprite;
    }


    // create a timer to count frames
    //new_timer(TIMER_TICKS(1000000 / 30), TF_CONTINUOUS, [](int){++frame_counter;});


    // infinite loop
    while (true) {
        // surface on which we will draw the sprites
        static display_context_t display = nullptr;

        // wait for a render buffer to be available
        do {display = display_lock();} while (not display);

        // start to draw the screen
        graphics_fill_screen(display, BAKCGROUND);
        graphics_set_color(0xFFFFFFFF, 0x0);

        graphics_draw_sprite_trans(display, 20, 50, logo[0]);

        // buffer flip
        display_show(display);

        // scan controller inputs
        //controller_scan();

    }
}
