g++ gen.cpp -o gen
g++ a.cpp
for i in {0..2}
do
echo "SAMPLE "$i
./gen 1 10 
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
for i in {3..7}
do
echo "SMALL "$i
./gen 50 500 50 5000 
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
for i in {7..12}
do
echo "BIG "$i
./gen 501 100000 10000 1000000 
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done