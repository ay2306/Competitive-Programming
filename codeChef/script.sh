g++ -DABC random_tester.cpp -o random_tester
g++ -DNOT_CODECHEF SQRDSUB.cpp -o SQRDSUB
for i in {0..50}
do
echo $i
python3 test.py
./random_tester
./SQRDSUB
diff output.txt output1.txt
done