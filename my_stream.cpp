#include "oop3d.h"

int open_stream(input_stream &stream, const char* filename)
{
    if(stream.inp) {
        stream.inp.close();
    }
    stream.inp.open(filename);
    if(!stream.inp) {
        return FILE_NOT_FIND;
    }
    return 0;
}

int open_stream(output_stream &stream, const char* filename)
{
    if(stream.out) {
        stream.out.close();
    }
    stream.out.open(filename);
    if(!stream.out) {
        return FILE_NOT_FIND;
    }
    return 0;
}

int close_stream(input_stream &stream)
{
    if(stream.inp) {
        stream.inp.close();
    }
    return 0;
}

int close_stream(output_stream &stream)
{
    if(stream.out) {
        stream.out.close();
    }
    return 0;
}


int write_stream(output_stream &stream, const char* str)
{
    if(!stream.out)
        return FILE_NOT_FIND;
    stream.out << str;
    return 0;
}

int read_stream(double &x, input_stream &stream)
{
    if(!stream.inp)
        return FILE_NOT_FIND;
    double y = 0;
    if(!(stream.inp >> y))
        return FILE_ERROR;
    x = y;
    return 0;
}
int read_stream(int &x, input_stream &stream)
{
    if(!stream.inp)
        return FILE_NOT_FIND;
    int y = 0;
    if(!(stream.inp >> y))
        return FILE_ERROR;
    x = y;
    return 0;
}

