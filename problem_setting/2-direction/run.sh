g++ gen.cpp -o gen
g++ a.cpp
for i in {0..2}
do
echo "SAMPLE "$i
./gen 2 4
cp input.txt ./input/input$i.txt
echo "TEST GENERATED"
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
echo "OUTPUT GENERATED"
done
for i in {3..7}
do
echo "SMALL "$i
./gen 1000 10000 
cp input.txt ./input/input$i.txt
echo "TEST GENERATED"
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
echo "OUTPUT GENERATED"
done
for i in {7..12}
do
echo "BIG "$i
./gen 10000 100000 
cp input.txt ./input/input$i.txt
echo "TEST GENERATED"
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
echo "OUTPUT GENERATED"
done
for i in {12..15}
do
echo "VERY BIG "$i
./gen 100000 100000 
cp input.txt ./input/input$i.txt
echo "TEST GENERATED"
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
echo "OUTPUT GENERATED"
done
