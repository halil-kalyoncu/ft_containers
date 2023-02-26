# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 10:00:26 by hkalyonc          #+#    #+#              #
#    Updated: 2023/02/24 11:16:17 by hkalyonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_containers
STD_NAME	=	std_containers

CPPC		=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEPDIR)$*.d
DEPFLAGSSTD	=	-MT $@ -MMD -MP -MF $(DEPDIRSTD)$*.d
RM			=	rm -f

SRCDIR		=	src/
SRCFILES	=	tester.cpp stack_tests.cpp vector_tests.cpp map_tests.cpp set_tests.cpp\

OBJDIR		=	build/ft/
OBJS		=	$(SRCFILES:%.cpp=$(OBJDIR)%.o)
OBJDIRSTD	=	build/std/
OBJSSTD		=	$(SRCFILES:%.cpp=$(OBJDIRSTD)%.o)

DEPDIR		=	$(OBJDIR).deps/
DEPS		=	$(SRCFILES:%.cpp=$(DEPDIR)%.d)
DEPDIRSTD	=	$(OBJDIRSTD).deps/
DEPSSTD		=	$(SRCFILES:%.cpp=$(DEPDIRSTD)%.d)

LOGS		=	logs/output/ logs/benchmark/

all: $(NAME) $(STD_NAME)

$(NAME): $(OBJS)
	@mkdir -p $(dir $(LOGS))
	@$(CPPC) $(CPPFLAGS) -o $@ $(OBJS)
	@echo "$(NAME) compiled"

$(STD_NAME): $(OBJSSTD)
	@mkdir -p $(dir $(LOGS))
	@$(CPPC) -D STD $(CPPFLAGS) -o $@ $(OBJSSTD)
	@echo "$(STD_NAME) compiled"

$(OBJDIR)%.o : $(SRCDIR)%.cpp $(DEPDIR)%.d
	@mkdir -p $(dir $(OBJDIR))
	@mkdir -p $(dir $(DEPDIR))
	@$(CPPC) -c $(CPPFLAGS) $(DEPFLAGS) -o $@ $<

$(OBJDIRSTD)%.o : $(SRCDIR)%.cpp
	@mkdir -p $(dir $(OBJDIRSTD))
	@mkdir -p $(dir $(DEPDIRSTD))
	@$(CPPC) -D STD -c $(CPPFLAGS) $(DEPFLAGSSTD) -o $@ $<

clean:
	@$(RM) $(OBJS) $(DEPS) $(OBJSSTD) $(DEPSSTD)
	@echo "object files removed"

lclean:
	@rm -rf $(LOGS)
	@echo "log files removed"

fclean: clean lclean
	@$(RM) $(NAME)
	@$(RM) $(STD_NAME)
	@echo "executables removed"

re: fclean all

.PHONY: all clean fclean re

$(DEPS):
include $(wildcard $(DEPS))
