###############################################
# This file is part of the dotfiles repository.
###############################################

cc=clang -std=c++11 -Wall -Wextra

# Listing of source-files sorted by directory-hierarchie.
keywords := $(patsubst %, keywords/%, add.cc package.cc word.cc)
src := $(patsubst %, src/%, dotfiles.cc parser.cc $(keywords))

srcObj := $(patsubst %.cc, %.o, $(src))
obj    := $(patsubst src/%, obj/%, $(srcObj))
obj-d  := $(patsubst %.o, %-d.o, $(obj))

update: dotfiles
	bin/dotfiles --update

install: clean dotfiles
	bin/dotfiles --install

compile: dotfiles dotfiles-d

dotfiles: mkdir $(obj)
	$(cc) $(obj) -o bin/$@

dotfiles-d: mkdir $(obj-d)
	$(cc) $(obj-d) -ggdb3 -o bin/$@

obj/%.o: src/%.cc
	$(cc) $(pkgConfig) -c $< -o $@
obj/%-d.o: src/%.cc
	$(cc) $(pkgConfig) -c $< -ggdb3 -o $@

.PHONY : clean
clean:
	rm -rf bin/dotfiles bin/dotfiles-d obj

.PHONY : mkdir
mkdir:
	mkdir -pv bin obj obj/keywords
