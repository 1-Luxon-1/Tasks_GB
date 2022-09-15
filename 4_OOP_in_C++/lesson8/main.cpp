#include "Task_8_2.cpp"
#include "Task_8_3.cpp"

    ///////////// Task 1 //////////////
 template<typename T>
 T div(T num, T den)
 {
     try
     {
         if (den == 0) throw "Division By Zero";
         else
             return num / den;
     }
     catch (const char* err)
     {
         cout << err << endl;
     }
 }
    ///////////////////////////////////
///////////////////////////////////////////////////////////////

int main()
{
    ///////////// Task 1 //////////////
    double a = 18.9;
    double b = 8.3;
    cout << div(a, b) <<endl;
    b = 0.0;
    cout << div(a, b) << endl;
    ///////////////////////////////////

    ///////////// Task 2 //////////////
    Bar bar;
    try
    {
        double num;
        do
        {
            cin >> num;
            bar.set(num);
        } while (num != 0);
    }
    catch (Ex& ex)
    {
        cerr << "Error: a + y > 100 \na * y = " << ex.get() << endl;
    }
    ///////////////////////////////////

    ///////////// Task 3 //////////////
    Robot rob;
    char dir;
    do
    {
        cin >> dir;
        rob.moving(dir);
        rob.getField();
    } while (dir != '0');
    ///////////////////////////////////
    return 0;
}
