LINUX				:= 0

# Folders

override BIN		:= bin
override SRC		:= src
override INC		:= includes

override CLI		:= root/client
override SRV		:= root/server
override COM		:= root/common

# Properties

CLIENT				= client
SERVER				= server

# Commands

override CC			:= gcc
override RM			:= rm -rf
override CFLAGS		:= -Wall -Wextra -Werror
override INCLUDES	:= -I$(COM)/$(INC)

# Sources

override CLIENT_SRCS:=									\
				client.c								\

override SERVER_SRCS:=									\
				server.c								\

override COMMON_SRCS:=									\
				convert.c								\
				print.c									\
				string.c								\

override CLIENT_OBJS:= $(addprefix $(CLI)/, $(addprefix $(BIN)/, $(CLIENT_SRCS:.c=.o)))
override SERVER_OBJS:= $(addprefix $(SRV)/, $(addprefix $(BIN)/, $(SERVER_SRCS:.c=.o)))
override COMMON_OBJS:= $(addprefix $(COM)/, $(addprefix $(BIN)/, $(COMMON_SRCS:.c=.o)))

override COMMON_HEADERS:= $(addprefix $(COM)/, $(addprefix $(INC)/,				\
				minitalk.h								\
				))

LIBRARIES	:= -lpthread
ifeq ($(LINUX),1)
LIBRARIES	+= -lm -lXext -lX11
endif

all:		$(SERVER) $(CLIENT)

override TARGETS	:= $(SRV)/$(BIN)/%.o $(CLI)/$(BIN)/%.o $(COM)/$(BIN)/%.o

$(SRV)/$(BIN)/%.o:	$(SRV)/$(SRC)/%.c $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CLI)/$(BIN)/%.o:	$(CLI)/$(SRC)/%.c $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(COM)/$(BIN)/%.o:	$(COM)/$(SRC)/%.c $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SERVER):	$(SERVER_OBJS) $(COMMON_OBJS)
			$(CC) $(CFLAGS) $(SERVER_OBJS) $(COMMON_OBJS) -o $@

$(CLIENT):	$(CLIENT_OBJS) $(COMMON_OBJS)
			$(CC) $(CFLAGS) $(CLIENT_OBJS) $(COMMON_OBJS) -o $@

clean:
			$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(COMMON_OBJS)
			find $(SRV)/$(BIN) -type d -empty -delete
			find $(CLI)/$(BIN) -type d -empty -delete
			find $(COM)/$(BIN) -type d -empty -delete

fclean:		clean
			$(RM) $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re
