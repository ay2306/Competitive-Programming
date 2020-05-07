g++ tourist_reform.cpp -o ayush
g++ ritesh_tourist_reform.cpp -o ritesh

# for i in {0..100}
# do
# echo "Test #"$i
python3 test.py
(./ayush<input.txt)>out1
(./ritesh<input.txt)>out2
diff out1 out2
# done