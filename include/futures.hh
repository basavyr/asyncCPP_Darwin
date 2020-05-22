#ifndef FUTURES_HH
#define FUTURES_HH

namespace Futures
{
class Future
{
public:
    static void threadID();
    static void sleep(int);
    static void slowLoop(int[], int);
    static void fastLoop(int[], int);
    static void fastStream(char, int);
    static void slowStream(char, int);

public:
    void show();
};
void threadID();
void newLine();
} // namespace Futures

#endif // FUTURES_HH
