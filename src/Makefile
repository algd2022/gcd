OPTIONS = -Wall -Wextra
BUILDDIR = build
TARGET = gcd

.PHONY: ${TARGET}
${TARGET}:
	make ${BUILDDIR}/gcd

${BUILDDIR}:
	mkdir -p ${BUILDDIR}
${BUILDDIR}/${TARGET}: ${TARGET}.c 
	gcc ${OPTIONS} -o $@ $<

clean:
	rm -rf ${BUILDDIR}/*
