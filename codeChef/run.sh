python3 test.py
g++ ENCODING.cpp
./a.out
g++ ENCODING_brute.cpp -o brute
./brute
diff output.txt output1.txt