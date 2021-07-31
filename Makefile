CC= g++
BUILD_DIR = obj
SRC_DIR = src
SOURCES = $(shell find $(SRC_DIR)/ -name "*.cxx")
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cxx=$(BUILD_DIR)/%.o)
TARGET  = linux_debug


bin=bin



ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr " [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif


$(VERBOSE).SILENT:

default: $(TARGET)
	@$(ECHO) ALL DONE;

.SECONDEXPANSION:

run:
	./bin/linux/debug/linux_debug


$(OBJECTS) : $$(patsubst $(BUILD_DIR)/%.o,$(SRC_DIR)/%.cxx,$$@)
	@$(ECHO) "\033[1;32m" CXX: $<
	 mkdir -p $(@D)
	$(CC) $(linux_cxx_flags) -o $@ $(include_h) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug) -c $<

$(TARGET): $(OBJECTS)
	@$(ECHO) "\033[0;31m"  LD: $@
	$(CC) $(linux_cxx_flags) -o $(bin)/linux/debug/$@ $^ $(include_h)  $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

.PHONY: default

clean:
	find . -print -type f | grep -i '.*[.]o' | xargs rm -f

clean_pgo:
	find . -print -type f | grep -i '.*[.]gcda' | xargs rm -f



include_h=-Iinclude/ -I/home/ain/Desktop/projects/raylib/raylib-3.7.0/build/raylib/include

linux_godot_lib_path_debug=
linux_godot_lib_debug= -lraylib -lglfw -lGL -lopenal -lm -pthread -ldl


linux_cxx_flags= -std=c++14   -static-libstdc++ -static-libgcc  -Wall -m64 -O3  -mtune=native -march=native -feliminate-unused-debug-types -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector --param=ssp-buffer-size=32 -Wformat -Wformat-security -m64 -fasynchronous-unwind-tables -Wp,-D_REENTRANT -ftree-loop-distribute-patterns -Wl,-z -Wl,now -Wl,-z -Wl,relro -fno-semantic-interposition -ffat-lto-objects -fno-trapping-math -Wl,-sort-common -Wl,--enable-new-dtags  -Wa,-mbranches-within-32B-boundaries





