echo $1;
while read -r LINE; do
	echo $LINE | cat > temp.txt
    ./a.out  < temp.txt > output.out
done < $1 