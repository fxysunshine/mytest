set(Programs
  queue_safe
  atomic
  move
  quick_sort
  stack_safe
  stackOOB
  async
  future
  process_name
)

foreach(program ${Programs})
  SINGLE_BINARY_TARGET(${program})
endforeach(program)
