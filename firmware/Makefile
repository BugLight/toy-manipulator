# See https://github.com/neovim/neovim/blob/master/Makefile for example CMake usage in makefile

MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR  := $(dir $(MAKEFILE_PATH))

CMAKE ?= cmake
CMAKE_BUILD_TYPE ?= Debug
CMAKE_TOOLCHAIN_FILE ?= $(MAKEFILE_DIR)cmake/arm-gcc-toolchain.cmake
CMAKE_FLAGS += -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) \
			   -DCMAKE_TOOLCHAIN_FILE=$(CMAKE_TOOLCHAIN_FILE) \
			   -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE

CMAKE_GENERATOR ?= $(shell (command -v ninja > /dev/null 2>&1 && echo "Ninja") || echo "Unix Makefiles")

ifeq (Ninja,$(CMAKE_GENERATOR))
	BUILD_TOOL = ninja
	# Only need to handle Ninja here.  Make will inherit the VERBOSE variable, and the -j, -l, and -n flags.
	ifneq ($(VERBOSE),)
		BUILD_TOOL += -v
	endif
	BUILD_TOOL += $(shell printf '%s' '$(MAKEFLAGS)' | grep -o -- ' *-[jl][0-9]\+ *')
	ifeq (n,$(findstring n,$(firstword -$(MAKEFLAGS))))
		BUILD_TOOL += -n
	endif
else
	BUILD_TOOL = $(MAKE)
endif

all: build/firmware.hex

build/firmware.hex: build/firmware.elf
	arm-none-eabi-objcopy -O ihex $< $@

build/firmware.elf: build/.ran-cmake
	+$(BUILD_TOOL) -C build

cmake:
	touch CMakeLists.txt
	$(MAKE) build/.ran-cmake

build/.ran-cmake: CMakeLists.txt
	mkdir -p build
	cd build && $(CMAKE) -G '$(CMAKE_GENERATOR)' $(CMAKE_FLAGS) $(MAKEFILE_DIR)
	touch $@

flash: build/firmware.hex
	st-flash --format ihex write $<

clean:
	+test -d build && $(BUILD_TOOL) -C build clean || true

distclean:
	rm -rf build/

.PHONY: all cmake clean flash distclean
