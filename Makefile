CFLAGS = -g -Wall -Wextra -Werror

NAME = so_long
MAKE = make --no-print-directory

OBJS = $(SRCS:.c=.o)

#-------------------------------------------------------COLORS--------------------------------------------------#

BLACK = "\e[30m"
RED = "\e[31m"
GREEN = "\e[32m"
YELLOW = "\e[33m"
BLUE = "\e[34m"
MAGENTA = "\e[35m"
CYAN = "\e[36m"
LIGHT_GRAY = "\e[37m"
DARK_GRAY = "\e[90m"
LIGHT_RED = "\e[91m"
LIGHT_GREEN = "\e[92m"
LIGHT_YELLOW = "\e[93m"
LIGHT_BLUE = "\e[94m"
LIGHT_MAGENTA = "\e[95m"
LIGHT_CYAN = "\e[96m"
WHITE = "\e[97m"
DEFAULT = "\e[39m"

#-------------------------------------------------------SRCS----------------------------------------------------#

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = MacroLibX
MLX = $(MLX_PATH)/libmlx.so

SRCS = srcs/exec.c \
	   srcs/parsing.c \
	   srcs/parsing_utils.c \
	   srcs/error.c \
	   srcs/flood_fill.c \
	   srcs/start_game.c \
	   srcs/put_image.c \
	   srcs/put_image2.c \
	   srcs/update.c \
	   srcs/initialize_img.c \
	   srcs/initialize_img2.c \
	   srcs/initialize_img3.c \
	   srcs/initialize_img4.c \
	   srcs/initialize_img5.c \
	   srcs/destroy_all.c \
	   srcs/frame.c \
	   srcs/frame2.c \
	   srcs/collision.c \
	   srcs/event.c \
	   srcs/event2.c \
	   srcs/item.c \
	   srcs/exit.c \
	   srcs/close_files.c \
	   srcs/map_settings.c \
	   srcs/wall.c \
	   srcs/wall2.c \
	   srcs/player.c \
	   srcs/player2.c \
	   srcs/monster.c \
	   srcs/monster2.c \
	   srcs/player_frame.c \
	   srcs/veldra.c \
	   srcs/veldra_frame.c \
	   srcs/death.c


#-----------------------------------------------------RULES-----------------------------------------------#

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH) -s -j

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) -lm -lSDL2
	@echo $(BLUE)
	@echo "███████  ██████          ██       ██████  ███    ██  ██████  "
	@echo "██      ██    ██         ██      ██    ██ ████   ██ ██       "
	@echo "███████ ██    ██         ██      ██    ██ ██ ██  ██ ██   ███ "
	@echo "     ██ ██    ██         ██      ██    ██ ██  ██ ██ ██    ██ "
	@echo "███████  ██████  ███████ ███████  ██████  ██   ████  ██████  "
	@echo $(DEFAULT)

%.o: %.c
	@echo -n $(CYAN)
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo -n $(DEFAULT)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@rm -f $(OBJS)
	@echo $(YELLOW)
	@echo "███████  ██████          ██       ██████  ███    ██  ██████      ██ ███████"
	@echo "██      ██    ██         ██      ██    ██ ████   ██ ██           ██ ██"
	@echo "███████ ██    ██         ██      ██    ██ ██ ██  ██ ██   ███     ██ ███████"
	@echo "     ██ ██    ██         ██      ██    ██ ██  ██ ██ ██    ██     ██      ██"
	@echo "███████  ██████  ███████ ███████  ██████  ██   ████  ██████      ██ ███████"
	@echo ""
	@echo " ██████ ██      ███████  █████  ███    ██  ███████ ██████"
	@echo "██      ██      ██      ██   ██ ████   ██  ██      ██   ██"
	@echo "██      ██      █████   ███████ ██ ██  ██  █████   ██   ██"
	@echo "██      ██      ██      ██   ██ ██  ██ ██  ██      ██   ██"
	@echo " ██████ ███████ ███████ ██   ██ ██   ████  ███████ ██████"
	@echo $(DEFAULT)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) fclean
	@rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
