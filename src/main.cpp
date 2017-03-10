#include <ring_buff.h>


int main(int argc, char *argv[])
{
    ring_buff<int, 10>crc_buf;

    for(int i = 0; i < 5; i++)
    {
        crc_buf.push(i);
    }
    crc_buf.show_buffer();

    //tests heve done!!!


    return 0;
}
