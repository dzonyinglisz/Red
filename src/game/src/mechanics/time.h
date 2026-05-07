class TimeKeeper
{
private:
public:
    TimeKeeper(int initTime);
    ~TimeKeeper();
    void progressTime(float dt);
    double speed = 90;
    float time;
};
