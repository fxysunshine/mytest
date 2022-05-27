set(Programs
  bitNum
  consolidate_forward
  delDigitals
  heap_overlap
  memory_profile
  offsetof
  symmetry
  test_process_stack
  vuln
  weak_symbol
)

set(WaylandTests
    cursor
    seat
    pointer
)

foreach(program ${Programs})
  SINGLE_BINARY_TARGET_C(${program})
endforeach(program)

foreach(program ${WaylandTests})
  add_executable(${program} ${program}.c)
  target_link_libraries(${program} PRIVATE
    EGL
    GLESv2
    wayland-client
    wayland-cursor
    wayland-egl
  )
endforeach(program)
