g++ gen.cpp -o gen
g++ a.cpp
for i in {0..2}
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
./gen 10 100 
cp input.txt ./input/input$i.txt
(./a.out < input.txt)>output.txt
cp output.txt ./output/output$i.txt
done
