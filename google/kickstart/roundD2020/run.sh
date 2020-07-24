g++ test.cpp -o gen
g++ b.cpp -o manvi
g++ b1.cpp -o me

./gen
((./manvi<inp.txt)>out1)
((./me<inp.txt)>out2)

diff out1 out2