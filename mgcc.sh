stdout=`gcc -Wall a.c`
if [[ -n "$stdout" ]]; then
	echo "hhhh";
else
	echo "nooo";
fi
echo $stdout
