#pragma once

#include <chrono>
#include <thread>
#include <ratio>

template<int FPS>
class frame_rater {
public:
    frame_rater() :     // initialize the object keeping the pace
        time_between_frames{ FPS },     // std::ratio<1, FPS> seconds
        tp{ std::chrono::steady_clock::now() }
    {}

    void sleep() {
        // add to time point
        tp += time_between_frames;
        std::chrono::duration<double, std::nano> a = (std::chrono::steady_clock::now() - tp);
        // and sleep until that time point
        std::this_thread::sleep_until(tp);
    }

private:
    // a duration with a length of 1/FPS seconds
    std::chrono::duration<double, std::ratio<1, FPS>> time_between_frames;

    // the time point we'll add to in every loop
    std::chrono::time_point<std::chrono::steady_clock, decltype(time_between_frames)> tp;
};
