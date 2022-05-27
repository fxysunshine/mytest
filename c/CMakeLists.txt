set(Programs
  bitNum
  consolidate_forward
  delDigitals
  heap_overlap
  memory_profile
  offsetof
  pointer
  symmetry
  test_process_stack
  vuln
  weak_symbol
)

foreach(program ${Programs})
  SINGLE_BINARY_TARGET_C(${program})
endforeach(program)

add_executable(cursor cursor.c)
target_link_libraries(cursor PRIVATE
    EGL
    GLESv2
    wayland-client
    wayland-cursor
    wayland-egl
)
