# convert pdf to grayscale, preserving metadata
# "AFAIK graphicx has no feature for manipulating colorspaces. " http://groups.google.com/group/latexusersgroup/browse_thread/thread/5ebbc3ff9978af05
# "> Is there an easy (or just standard) way with pdflatex to do a > conversion from color to grayscale when a PDF file is generated? No." ... "If you want to convert a multipage document then you better have pdftops from the xpdf suite installed because Ghostscript's pdf to ps doesn't produce nice Postscript." http://osdir.com/ml/tex.pdftex/2008-05/msg00006.html
# "Converting a color EPS to grayscale" - http://en.wikibooks.org/wiki/LaTeX/Importing_Graphics
# "\usepackage[monochrome]{color} .. I don't know of a neat automatic conversion to monochrome (there might be such a thing) although there was something in Tugboat a while back about mapping colors on the fly. I would probably make monochrome versions of the pictures, and name them consistently. Then conditionally load each one" http://newsgroups.derkeiler.com/Archive/Comp/comp.text.tex/2005-08/msg01864.html
# "Here comes optional.sty. By adding \usepackage{optional} ... \opt{color}{\includegraphics[width=0.4\textwidth]{intro/benzoCompounds_color}} \opt{grayscale}{\includegraphics[width=0.4\textwidth]{intro/benzoCompounds}} " - http://chem-bla-ics.blogspot.com/2008/01/my-phd-thesis-in-color-and-grayscale.html
# with gs:
# http://handyfloss.net/2008.09/making-a-pdf-grayscale-with-ghostscript/
# note - this strips metadata! so:
# http://etutorials.org/Linux+systems/pdf+hacks/Chapter+5.+Manipulating+PDF+Files/Hack+64+Get+and+Set+PDF+Metadata/
COLORFILENAME=$1
OVERWRITE=$2
FNAME=${COLORFILENAME%.pdf}
# NOTE: pdftk does not work with logical page numbers / pagination;
# gs kills it as well;
# so check for existence of 'pdfmarks' file in calling dir;
# if there, use it to correct gs logical pagination
# for example, see
# http://askubuntu.com/questions/32048/renumber-pages-of-a-pdf/65894#65894
PDFMARKS=
if [ -e pdfmarks ] ; then
PDFMARKS="pdfmarks"
echo "$PDFMARKS exists, using..."
# convert to gray pdf - this strips metadata!
gs -sOutputFile=$FNAME-gs-gray.pdf -sDEVICE=pdfwrite \
-sColorConversionStrategy=Gray -dProcessColorModel=/DeviceGray \
-dCompatibilityLevel=1.4 -dNOPAUSE -dBATCH "$COLORFILENAME" "$PDFMARKS"
else # not really needed ?!
gs -sOutputFile=$FNAME-gs-gray.pdf -sDEVICE=pdfwrite \
-sColorConversionStrategy=Gray -dProcessColorModel=/DeviceGray \
-dCompatibilityLevel=1.4 -dNOPAUSE -dBATCH "$COLORFILENAME"
fi
# dump metadata from original color pdf
## pdftk $COLORFILENAME dump_data output $FNAME.data.txt
# also: pdfinfo -meta $COLORFILENAME
# grep to avoid BookmarkTitle/Level/PageNumber:
pdftk $COLORFILENAME dump_data output | grep 'Info\|Pdf' > $FNAME.data.txt
# "pdftk can take a plain-text file of these same key/value pairs and update a PDF's Info dictionary to match. Currently, it does not update the PDF's XMP stream."
pdftk $FNAME-gs-gray.pdf update_info $FNAME.data.txt output $FNAME-gray.pdf
# (http://wiki.creativecommons.org/XMP_Implementations : Exempi ... allows reading/writing XMP metadata for various file formats, including PDF ... )
# clean up
rm $FNAME-gs-gray.pdf
rm $FNAME.data.txt
if [ "$OVERWRITE" == "y" ] ; then
echo "Overwriting $COLORFILENAME..."
mv $FNAME-gray.pdf $COLORFILENAME
fi
# BUT NOTE:
# Mixing TEX & PostScript : The GEX Model - http://www.tug.org/TUGboat/Articles/tb21-3/tb68kost.pdf
# VTEX is a (commercial) extended version of TEX, sold by MicroPress, Inc. Free versions of VTEX have recently been made available, that work under OS/2 and Linux. This paper describes GEX, a fast fully-integrated PostScript interpreter which functions as part of the VTEX code-generator. Unless specified otherwise, this article describes the functionality in the free- ware version of the VTEX compiler, as available on CTAN sites in systems/vtex.
# GEX is a graphics counterpart to TEX. .. Since GEX may exercise subtle influence on TEX (load fonts, or change TEX registers), GEX is op- tional in VTEX implementations: the default oper- ation of the program is with GEX off; it is enabled by a command-line switch.
# \includegraphics[width=1.3in, colorspace=grayscale 256]{macaw.jpg}
# http://mail.tug.org/texlive/Contents/live/texmf-dist/doc/generic/FAQ-en/html/FAQ-TeXsystems.html
# A free version of the commercial VTeX extended TeX system is available for use under Linux, which among other things specialises in direct production of PDF from (La)TeX input. Sadly, it���s no longer supported, and the ready-built images are made for use with a rather ancient Linux kernel.
# NOTE: another way to capture metadata; if converting via ghostscript:
# http://compgroups.net/comp.text.pdf/How-to-specify-metadata-using-Ghostscript
# first:
# grep -a 'Keywo' orig.pdf
# /Author(xxx)/Title(ttt)/Subject()/Creator(LaTeX)/Producer(pdfTeX-1.40.12)/Keywords(kkkk)
# then - copy this data in a file prologue.ini:
#/pdfmark where {pop} {userdict /pdfmark /cleartomark load put} ifelse
#[/Author(xxx)
#/Title(ttt)
#/Subject()
#/Creator(LaTeX with hyperref package + gs w/ prologue)
#/Producer(pdfTeX-1.40.12)
#/Keywords(kkkk)
#/DOCINFO pdfmark
#
# finally, call gs on the orig file,
# asking to process pdfmarks in prologue.ini:
# gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 \
# -dPDFSETTINGS=/screen -dNOPAUSE -dQUIET -dBATCH -dDOPDFMARKS \
# -sOutputFile=out.pdf in.pdf prologue.ini
# then the metadata will be in output too (which is stripped otherwise;
# note bookmarks are preserved, however). 