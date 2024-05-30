
NAME = snake
CC = @gcc
FLAGS = -Wall -Wextra -Werror -pedantic -g  $(INCLUDES)

# Libraries
LIBS_DIR = .\\libs\\

# RAYLIB
RAYLIB_DIR = raylib-5.0\\
RAYLIB_LIB = $(LIBS_DIR)$(RAYLIB_DIR)\\lib\\libraylib.a
RAYLIB_INCLUDE_DIR = $(LIBS_DIR)$(RAYLIB_DIR)\\include\\

includefolder = includes\\
INCLUDES = -I $(includefolder) -I $(RAYLIB_INCLUDE_DIR)
LINK_FLAGS = -lm -lpthread -lgdi32 -lwinmm -lopengl32

SRC_FOLDER = src\\
OBJ_DIR = obj\\

SRC_ROOT_FILES = main.c snake.c snake_renderer.c

INCLUDE_HEADERS = $(addprefix $(includefolder), \
	snake.h \
)

FILES = \
	$(SRC_ROOT_FILES) \


OBJS = $(addprefix $(OBJ_DIR), $(FILES:%.c=%.o))

# Reset
Color_Off='[0m'       # Text Reset

IRed='[0;91m'         # Red
IGreen='[0;92m'       # Green
IYellow='[0;93m'      # Yellow
ICyan='[0;96m'        # Cyan

MSG1 = @echo ${IGreen}"Compiled Successfully ✔︎"${Color_Off}
MSG2 = @echo ${IYellow}"Cleaned Successfully ✔︎"${Color_Off}
MSG3 = @echo ${ICyan}"Cleaned ${NAME} Successfully ✔︎"${Color_Off}

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE_HEADERS)
	@echo $(RAYLIB_FILES_DIR)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)  $(RAYLIB_LIB) $(LINK_FLAGS)
	$(MSG1)

$(RAYLIB_LIB):
	@cd $(LIBS_DIR)$(RAYLIB) && cmake -DBUILD_SHARED_LIBS=OFF . && make

$(OBJS): $(OBJ_DIR)%.o: $(SRC_FOLDER)%.c $(INCLUDE_HEADERS)
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	@$(CC) $(FLAGS) -o $@ -c $<

run: all
	$(NAME).exe

clean:
	rmdir /s /q $(OBJ_DIR)
	$(MSG2)

fclean: clean
	@del $(NAME).exe
	$(MSG3)

re: fclean all

