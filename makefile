# **************************************************************************** #
#		   _                            __   _                __
#		  (_)___ ____  ________  ____  / /__(_)___ ___   ____/ /__ _   __
#		 / / __ `/ _ \/ ___/ _ \/ __ \/ //_/ / __ `__ \ / __  / _ \ | / /
#		/ / /_/ /  __(__  )  __/ /_/ / ,< / / / / / / // /_/ /  __/ |/ /
#	 __/ /\__,_/\___/____/\___/\____/_/|_/_/_/ /_/ /_(_)__,_/\___/|___/
#	/___/
#
#	@author JaeSeoKim <devjaeseo@gmail.com>
#	@date 2021/09/28
#	@file makefile
# **************************************************************************** #

NAME = ft_containers

CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Setup Debug Config
ifeq ($(DEBUG),true)
CFLAGS += -O0 -g3
else ifeq ($(DEBUG),memory)
CFLAGS += -O0 -g3 -fsanitize=address
endif

# External Command
RM = rm
RMFLAGS = -rf

# Diretory Config
INC_DIR = src
SRC_DIR = src
OBJ_DIR = obj

CFLAGS += -I ${INC_DIR}

# Header Files
INCS = $(addprefix $(INC_DIR)/, \
	vector.hpp \
)

# Src Files
SRCS = $(addprefix $(SRC_DIR)/, \
	main.cpp	\
	vector.test.cpp	\
	iterator_traits.test.cpp \
	reverse_iterator.test.cpp \
	algorithm.test.cpp	\
	utility.test.cpp \
	random_access_iterator.test.cpp \
)

# Vitual Path List
vpath %.cpp $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))


# ============================================================================ #
#                        Progress Indication Script                            #
#                                                                              #

_mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
I := $(patsubst %/,%,$(dir $(_mkfile_path)))

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell \
	$(MAKE) $(MAKECMDGOALS) --no-print-directory \
		-nrRf $(firstword $(MAKEFILE_LIST)) \
		ECHO="COUNTTHIS" | grep -c "COUNTTHIS" \
)
N := x
C = $(words $N)$(eval N := x $N)
ECHO = python3 $(I)/script/echo_progress.py --stepno=$C --nsteps=$T
endif

#                                                                              #
# ============================================================================ #

.PHONY: all fclean clean re

all : ${NAME}
	@${ECHO} 🎉 All Done

re :
	@make fclean
	@make ${NAME}
	@${ECHO} 🚀 Re Build Done

fclean : clean
	@${ECHO} 🧹 Cleaning ${NAME} Done

clean :
	@${RM} ${RMFLAGS} ${NAME}
	@${RM} ${RMFLAGS} ${OBJS}
	@${ECHO} 🧹 Cleaning Objects Done

${OBJ_DIR} :
	@mkdir -p $(OBJ_DIR)

obj/%.o : %.cpp ${INCS} | $(OBJ_DIR)
	@${CC} ${CFLAGS} -c ${<} -o ${@}
	@${ECHO} 🚧 Compiling ${@} from ${<}

${NAME} : ${INCS} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${@}
	@${ECHO} 📚 Linking $@

endif
