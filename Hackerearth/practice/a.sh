g++ check.cpp -o check
g++ specialPalindrome.cpp
# for i in {0..100}
# do
echo "test"$i
python3 test.py
(./a.out<input.txt)>out1
(./check<input.txt)>out2
diff out1 out2
# done