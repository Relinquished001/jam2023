BUILD_DIR=build
include $(N64_INST)/include/n64.mk

src_dir     := $(wildcard src/*.cpp)
assets_png  := $(wildcard assets/*.png)
assets_conv := $(addprefix filesystem/,$(notdir $(assets_png:%.png=%.sprite)))

MKSPRITE_FLAGS ?=

all: main.z64

filesystem/%.sprite: assets/%.png
	@mkdir -p $(dir $@)
	@echo "    [SPRITE] $@"
	@$(N64_MKSPRITE) -f RGBA16 --compress -o "$(dir $@)" "$<"

build/main.dfs: $(assets_conv)
build/main.elf: $(src_dir:%.cpp=build/%.o)

main.z64: N64_ROM_TITLE="Summer Brew64 Jam"
main.z64: build/main.dfs

clean:
	rm -rf build/ filesystem/ main.z64

-include $(wildcard build/*.d)

.PHONY: all clean
