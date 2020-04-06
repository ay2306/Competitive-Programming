g++ d.cpp -o d_binary
# g++ harsh.cpp -o d_binary
echo "Runnning B<=10 Testcases"
for i in {0..1}
do
python3 interactor.py python3 int_judge.py 0 -- ./d_binary
done
echo "Runnning B<=20 Testcases"
for i in {0..1}
do
python3 interactor.py python3 int_judge.py 1 -- ./d_binary
done
echo "Runnning B<=100 Testcases"
for i in {0..4}
do
python3 interactor.py python3 int_judge.py 2 -- ./d_binary
done