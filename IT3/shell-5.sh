num=1
inc=3
cnt=0
echo "ENTER SERIES RANGE"
read no
while [ $cnt -lt $no ]
    do
        printf "%s","$num"
        num=$(($num+inc))
        inc=$(($inc+2))
        cnt=$((cnt+1))
    done
