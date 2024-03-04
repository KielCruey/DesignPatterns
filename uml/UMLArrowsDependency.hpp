/*
    Dependence is the most basic relationship between classes.
    Class Foo depends on class Bar if it uses instances of Bar
    at some point in its code. If the public interface for Bar ever
    changes, the code in Foo may need to be updated.
    Keep in mind that this does not imply that Bar depends on
    Foo; Bar probably does not know what classes are using it.
*/
class Bar
{
public:
    Bar();
    ~Bar();

    int addNumbers(int a, int b);
};

class Foo
{
public:
    Foo();
    ~Foo();

    void DoWork(Bar * bar);
};
