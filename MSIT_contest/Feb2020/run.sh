g++ MSTNT.cpp
for i in {0..3}
do
python3 test.py
./a.out
name="input"
name+=$i
name+=".txt"
touch $name
echo $name
cp input.txt $name
name="output"
name+=$i
name+=".txt"
touch $name
echo $name
cp output.txt $name
done