###############################################
# This file is part of the dotfiles repository.
###############################################

cc=clang -std=c++11 -Wall -Wextra
src=config.cc context.cc dotfiles.cc statement.cc

sDir=src
oDir=obj

rawObj=$(patsubst %.cc, %.o, $(src))
obj=$(patsubst %, $(oDir)/%, $(rawObj))

rawObj-d=$(patsubst %.cc, %-d.o, $(src))
obj-d=$(patsubst %, $(oDir)/%, $(rawObj-d))

update: dotfiles
	bin/dotfiles --update

install: clean dotfiles
	bin/dotfiles --install

compile: dotfiles dotfiles-d

dotfiles: mkdir $(obj)
	$(cc) $(obj) -o bin/$@

dotfiles-d: mkdir $(obj-d)
	$(cc) $(obj-d) -ggdb3 -o bin/$@

$(oDir)/%.o: $(sDir)/%.cc
	$(cc) $(pkgConfig) -c $< -o $@
$(oDir)/%-d.o: $(sDir)/%.cc
	$(cc) $(pkgConfig) -c $< -ggdb3 -o $@

.PHONY : clean
clean:
	rm -rf bin/dotfiles bin/dotfiles-d $(oDir)

.PHONY : mkdir
mkdir:
	mkdir -pv bin $(oDir)
