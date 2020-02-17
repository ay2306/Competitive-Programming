for i in {0..4}
do
python3 test.py
python3 runner.py
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