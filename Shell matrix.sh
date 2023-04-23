Mat=(0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0)
echo "Enter Rows: "
read Rows
echo "Columns"
read Cols

for (( i=0;i<$Rows;i++ ))
do
  for (( j=0;j<$Cols;j++ ))
  do
    read temp;
    index=$((i*$Cols+j))
    Mat[index]=$temp
  done
done

echo "done"

for (( i=0;i<$Rows;i++ ))
do
  for (( j=0;j<$Cols;j++ ))
  do
    index=$((i*$Cols+j))
    echo -n "${Mat[$index]} "
  done
  echo
done

echo "transpose"
for (( i=0;i<$Rows;i++ ))
do
  for (( j=i+1;j<$Cols;j++ ))
  do
    index1=$((i*$Rows+j))
    index2=$((j*$Rows+i))
    temp=${Mat[$index1]}
    Mat[$index1]=${Mat[$index2]}
    Mat[$index2]=$temp
  done

done

for (( i=0;i<$Rows;i++ ))
do
  for (( j=0;j<$Cols;j++ ))
  do
    index=$((i*$Cols+j))
    echo -n "${Mat[$index]} "
  done
  echo
done
