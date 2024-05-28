# SRCS
SRC_C := error.c \
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
		 stat/init.c \
		 stat/main.c \
		 stat/utils.c

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

CFLAGS				+= -DPROG_NAME='"$(TARGET)"'

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
