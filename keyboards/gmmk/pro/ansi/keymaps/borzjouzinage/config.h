#pragma once

// RGB Effects configuration
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES // Reactive and splash
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS // Heatmap, rain
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    
    // Disabling some RGB effects
    #undef ENABLE_RGB_MATRIX_GRADIANT_UP_DOWN    // top-down rainbow  
    #undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT // left-right rainbow
    #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT // pinwheel effects
    #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #undef ENABLE_RGB_MATRIX_CYCLE_ALL         // rainbow effects
    #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #undef ENABLE_RGB_MATRIX_DUAL_BEACON              
    #undef ENABLE_RGB_MATRIX_RAINBOW_BEACON             
    #undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS 
    #undef ENABLE_RGB_MATRIX_RAINDROPS
    #undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#endif