g++ gen.cpp -o gen
g++ a.cpp
for i in {0..2}
do
echo "SAMPLE "$i
./gen 6 20
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
for i in {8..12}
do
echo "BIG "$i
./gen 1000000 2000000 
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
