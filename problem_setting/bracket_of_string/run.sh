g++ gen.cpp -o gen
g++ a.cpp
for i in {0..2}
do
echo "SAMPLE "$i
./gen 4 6
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
for i in {3..7}
do
echo "SMALL "$i
./gen 2012313 501232131 
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
for i in {7..12}
do
echo "BIG "$i
./gen 1000000000000 100000000000000000 
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
