# Build or check every project in this section.
.DEFAULT_GOAL := all
PROJECTS := $(patsubst %/Makefile,%,$(wildcard */Makefile))
.PHONY: all test sanitize
all test sanitize:
	@set -e; for project in $(PROJECTS); do $(MAKE) -C "$$project" $@; done
