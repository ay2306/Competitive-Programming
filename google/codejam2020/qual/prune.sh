g++ tt.cpp -o tt
g++ a.cpp -o a
for i in {0..1500}
do
echo $i
python3 testing.py
./tt
./a
diff out out1
done

