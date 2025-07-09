# Определяем переменные
TASK_PATH = .
SRC_DIR = $(TASK_PATH)/src
INC_DIR = $(TASK_PATH)/inc
BIN_DIR = $(TASK_PATH)/bin
OBJ_DIR = $(BIN_DIR)/obj
TEST_FILES_DIR = $(BIN_DIR)/test_files

# Находим все .c файлы в src
SRCS = $(wildcard $(SRC_DIR)/*.cpp)


OBJ_CUR = \
	$(OBJ_DIR)/oop_3_6_7.o

# Цели сборки по умолчанию
TARGETS = my_prog

# Компилятор и флаги
CC = g++
WARN_FLAGS = -Wall -Werror
CFLAGS = -I$(INC_DIR) $(WARN_FLAGS) -g

# Правило для цели сборки по умолчанию
all: $(TARGETS)

# Правило для создания папки bin
$(BIN_DIR):
	mkdir -p $(BIN_DIR) \
	$(OBJ_DIR)

# Правила для промежуточных целей сборки по умолчанию

my_prog: $(BIN_DIR)/my_prog

$(BIN_DIR)/my_prog: $(OBJ_CUR) | $(BIN_DIR)
	$(CC) -o $@ $^

# Правило для создания объектных файлов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Чистка объектов и исполняемого файла
clean:
	rm -rf $(OBJ_DIR)/*.o $(TEST_FILES_DIR)/*.bin $(addprefix $(BIN_DIR)/, $(TARGETS))

.PHONY: all clean fclean
