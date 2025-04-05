SHELL	= /bin/bash

.PHONY	= all clear test

# 'notdir' -> remove o caminho para o arquivo
# 'wildcard' -> pega a lista de arquivos
# 'addprefix' -> adiciona prefixo (no caso o caminho do arquivo)
# 'patsubst' -> (padrao, substituicao, texto)
# 				padrao = padrao das palavras que vao ser substituidas
#			No caso ta sendo usado para remover a extensão .cpp

CC 			= 	g++
FLAGS	 	= 	-g
SRC_DIR 	= 	src
TEST_DIR 	= 	test
OUT_DIR 	= 	out
BACKUP_DIR 	= 	backup
SRC 		:= 	$(notdir $(wildcard $(SRC_DIR)/*.cpp))
TEST		:=	$(addprefix $(TEST_DIR)/, $(patsubst %.cpp, %, $(SRC)))
OUT 		:= 	$(addprefix $(OUT_DIR)/, $(patsubst %.cpp, %, $(SRC)))
BACKUP		:= 	$(notdir $(wildcard $(BACKUP_DIR)/*.cpp))

all: $(OUT_DIR) $(TEST)
	@echo ""

$(OUT_DIR)/%: $(SRC_DIR)/%.cpp
	@$(CC) $< -o $@ $(FLAGS)
	@cp $< $(BACKUP_DIR)

$(TEST_DIR)/%: $(OUT_DIR)/% $(TEST_DIR)/%.in
	@$(OUT_DIR)/$(notdir $@) < $@.in > $@
	@diff $@ $@.exp \
		&& echo '// o codigo $(notdir $@) deu certo' \
		|| echo '// o codigo $(notdir $@) deu errado'

clear:
	@rm $(SRC_DIR)/.* $(TEST_DIR)/.* $(OUT_DIR)/.* .* 2> erro \
		|| echo ''
	@rm erro
