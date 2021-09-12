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
