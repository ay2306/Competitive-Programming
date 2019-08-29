for i in {0..9}
do
# g++ graphGen.cpp
# ./a.out
g++ lucky7.cpp
python3 test.py
./a.out
name="input"
name+=$i
name+=".txt"
echo $name
cp input.txt $name 
name="output"
name+=$i
name+=".txt"
echo $name
cp output.txt $name 
done