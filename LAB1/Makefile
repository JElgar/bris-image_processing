PONY: help

APP := hello.cpp

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

ssh: ## ssh into vagrant image
	vagrant ssh

compile:
	g++ $(APP) ${O_LIBS}:w
