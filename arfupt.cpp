#include <iostream>
const double * f1(const double ar[], int n);
//在函数原型中const double ar[] 与const double * ar的含义完全相同
const double * f2(const double [], int );
const double * f3(const double * , int );

int main()
{
    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};

    const double* (*p1)(const double *, int) = f1;
    auto p2 = f2;
    cout << "Using pointers to functions: \n";
    cout << "Address Value\n";
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) <<endl;
    cout << p2(av, 3) << ": " << *p2(av,3) << endl;

    //pa an array of pointers
    //auto doesn't work with list initialization
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
    //but it does work for initializing to a single value
    //pb a pointer to first element of pa
    auto pb = pa;
    const double *(**pb1)(const double *, int) = pa;

    //使用 函数指针构成的数组
    cout << "\n 使用 函数指针数组 \n";
    cout << "Adress Values\n";
    for (int i = 0; i< 3; i++)
    {
        cout << pa[i](av, 3) << ": " <<*pa[i](av,3) <<endl;
    }

    //使用指向函数指针的指针
    cout << "\n 使用 指向函数指针的  指针:\n";
    cout << "Address Value\n";
    for (int i = 0; i< 3; i++)
    {
        cout << pb[i](av, 3) << ":"<< *pb[i](av, 3) <<endl;
    }

    //使用指向 函数指针数组 的指针
    cout << "\n 使用指向 函数指针数组 的指针:\n";
    cout << "Address value:\n";
    auto pc = &pa;
    const double * (*(*pc1)[3])(const double *, int) = &pa;
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;

    const double* (*(*pd)[3])(const double *, int) = &pa;

    const double *pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;

    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
    //cin.get();
    return 0;
}

//some rather dull functions

const double* f1(const double *ar, int n)
{
    return ar;
}

const double * f2(const double ar[], int n)
{
    return ar+1;
}

const double * f3(const double ar[], int n)
{
    return ar+2;
}
