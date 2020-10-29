g++ gen.cpp -o gen
g++ a.cpp
cp input0.txt ./input/input0.txt
cp output0.txt ./output/output0.txt
for i in {1..2}
do
echo "SAMPLE "$i
./gen 3 6
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
for i in {3..7}
do
echo "SMALL "$i
./gen 1000 10000 
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
for i in {7..12}
do
echo "BIG "$i
./gen 10000 100000 
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
