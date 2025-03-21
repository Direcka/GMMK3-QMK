//  !!! DO NOT ADD #pragma once !!! //
#ifdef ENABLE_RGB_MATRIX_CUSTOM1

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(custom_effect)

// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS



hsv_t BREATHING_math(hsv_t hsv, uint8_t i, uint8_t time) {
  hsv.v = scale8(abs8(sin8(time / 2) - 128) * 2, hsv.v);
  return hsv;
}
// e.g: A simple effect, self-contained within a single method
static bool custom_effect(effect_params_t* params) {
  return effect_runner_i(params, &BREATHING_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
