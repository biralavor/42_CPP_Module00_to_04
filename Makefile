NAME = cpp42-env
CONTAINER = cpp42-container

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
ORANGE			:= \033[0;91m
MAGENTA			:= \033[0;95m
RESET			:= \033[0m

COLORED_USER_ID = $(CYAN)$(shell id -u)$(YELLOW)
COLORED_GROUP_ID = $(CYAN)$(shell id -g)$(YELLOW)

.PHONY: build
build:
	@echo "$(YELLOW)Building DOCKER with UID=$(COLORED_USER_ID) and GID=$(COLORED_GROUP_ID)$(RESET)"
	docker build \
		--build-arg USER_ID=$(shell id -u) \
		--build-arg GROUP_ID=$(shell id -g) \
		-t $(NAME) .

.PHONY: go-docker
go-docker:
	docker run -it \
	--name $(CONTAINER) \
	-v $(PWD):/workspace:rw \
	--user $(shell id -u):$(shell id -g) \
	$(NAME)

.PHONY: stop
stop:
	docker stop $(CONTAINER) || true

.PHONY: clean
clean: stop
	docker rm $(CONTAINER) || true

.PHONY: reload-docker
reload-docker: clean build go-docker

.PHONY: deep-clean
deep-clean: clean
	docker rmi $(NAME) || true

.PHONY: ps
ps:
	docker ps -a

.PHONY: prune-system
prune-system:
	docker system prune -f