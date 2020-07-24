g++ SUBLEX.cpp -o sa
g++ SUBLEX_SAM.cpp -o sam
for i in {0..10}
do
echo "TEST " $i
python3 test.py
(./sa < input.txt)>out1
(./sam < input.txt)>out2
# cat out1
# cat out2
diff out1 out2
done