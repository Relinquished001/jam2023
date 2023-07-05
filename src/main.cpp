#include <cstdio>
#include <cstdint>
#include <libdragon.h>
#include <memory>
#include <stdexcept>

#include "test.hpp"
#include "camera.hpp"

// Test global constructor
TestClass globalClass;

int main(void)
{
    Camera cam;

    debug_init_isviewer();
    debug_init_usblog();
    controller_init();

    auto localClass = std::make_unique<TestClass>();

    console_init();
    console_set_render_mode(RENDER_MANUAL);


    while(1)
    {
        console_clear();
        printf("Global class method: %d\n", globalClass.f1());
        printf("Local class method: %d\n", localClass->f1());
        printf("Exception data: %d\n", localClass->exc());
        printf("\nPress A to crash (test uncaught C++ exceptions)\n");
        console_render();

        controller_scan();
        struct controller_data keys = get_keys_down();
        if (keys.c[0].A)
            localClass->crash();
        
    }
}
