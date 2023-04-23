echo "ENTER A NUMBER"
read num
sum=0
while [ $num -gt 0 ]
    do
        a=$(($num%10))
        cube=$(($a*$a*$a))
        echo "cube of $a = $cube"
        sum=$(($sum+cube))
        num=$(($num/10))
    done
echo "SUM OF CUBES OF ALL DIGITS IS  $sum"
