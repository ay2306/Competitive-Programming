g++ a.cpp -o binary
cp sample_in.txt input0.txt
cp sample_out.txt output0.txt
mv input0.txt ./input/input0.txt
mv output0.txt ./output/output0.txt
for i in {1..5}
do
echo "Test "$i
python3 test.py 5 15
echo "Test "$i
(./binary<input.txt)>out
cp input.txt input$i.txt
cp out output$i.txt
mv output$i.txt ./output/output$i.txt
mv input$i.txt ./input/input$i.txt
done
for i in {6..10}
do
echo "Test "$i
python3 test.py 20 100
echo "Test "$i
(./binary<input.txt)>out
cp input.txt input$i.txt
cp out output$i.txt
mv output$i.txt ./output/output$i.txt
mv input$i.txt ./input/input$i.txt
done
for i in {11..15}
do
echo "Test "$i
python3 test.py 500 10000
echo "Test "$i
(./binary<input.txt)>out
cp input.txt input$i.txt
cp out output$i.txt
mv output$i.txt ./output/output$i.txt
mv input$i.txt ./input/input$i.txt
done