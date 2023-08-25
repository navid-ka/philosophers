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
	export TYPE=$(shell gum choose "fix" "feat" "docs" "style" "refactor" "test" "chore" "revert")
	export DESCRIPTION=$(shell gum write --placeholder "Details of this change (CTRL+D to finish)")
	echo "TYPE: $TYPE"
	echo "DESCRIPTION: $DESCRIPTION"
	/bin/bash -c "gum confirm 'Commit changes?' && git commit -m '$TYPE' -m '$DESCRIPTION' && git push"


.PHONY: clean all fclean re main
