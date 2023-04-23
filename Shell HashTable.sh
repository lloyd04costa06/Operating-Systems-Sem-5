
hashTab=(-1 -1 -1 -1 -1 -1 -1 -1 -1 -1)
value=0

function Insert(){
  echo 'ENTER NUMBER TO BE INSERTED'
  read NUM
  HashValue=$(($NUM%10))
  for (( i=0; i<10; i++ ))
      do
          index=$((($HashValue+$i)%10))
          B=${hashTab[$index]}
          if [ $B -eq -1 ]
          then
            hashTab[$index]=$NUM
            break
          fi

          if [ $i -eq 9 ]
          then
            echo "ELEMENT CANNOT BE INSERTED"
          fi
      done

}

function Search(){
  echo 'ENTER NUMBER TO BE SEARCHED'
  read NUM
  HashValue=$(($NUM%10))
  for (( i=0; i<10; i++ ))
      do
          index=$((($HashValue+$i)%10))
          B=${hashTab[$index]}
          if [ $B -eq $NUM ]
          then
            echo "NUMBER PRESENT IN HASH TABLE"
            break
          fi

          if [ $i -eq 9 ]
          then
            echo "ELEMENT NOT PRESENT"
          fi
      done

}

function Delete(){
  echo 'ENTER NUMBER TO BE DELETED'
  read NUM
  HashValue=$(($NUM%10))
  for (( i=0; i<10; i++ ))
      do
          index=$((($HashValue+$i)%10))
          B=${hashTab[$index]}
          if [ $B -eq $NUM ]
          then
            hashTab[$index]=-1
            echo "NUMBER DELETED"
            break
          fi

          if [ $i -eq 9 ]
          then
            echo "ELEMENT NOT PRESENT"
          fi
      done

}

function Display(){
  echo "HASH CONTENT: "
  for (( i=0; i<=10; i++ ))
    do
      a=${hashTab[$i]}
      echo "$a"
  done
}



ch=1
while [ $ch -eq 1 ]
do
	echo "1. INSERTED"
	echo "2. SEARCH"
	echo "3. DISPLAY"
  echo "4. DELETE"
	read choice
	case $choice in
	1) Insert
	;;
	2) Search
	;;
	3) Display
	;;
  4) Delete
	;;
	*) echo "INVALID CHOICE"
	;;
	esac
	echo "DO YOU WANT TO CONTINUE 1/0"
	read ch
done
