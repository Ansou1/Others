#!/bin/sh

trace="trace"
tmp="/tmp/____tmp_passage_test____"

\rm -f "${trace}"
\rm -f "${tmp}"
for file in "test0-1.bdsh" "test0-1_old.bdsh" "test0-2.bdsh" "test0-2_old.bdsh" "test0-3.bdsh" "test0-4.bdsh" "test1.bdsh" "test2.bdsh" "test3.bdsh" "test4.bdsh" "test5_1.bdsh" "test5_2.bdsh" "test5_3.bdsh" "test5_4.bdsh" "test5.bdsh" "test_relou_2.bdsh" "test_relou.bdsh"
do
    echo "PASSAGE DU TEST ${file}."
    if [ -f "${file}" ]
    then
	./moul.pl "${file}" > "${tmp}"
	nb_total=`fgrep "TEST" "${tmp}" | wc -l`
	nb_ok=`fgrep "TEST OK" "${tmp}" | wc -l`
	cat "${tmp}" >> "${trace}"
	printf "SCORE ${file} : ${nb_ok} / ${nb_total}\n\n"
	printf "SCORE ${file} : ${nb_ok} / ${nb_total}\n\n" >> "${trace}"
    else
	echo "PAS DE FICHIER ${file} PRESENT >&2."
    fi
done

\rm -f "${tmp}"

nb_total=`fgrep "TEST" "${trace}" | wc -l`
nb_ok=`fgrep "TEST OK" "${trace}" | wc -l`

printf "SCORE TOTAL : %s\n" "${nb_ok} sur ${nb_total}."
printf "SCORE TOTAL : %s\n" "${nb_ok} sur ${nb_total}." >> "${trace}"

