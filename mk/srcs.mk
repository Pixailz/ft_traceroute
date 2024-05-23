# SRCS
SRC_C_MANDATORY := error.c \
				   execution.c \
				   ft_get_ts.c \
				   main.c \
				   parsing/cmd/help.c \
				   parsing/cmd/usage.c \
				   parsing/parse.c \
				   print_packet.c \
				   probs.c \
				   recv_pong.c \
				   send_ping.c \
				   signal.c \
				   socket.c \
				   stat.c

SRC_C_BONUS := main.c \
			   utils/utils.1.c \
			   utils/utils.1/utils.1.c \
			   utils/utils.1/utils.2.c \
			   utils/utils.1/utils.3.c \
			   utils/utils.1/utils.4.c \
			   utils/utils.2.c \
			   utils/utils.3.c \
			   utils/utils.4.c

ifeq ($(BONUS),1)
TARGET				:= $(TARGET_BONUS)
SRC_C				:= $(addprefix $(SRC_DIR)/bonus/,$(SRC_C_BONUS))
else
SRC_C				:= $(addprefix $(SRC_DIR)/mandatory/,$(SRC_C_MANDATORY))
endif

CFLAGS				+= -DPROG_NAME='"$(TARGET)"'

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
