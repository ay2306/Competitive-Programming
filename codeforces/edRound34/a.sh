g++ rohit.cpp -o brute
g++ c.cpp 

for i in {0..1}
do
echo $i
python3 tc.py
(./brute<inp)>out2
(./a.out<inp)>out1
diff out1 out2
done