g++ PPDIV.cpp -o ppdiv
for i in {0..100}
# for i in {0..0}
do
echo $i
python3 test.py
(./ppdiv<input.txt)>out1
((python3 PPDIV.py)<input.txt)>out
diff out out1
done
