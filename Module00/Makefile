NAME = Module00Tests

# **************************************************************************** #
#                                  COLORS                                        #
# **************************************************************************** #
GREEN  := \033[0;32m
YELLOW := \033[0;33m
CYAN   := \033[0;36m
RESET  := \033[0m

# **************************************************************************** #
#                                VARIABLES                                       #
# **************************************************************************** #
BUILD_DIR   := build
CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=Debug

# **************************************************************************** #
#                                 TARGETS                                        #
# **************************************************************************** #

all: test

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake $(CMAKE_FLAGS) ..
	@echo "$(GREEN)CMake files generated in $(YELLOW)$(BUILD_DIR)$(RESET)"

build: $(BUILD_DIR)
	@echo "$(CYAN)Building project...$(RESET)"
	@cmake --build $(BUILD_DIR)
	@echo "$(GREEN)Build complete$(RESET)"

test: build
	@echo "$(CYAN)Running tests...$(RESET)"
	@cd $(BUILD_DIR) && ctest --output-on-failure
	@echo "$(GREEN)Tests completed$(RESET)"

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)Build directory cleaned$(RESET)"

re: clean all

.PHONY: all build test clean re