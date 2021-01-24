g++ -DLOCAL D_Small_Multiple.cpp
for i in {99990..99999}
do
echo $i>input.txt
val=$(./a.out) 
echo $i $val
done