g++ c.cpp -o c
g++ check.cpp -o check

python3 test.py

(./c<input.txt)>out1
(./check<input.txt)>out2

diff out1 out2
