# Build or run the examples in this section.
.DEFAULT_GOAL := all
PROJECTS := $(patsubst %/Makefile,%,$(wildcard */Makefile))
.PHONY: all smoke sanitize
all smoke sanitize:
	@set -e; for project in $(PROJECTS); do $(MAKE) -C "$$project" $@; done
