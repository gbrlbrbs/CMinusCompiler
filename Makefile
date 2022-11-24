BUILDDIR=./build

all:
	@echo "Generating build files for the parser"
	@bison -d cminus.y
	@echo "Generating build files for lexer"
	@flex cminus.l
	@echo "Building..."
	@[ -d $(BUILDDIR) ] || mkdir -p $(BUILDDIR)
	@gcc *.c -o $(BUILDDIR)/cminus 
	@echo "Finished building."