#ifndef MY_STREAM_H
#define MY_STREAM_H

#include "oop3d.h"

struct input_stream {
    std::ifstream inp;
};

struct output_stream {
    std::ofstream out;
};

int open_stream(input_stream &stream, const char* filename);
int open_stream(output_stream &stream, const char* filename);

int close_stream(input_stream &stream);
int close_stream(output_stream &stream);

int write_stream(output_stream &stream, const char* str);

int read_stream(double &x, input_stream &stream);
int read_stream(int &x, input_stream &stream);

#endif // MY_STREAM_H
