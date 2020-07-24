g++ placing_rooks.cpp -o ayush
g++ harsh.cpp -o harsh
# for i in {0..100}
# do
# echo "Test Number " $i
python3 test.py
(./ayush<input.txt)>out1
(./harsh<input.txt)>out2
diff out1 out2
# done 