g++ a.cpp -o binary
(./binary<si1.txt)>output.txt
cp si1.txt ./input/input0.txt
cp so1.txt ./output/output0.txt
(./binary<si2.txt)>output.txt
cp si2.txt ./input/input1.txt
cp so2.txt ./output/output1.txt

for i in {2..8}
do
echo "CREATING TEST " $i
python3 test.py 100 1000 0 1000
cp input.txt ./input/input$i.txt
echo "CREATING OUTPUT " $i
(./binary<input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
for i in {9..14}
do
echo "CREATING TEST " $i
python3 test.py 1000 10000 0 100000
cp input.txt ./input/input$i.txt
echo "CREATING OUTPUT " $i
(./binary<input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
for i in {15..20}
do
echo "CREATING TEST " $i
python3 test.py 100000 100000 0 1000000000
echo "CREATING OUTPUT " $i
cp input.txt ./input/input$i.txt
(./binary<input.txt)>output.txt
cp output.txt ./output/output$i.txt
done

for i in {21..35}
do
echo "CREATING TEST " $i
python3 test.py 50000 100000 0 1000000 linear
echo "CREATING OUTPUT " $i
cp input.txt ./input/input$i.txt
# (./binary<input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
for i in {36..36}
do
echo "CREATING TEST " $i
python3 test.py 10 10 0 10 linear
echo "CREATING OUTPUT " $i
cp input.txt ./input/input$i.txt
# (./binary<input.txt)>output.txt
cp output.txt ./output/output$i.txt
done