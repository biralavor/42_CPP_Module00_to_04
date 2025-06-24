define get_container_name
	head -n 4 docker-compose.yaml | tail -n 1 | sed 's/://g'
endef

define get_image_name
	cat docker-compose.yaml | grep 'image:' | awk '{printf $$2}'
endef

IMAGE = $(shell $(get_image_name))
CONTAINER = $(shell $(get_container_name))

RED				= \e[0;31m
GREEN			= \e[0;32m
YELLOW			= \e[0;33m
BLUE			= \e[0;34m
PURPLE			= \e[0;35m
CYAN			= \e[0;36m
ORANGE			= \e[0;91m
MAGENTA			= \e[0;95m
RESET			= \e[0m

COLORED_USER_ID = $(CYAN)$(shell id -u)$(YELLOW)
COLORED_GROUP_ID = $(CYAN)$(shell id -g)$(YELLOW)

.PHONY: build
build:
	docker compose up -d --build
	@printf "$(GREEN)Docker image $(IMAGE) built successfully!$(RESET)"

.PHONY: go
go: build
	@printf "$(GREEN)Docker container $(CONTAINER) is running!$(RESET)"
	$(call prepare_googletest)
	$(call build_googletest)
	docker compose exec app /bin/bash

.PHONY: stop
stop:
	docker compose stop $(CONTAINER)
	@printf "$(YELLOW)Docker container $(CONTAINER) stopped!$(RESET)"

.PHONY: down
down:
	docker compose down
	@printf "$(YELLOW)Docker container $(CONTAINER) stopped and removed!$(RESET)"

.PHONY: reload-docker
reload-docker: stop build go-docker

.PHONY: ps
ps:
	docker ps -a
	@printf "$(YELLOW)Docker containers listed!$(RESET)"

.PHONY: deep-clean
deep-clean:
	docker builder prune