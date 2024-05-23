class Time
{
private:
    unsigned short seconds;
    unsigned short minutes;
    unsigned hours;

    bool isNonNegative(int);
    void validateInput(int);
public:
    Time();
    Time(int, int=0, int=0);

    void display() const;

    unsigned getSeconds() const;
    unsigned getMinutes() const;
    unsigned getHours() const;

    void setSeconds(int);
    void setMinutes(int);
    void setHours(int);
    void setTime(int, int=0, int=0);
};
