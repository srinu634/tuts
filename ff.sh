g++ ford_fulkerson.cpp
echo ""
echo "Test Case1: A Single line segment"
./a.out < 1.in > 1.out
echo""
cat 1.out

echo ""
echo "Test Case2: Adding a direct edge from S to T to TestCase1"
echo ""
./a.out < 2.in > 2.out
cat 2.out
echo ""

echo "Test Case3: Cormen Example"
echo ""
./a.out < 3.in  > 3.out
cat 3.out
echo ""

echo "Test Case4: Base Case"
echo ""
./a.out < 4.in > 4.out
cat 4.out
echo ""


echo "Test Case5: Disconected Graph"
echo ""
./a.out < 5.in > 5.out
cat 5.out
echo ""

echo "Test Case6: Tardos Example"
echo ""
./a.out < 6.in > 6.out
cat 6.out
echo ""
