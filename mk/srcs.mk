# SRCS
SRC_C := error.c \
		 execution.c \
		 ft_get_ts.c \
		 main.c \
		 parsing/cmd/help.c \
		 parsing/cmd/usage.c \
		 parsing/parse.c \
		 parsing/post/base_port.c \
		 parsing/post/interface.c \
		 parsing/post/ip.c \
		 parsing/post/ip_identification.c \
		 parsing/post/max_hop.c \
		 parsing/post/nb_prob.c \
		 parsing/post/src_ip.c \
		 parsing/post/start_hop.c \
		 parsing/post/target.c \
		 parsing/post/tos.c \
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
