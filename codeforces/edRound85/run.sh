g++ d.cpp -o d
g++ check.cpp -o check
for i in {0..100}
do
python3 test.py
(./d<input.txt)>out1
(./check<input.txt)>out2
echo $i
diff out1 out2
done   