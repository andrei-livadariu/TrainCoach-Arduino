#ifndef TRAINLIB_IBINARYSIGNAL_H
#define TRAINLIB_IBINARYSIGNAL_H

class IBinarySignal
{
    public:
        virtual bool getLock() = 0;
        virtual void setLock(bool lock) = 0;
        
        virtual void flipLock() { setLock(!getLock()); };

        virtual void lock() { setLock(true); };
        virtual void unlock() { setLock(false); };

        virtual bool isLocked() { return getLock(); };
        virtual bool isUnlocked() { return !getLock(); };
};

#endif