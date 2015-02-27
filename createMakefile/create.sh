gcc -o createMakefile main.c;
./createMakefile $1 $2 libft $3 &&
mkdir $1/proj;
mkdir $1/includes;mkdir $1/proj/src;
mv ${1}/*.c $1/proj/src;mv ${1}/*.h $1/includes;
cp -r ~/Mygithub/libft $1/;
mv $1/libft/*.h $1/includes;
echo "dduval" > $1/auteur

