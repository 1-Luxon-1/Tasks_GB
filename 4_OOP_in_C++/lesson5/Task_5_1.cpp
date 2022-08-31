template<class T>
class Pair1
{
public:
    Pair1(T n1, T n2) :num1(n1), num2(n2) {}

    T first()
    {
        return num1;
    }

    T second()
    {
        return num2;
    }
private:
    T num1;
    T num2;
};