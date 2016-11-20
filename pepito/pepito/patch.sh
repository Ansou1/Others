rm -vfr back_up
mkdir back_up
diff main.c patch/main.c > diff_main.patch
diff utils.c patch/utils.c > diff_utils.patch
patch -nb main.c diff_main.patch
patch -nb utils.c diff_utils.patch
mv *.orig back_up