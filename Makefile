SHELL	= /bin/bash

.PHONY	= 'all build test clean'

CC			= g++
FLAGS		= -g
SRC_DIR		= src
OUT_DIR		= out
TEST_DIR	= test
SRC			:= $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OUT			:= $(addprefix $(OUT_DIR)/,$(patsubst %.cpp,%,$(SRC)))
TEST		:= $(addprefix $(TEST_DIR)/,$(patsubst %.cpp,%,$(SRC)))

all: $(OUT)
	@echo ''

$(OUT_DIR)/%: $(SRC_DIR)/%.cpp
	$(CC) $< -o $@ $(FLAGS)

test: $(TEST)
	@echo ''
	
$(TEST_DIR)/%: $(OUT_DIR)/%
	@$(OUT_DIR)/$(notdir $@) < $@.in > $@
	@diff $@.out $@ \
		&& echo 'O codigo $(notdir $@) deu certo' \
		|| echo 'O codigo $(notdir $@) deu errado'

clean:
	@echo 'Removendo binarios'
	@rm $(OUT_DIR)/*
	@echo 'Removendo teste'
	@find ./$(TEST_DIR) -type f ! -name "*.*" -exec rm {} \;
	@echo ''