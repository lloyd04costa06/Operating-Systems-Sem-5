for (( i=2000; i<=2500; i++ ))
    do
        if [ $(($i % 4)) -eq 0 ]
         then 
		    echo "$i "
        fi
    done