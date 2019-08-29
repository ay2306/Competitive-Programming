for i in {0..15}
do
g++ c.cpp
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