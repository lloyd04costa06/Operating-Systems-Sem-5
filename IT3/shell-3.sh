ch=1
echo "ENTER FIRST NUMBER"
read num1
echo " ENTER SECOND NUMBER"
read num2
while [ $ch -eq 1 ]
do
	echo "1. ADDITION"
	echo "2. SUBSTRACTION"
	echo "3. MULTIPLICATION"
	echo "4. DIVISION"
	echo "5. MODULUS"
	read choice
	case $choice in
	1) result=$(($num1+$num2))
	   echo "SUM OF $num1+$num2=$result"
	;;
	2) result=$(($num1-$num2))
	   echo "DIFFERNCE OF $num1-$num2=$result"
	;;
	3) result=$(($num1*$num2))
	   echo "PRODUCT OF $num1*$num2=$result"
	;;
	4) result=$(($num1/$num2))
	   echo "QUOTIENT OF $num1/$num2=$result"
	;;
	5) result=$(($num1%$num2))
	   echo "REMAINDER OF $num1%$num2=$result"
	;;
	*) echo "INVALID CHOICE"
	;;
	esac
	echo "DO YOU WANT TO CONTINUE 1/0"
	read ch
done
