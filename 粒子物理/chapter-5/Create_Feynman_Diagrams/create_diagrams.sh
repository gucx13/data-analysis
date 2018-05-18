#latex BsJpsiPhi_penguin_example.tex
latex e_mu_Fey.tex
rm *.aux
rm *.log
#dvips BsJpsiPhi_penguin_example.dvi
dvips e_mu_Fey.dvi
#ps2pdf BsJpsiPhi_penguin_example.ps
pstopdf e_mu_Fey.ps
# Remove if want to keep dvi format:
rm *.dvi
open e_mu_Fey.pdf
