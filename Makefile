MAKEFLAGS += --no-print-directory
NAME = philosophers
endifNAME = philosophers
CFLAGS = -Wall -Werror -Wextra -l pthread
OBJECTS = main.c

all: ${NAME}

${NAME}: ${OBJECTS}
	@cc ${CFLAGS} ${OBJECTS} -o ${NAME}
	@gum style \
		--foreground 212 --border-foreground 213 --border normal \
		--align center --width 70 --margin "0 2" --padding "2 4" \
		'Compilation completed, ./philosophers'

fclean: 
	@gum spin --spinner meter --title "Cleaning..." -- make clean
	@rm -rf ${NAME}
	@gum style \
		--foreground 212 --border-foreground 213 --border normal \
		--align center --width 70 --margin "0 2" --padding "2 4" \
		'Cleaned directory and object files!'

clean:
	@rm -f ${NAME}
	@gum style \
		--foreground 212 --border-foreground 213 --border normal \
		--align center --width 70 --margin "0 2" --padding "2 4" \
		'Cleaned object files!'

re: fclean all

git: fclean
	@git add .
	@TYPE=$(shell gum choose "fix:" "feat:" "refactor:" "test:" "chore:" "revert:"); \
	DESCRIPTION=$(shell gum input --placeholder "Details of this change (Add '')"); \
	if gum confirm "Another commit!"; then \
		git commit -m "$$TYPE $$DESCRIPTION"; \
		gum spin --spinner meter --title "Pushing to repository" -- git push; \
		gum style --foreground 212 --border-foreground 213 --align center --width 70 --margin "0 2" --padding "2 4" 'Git push complete!'; \
	else \
		printf "$(COLOR)Changes not committed.$(COLOR_RESET)"; \
	fi

.PHONY: clean all fclean re main
