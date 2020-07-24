# g++ a.cpp -o binary
# g++ brute.cpp -o brute
# # for i in {1..100}
# # do
# # python3 test.py 5 30 5 30
# # echo "TESTING REGULAR $i"
# # (./binary<input.txt)>out
# # echo "TESTING BRUTE $i"
# # (./brute<input.txt)>out2
# # diff out out2
# # done
# cp sample_in.txt input0.txt
# cp sample_out.txt output0.txt
# mv input0.txt ./input/input0.txt
# mv output0.txt ./output/output0.txt
# for i in {1..5}
# do
# # echo "Test "$i
# python3 test.py 5 30 50 100
# # (./binary<input.txt)>out
# # cp input.txt input$i.txt
# # cp out output$i.txt
# # mv output$i.txt ./output/output$i.txt
# # mv input$i.txt ./input/input$i.txt
# echo "TESTING REGULAR $i"
# (./binary<input.txt)>out
# echo "TESTING BRUTE $i"
# (./brute<input.txt)>out2
# diff out out2
# done
# for i in {6..100}
# do
# # echo "Test "$i
# python3 test.py 500 30000 5000 10000
# # (./binary<input.txt)>out
# # cp input.txt input$i.txt
# # cp out output$i.txt
# # mv output$i.txt ./output/output$i.txt
# # mv input$i.txt ./input/input$i.txt
# echo "TESTING REGULAR $i"
# (./binary<input.txt)>out
# echo "TESTING BRUTE $i"
# (./brute<input.txt)>out2
# diff out out2
# done

# # for i in {11..15}
# # do
# # echo "Test "$i
# # python3 test.py 100000 200000 100000 200000
# # (./binary<input.txt)>out
# # cp input.txt input$i.txt
# # cp out output$i.txt
# # mv output$i.txt ./output/output$i.txt
# # mv input$i.txt ./input/input$i.txt
# # echo "TESTING REGULAR $i"
# # (./binary<input.txt)>out
# # echo "TESTING BRUTE $i"
# # (./brute<input.txt)>out2
# # diff out out2
# # done


g++ a.cpp -o binary
cp sample_in.txt input0.txt
cp sample_out.txt output0.txt
mv input0.txt ./input/input0.txt
mv output0.txt ./output/output0.txt
for i in {1..5}
do
echo "Test "$i
python3 test.py 5 30 50 100
(./binary<input.txt)>out
cp input.txt input$i.txt
cp out output$i.txt
mv output$i.txt ./output/output$i.txt
mv input$i.txt ./input/input$i.txt
done
for i in {6..10}
do
echo "Test "$i
python3 test.py 500 30000 5000 10000
(./binary<input.txt)>out
cp input.txt input$i.txt
cp out output$i.txt
mv output$i.txt ./output/output$i.txt
mv input$i.txt ./input/input$i.txt
done

for i in {11..15}
do
echo "Test "$i
python3 test.py 100000 200000 100000 200000
(./binary<input.txt)>out
cp input.txt input$i.txt
cp out output$i.txt
mv output$i.txt ./output/output$i.txt
mv input$i.txt ./input/input$i.txt
done