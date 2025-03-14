#pragma once

class Time {
private:
    unsigned short _hours;
    unsigned short _minutes;
    unsigned short _seconds;

public:
    Time() {
        _hours = 0;
        _minutes = 0;
        _seconds = 0;
    }

    Time(unsigned short hours, unsigned short minutes, unsigned short seconds) {
        _hours = hours;
        _minutes = minutes;
        _seconds = seconds;

        assert(_hours >= 0 && _hours < 24);    
        assert(_minutes >= 0 && _minutes < 60); 
        assert(_seconds >= 0 && _seconds < 60); 

    }

    unsigned long totalSeconds() const {
        return (_hours * 3600) + (_minutes * 60) + _seconds;
    }

    bool operator!() const {
        return (_hours == 0 && _minutes == 0 && _seconds == 0);
    }

    Time& operator++() {
        _seconds = (_seconds + 1) % 60;
        _minutes = (_minutes + (_seconds == 0)) % 60;
        _hours = (_hours + (_minutes == 0 && _seconds == 0)) % 24;
        return *this;
    }

    Time operator++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    Time& operator--() {
        _seconds = (_seconds == 0) ? 59 : _seconds - 1;
        _minutes = (_seconds == 59) ? (_minutes == 0 ? 59 : _minutes - 1) : _minutes;
        _hours = (_seconds == 59 && _minutes == 59) ? (_hours == 0 ? 23 : _hours - 1) : _hours;
        return *this;
    }

    Time operator--(int) {
        Time temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const Time& other) const {
        return totalSeconds() == other.totalSeconds();
    }

    bool operator!=(const Time& other) const {
        return totalSeconds() != other.totalSeconds();
    }

    bool operator<(const Time& other) const {
        return totalSeconds() < other.totalSeconds();
    }

    bool operator>(const Time& other) const {
        return totalSeconds() > other.totalSeconds();
    }

    bool operator<=(const Time& other) const {
        return totalSeconds() <= other.totalSeconds();
    }

    bool operator>=(const Time& other) const {
        return totalSeconds() >= other.totalSeconds();
    }

    void operator()() const {
        cout << _hours << ":" << (_minutes < 10 ? "0" : "") << _minutes << ":" << (_seconds < 10 ? "0" : "") << _seconds << endl;
    }
};




