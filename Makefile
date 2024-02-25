all: usage

usage: 
	@echo 'Usage: make [target] PROBLEM=<problem-name>'
	@echo ''
	@echo 'Targets:'
	@echo 'cpp        Builds C++ template'
	@echo 'go         Builds Go template'
	@echo 'python     Builds Python template'
	@echo 'rust       Builds Rust template'

cpp:
ifndef PROBLEM 
	$(error PROBLEM is not set)
endif
	$(eval DIR = ./problems/$(PROBLEM)/cpp)
	$(eval TARGET = $(DIR)/main.cpp)
	@echo 'creating template at $(TARGET)'
	mkdir -p $(DIR)
	touch $(TARGET)
	@echo 'done'

go:
ifndef PROBLEM 
	$(error PROBLEM is not set)
endif
	$(eval DIR = ./problems/$(PROBLEM)/go)
	$(eval TARGET = $(DIR)/main.go)
	@echo 'creating template at $(TARGET)'
	mkdir -p $(DIR)
	cd $(DIR) && test -f go.mod || go mod init $(PROBLEM)
	touch $(TARGET)
	@echo 'done'

python:
ifndef PROBLEM 
	$(error PROBLEM is not set)
endif
	$(eval DIR = ./problems/$(PROBLEM)/python)
	$(eval TARGET = $(DIR)/main.py)
	@echo 'creating template at $(TARGET)'
	mkdir -p $(DIR)
	touch $(TARGET)
	@echo 'done'

rust:
ifndef PROBLEM 
	$(error PROBLEM is not set)
endif
	$(eval DIR = ./problems/$(PROBLEM))
	$(eval TARGET = $(DIR)/rust/src/lib.rs)
	@echo 'creating template at $(TARGET)'
	mkdir -p $(DIR)
	cd $(DIR) && test -d rust || cargo new rust --lib --vcs none
	@echo 'done'
