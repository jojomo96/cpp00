NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=obj/%.o)

# ANSI color codes
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[0;34m
NC = \033[0m # No Color

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)==============================$(NC)"
	@echo "$(BLUE)Building project...$(NC)"
	@echo "$(BLUE)==============================$(NC)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)==============================$(NC)"
	@echo "$(GREEN)Build complete!$(NC)"
	@echo "$(GREEN)==============================$(NC)"

obj/%.o: %.cpp
	@mkdir -p obj
	@echo "$(YELLOW)------------------------------$(NC)"
	@echo "$(YELLOW)Compiling $<$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)[done]$(NC)"
	@echo "$(YELLOW)------------------------------$(NC)"

clean:
	@echo "$(RED)==============================$(NC)"
	@echo "$(RED)Cleaning up...$(NC)"
	@rm -f $(OBJS)
	@rm -rf obj
	@echo "$(GREEN)Clean complete!$(NC)"
	@echo "$(GREEN)==============================$(NC)"

fclean: clean
	@echo "$(RED)==============================$(NC)"
	@echo "$(RED)Removing executable...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean complete!$(NC)"
	@echo "$(GREEN)==============================$(NC)"

re: fclean all

.PHONY: all clean fclean re
