cat /etc/passwd | grep -v "#" | awk "NR % 2 == 0" | cut -d ":" -f1 | rev | sort -r | awk "$FT_LINE1 <= NR && NR <= $FT_LINE2" | tr "\n" "," | sed "s/,/, /g" | sed "s/, *$/\./" | tr -d "\n"
