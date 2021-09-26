set(Programs
  queue_safe
  atomic
  move
  quick_sort
  stack_safe
  stackOOB
  async
  future
)

foreach(program ${Programs})
  SINGLE_BINARY_TARGET(${program})
endforeach(program)
