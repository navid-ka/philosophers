NAME = philosophers
CFLAGS = -Wall -Werror -Wextra -l pthread
OBJECTS = main.c
COLOR_RESET = \033[0m
COLOR = \033[32m
KAOMOJI_SUCCESS = (づ ᴗ _ᴗ)づ♡
KAOMOJI_REMOVE = (ノಠ益ಠ)ノ彡┻━┻

all: ${NAME}

${NAME}: ${OBJECTS}
	@cc ${CFLAGS} ${OBJECTS} -o ${NAME}
	@printf "$(COLOR)Main program compiled successfully!$(COLOR_RESET)\n"

fclean: clean
	@rm -rf ${NAME}
	@printf "$(COLOR)Cleaned directory! $(KAOMOJI_REMOVE)$(COLOR_RESET)\n"

clean:
	@rm -f ${NAME}
	@printf "$(COLOR)Cleaned object files! $(KAOMOJI_REMOVE)$(COLOR_RESET)\n"

re: fclean all

git: fclean
	git add .
	TYPE=$(shell gum choose "fix:" "feat:" "docs:" "refactor" "test" "chore" "revert"); \
	DESCRIPTION=$(shell gum write --placeholder "Details of this change (CTRL+D to finish)"); \
	if gum confirm "Commit changes?"; then \
		git commit -m "$$TYPE $$DESCRIPTION"; \
		git push; \
	else \
		echo "Changes not committed."; \
	fi


.PHONY: clean all fclean re main
