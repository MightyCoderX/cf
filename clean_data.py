"""
Made to parse lines copied from the PDF file,
by selecting the text with CTRL-A, after removing table headings and titles.

And it transforms each line like this:
"A001 ABANO TERME (PD) PD" -> "A001;ABANO TERME;PD"
"""

with open("./codici_catastali_comuni.csv") as f:
    with open("./codici_catastali_comuni_clean.csv", "w") as out:
        while line := f.readline():
            code_and_city, p1, p2 = line.rsplit(" ", 2)
            code, city = code_and_city.split(" ", 1)
            out.write(f"{code};{city};{p2}")
