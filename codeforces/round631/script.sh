g++ -DLOCAL_TESTING a.cpp
g++ -DLOCALTESTING brute.cpp -o brute
for i in {0..50}
./a.out
./brute
diff out1 out2