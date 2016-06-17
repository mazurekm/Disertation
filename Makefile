prefix=main

$(prefix).pdf: $(prefix).bbl
	pdflatex $(prefix).tex

$(prefix).bbl: $(prefix).aux 
	bibtex $(prefix)

$(prefix).aux:
	pdflatex $(prefix).tex

.PHONY: clean
clean:
	rm -f $(prefix).aux $(prefix).log $(prefix).lof $(prefix).lot $(prefix).out $(prefix).pdf $(prefix).toc $(prefix).bbl $(prefix).blg texput.log $(prefix)-blx.bib $(prefix).run.xml $(prefix).bcf $(prefix).aux.blg
