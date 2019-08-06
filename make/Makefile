all: build-in-directives build-in-funcs build-in-vars

build-in-directives:
	@echo "build n directives:"

build-in-funcs:
	@echo "build in fucntions:"
	@echo "subst:"$(subst hello,world,"hello,world")
	@echo "patsubst:"$(patsubst h%o,world,hello world)
	@echo "patsubst:"$(patsubst h%o,world,hello,world) # word要空格分割
	@echo "patsubst:"$(patsubst h%o,world,"hello world") #双引号包围的视作一个word？
	@echo "strip:"$(strip   hello    wold  )
	@echo "find:"$(findstring hello, hello,world)
	@echo "sort:"$(sort foo bar lose)
	@echo "realpath:"$(realpath ..)


build-in-vars:
	@echo "build in vars:"
	@echo "MAKEFILES: ${MAKEFILES}"
	@echo "VPATH: ${VPATH}"
	@echo "SHELL: ${SHELL}"
	@echo "MAKESHELL: ${MAKESHELL}"
	@echo "MAKE_VERSION: ${MAKE_VERSION}"
	@echo "MAKE_HOST: ${MAKE_HOST}"
	@echo "MAKE_LEVEL: ${MAKE_LEVEL}"
	@echo "MAKEFLAGS: ${MAKEFLAGS}"
	@echo "GNUMAKEFLAGS: ${GNUMAKEFLAGS}"
	@echo "CURDIR:${CURDIR}"
