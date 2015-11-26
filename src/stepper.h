class Stepper {
public:
    enum Direction {
        NONE, LEFT, RIGHT
    };

    void init();

    Stepper(int a, int b, int c, int d);

    void rotate(Direction direction);


private:
    int a, b, c, d;
    int counter;
    int t = 2;

    void makeMove(int counter);
};