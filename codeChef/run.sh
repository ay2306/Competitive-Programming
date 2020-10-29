g++ Golomb_Sequence.cpp -o main
g++ brute.cpp -o brute
g++ gen.cpp -o gen
(./gen)
(./main<input.txt)>out1
(./brute<input.txt)>out2
diff out1 out2