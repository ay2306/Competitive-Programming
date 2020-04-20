g++ temp.cpp -o temp
g++ tavas_and_malekas.cpp -o tam 
for i in {0..1}
do
echo $i
python3 test.py
# echo "Input:"
# cat input.txt
# echo " "
# echo "Expected:"
(./temp<input.txt) > out1
# cat out1
# echo " "
# echo "My output:"
(./tam<input.txt) > out2
# cat out2
# echo " "
diff out1 out2
done