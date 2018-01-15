message("foreach 1")
foreach(arg
	first
	second
	third
    )
  message("${arg}")
endforeach()

message("\n foreach range")

# test foreach for range
foreach(i RANGE 10)
  message(${i})
endforeach()

message("\n foreach range with step")
foreach(i RANGE 2 10 2)
  message(${i})
endforeach()

message("\n foreach in list")
