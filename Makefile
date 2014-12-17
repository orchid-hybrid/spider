SOURCES=pat.scm sequence.scm atomic.scm symbol-table.scm verify.scm reference-count.scm assignment-form.scm codegen.scm
OBJECTS=$(SOURCES:.scm=.so)

all: $(OBJECTS)
	csc spider.scm

$(OBJECTS): %.so: %.scm
	csc -sJ -o $@ $<
